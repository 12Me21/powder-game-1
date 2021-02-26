#include "ball.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"
#include "entity.h"
#include "elements.h"

Ball balls[Ball_MAX+1];
Ball* const Ball_END = &balls[Ball_MAX];

void Ball_create(double x, double y, int type) {
	Ball* ball;
	forRange (ball, =balls, <Ball_END, ++) {
		if (!ball->used) {
			*ball = (Ball){
				{x+0.5, y+0.5},
				{0,0},
				true,
				0,
				0,
				type,
			};
			break;
		}
	}
}

static const struct neighbor {
	int offset;
	Vector breakVel;
	int breakX;
	int breakY;
} neighbors[] = {
   {-WIDTH-1,  (Vector){-0.7 ,-0.7 },-1,-1,},
   {-WIDTH,    (Vector){0    ,-1   },0, -1,},
   {-WIDTH+1,  (Vector){0.7  ,-0.7 },1, -1,},
   {-1,        (Vector){-1   ,0    },-1,0,	},
   {0,         (Vector){0    ,0    },0, 0,	},
   {1,         (Vector){1    ,0    },1, 0,	},
   {WIDTH-1,   (Vector){-0.7 ,0.7  },-1,1,	},
   {WIDTH,     (Vector){0    ,1    },0, 1,	},
   {WIDTH+1,   (Vector){0.7  ,0.7  },1, 1,	},
   {2*-WIDTH-1,(Vector){-0.44,-0.89},-1,-2,},
   {2*-WIDTH,  (Vector){0    ,-1   },0, -2,},
   {2*-WIDTH+1,(Vector){0.44 ,-0.89},1, -2,},
   {2*WIDTH-1, (Vector){-0.44,0.89 },-1,2,	},
   {2*WIDTH,   (Vector){0    ,1    },0, 2,	},
   {2*WIDTH+1, (Vector){0.44 ,0.89 },1, 2,	},
   {-2-WIDTH,  (Vector){-0.89,-0.44},-2,-1,},
   {-2,        (Vector){-1   ,0    },-2,0,	},
   {-2+WIDTH,  (Vector){-0.89,0.44 },-2,1,	},
   {2-WIDTH,   (Vector){0.89 ,-0.44},2, -1,},
   {2,         (Vector){1    ,0    },2, 0,	},
   {2+WIDTH,   (Vector){0.89 ,0.44 },2, 1,	},
   {3*-WIDTH-1,(Vector){-0.31,-0.94},-1,-3,},
   {3*-WIDTH,  (Vector){0    ,-1   },0, -3,},
   {3*-WIDTH+1,(Vector){0.31 ,-0.94},1, -3,},
   {3*WIDTH-1, (Vector){-0.31,0.94 },-1,3,	},
   {3*WIDTH,   (Vector){0    ,1    },0, 3,	},
   {3*WIDTH+1, (Vector){0.31 ,0.94 },1, 3,	},
   {-3-WIDTH,  (Vector){-0.94,-0.31},-3,-1,},
   {-3,        (Vector){-1   ,0    },-3,0,	},
   {-3+WIDTH,  (Vector){-0.94,0.31 },-3,1,	},
   {3-WIDTH,   (Vector){0.94 ,-0.31},3, -1,},
   {3,         (Vector){1    ,0    },3, 0,	},
   {3+WIDTH,   (Vector){0.94 ,0.31 },3, 1,	},
   {-2-2*WIDTH,(Vector){-0.7 ,-0.7 },-2,-2,},
   {2-2*WIDTH, (Vector){0.7  ,-0.7 },2, -2,},
   {-2+2*WIDTH,(Vector){-0.7 ,0.7  },-2,2,	},
   {2+2*WIDTH, (Vector){0.7  ,0.7  },2, 2,	},
};

static void Ball_break(Ball* ball, int mode, int createType, int meta, double vx, double vy, double speed) {
	Part** pc = Part_pos2(&ball->pos);
	int i;
	if (mode==0) {
		for (i=9;i<21;i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					floor(ball->pos.x)+neighbors[i].breakX,
					floor(ball->pos.y)+neighbors[i].breakY,
					createType
				);
				if (near) {
					near->vel.x += vx+neighbors[i].breakVel.x*speed;
					near->vel.y += vy+neighbors[i].breakVel.y*speed;
					near->meta = meta;
				}
			}
		}
		ball->used = false;
	} else if (mode==1||mode==2) {
		for (i=mode==1?9:0; i<21; i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					floor(ball->pos.x)+neighbors[i].breakX,
					floor(ball->pos.y)+neighbors[i].breakY,
					createType
				);
				if (near) {
					near->vel.x += vx+neighbors[i].breakVel.x*speed;
					near->vel.y += vx+neighbors[i].breakVel.y*speed;
					near->meta = meta;
				}
			} else if (near>=Part_0) {
				near->type = createType;
				near->meta = 0;
				near->pumpType = 0;
			}
		}
		ball->used = false;
	}
}

static bool Ball_react(Ball* ball, Part* part, int* newType) {
	//return 0;
	switch (ball->type) {
#define UPDATE_BALL_PART 1
#include "elements/All.c"
#undef UPDATE_BALL_PART
	}
	int pstate = ELEMENTS[part->type].state;
	int bstate = ELEMENTS[ball->type].state;
	return (pstate==State_LIQUID && bstate==State_LIQUID && ball->type!=part->type) ||
		(pstate==State_LIQUID && bstate!=State_LIQUID) ||
		(pstate==State_GAS && bstate!=State_GAS) ||
		part->type==Elem_FIRE;
}

void Ball_update(void) {
	//	var d,b,c=new Vector;
	Ball* i;
	forRange (i, =balls, <Ball_END, ++) {
		if (!i->used) continue;
		// remove invalid balls
		if (!ELEMENTS[i->type].ballValid) {
			i->used = false;
			continue;
		}
		Part** p = Part_pos2(&i->pos);
		int d;
		for (d=0;d<21;d++)
			if (p[neighbors[d].offset] == Part_BALL)
				p[neighbors[d].offset] = Part_EMPTY;
		double weight = ELEMENTS[i->type].ballWeight;
		i->vel.y += weight;

		double adv = ELEMENTS[i->type].ballAdvection;
		if (adv) {
			Block* cell = &Part_blocks[(int)i->pos.y>>2][(int)i->pos.x>>2];
			i->vel.x += cell->vel.x*d;
			i->vel.y += cell->vel.y*d;
			if (Vec_fastDist(&cell->vel)>0.3)
				Vec_mul(&i->vel, 0.9+(1-d)/10);
		}
		// dragging
		if (!i->held) {
			if ((Menu_leftSelection==Menu_DRAG&&Mouse_rising.left)||(Menu_rightSelection==Menu_DRAG&&Mouse_rising.right)) {
				if (Vec_fastDist(&(Vector){Pen_x-i->pos.x, Pen_y-i->pos.y})<20)
					i->held = true;
			}
		} else {
			if ((Menu_leftSelection==Menu_DRAG&&Mouse_old.left)||(Menu_rightSelection==Menu_DRAG&&Mouse_old.right)) {
				i->vel.x += 0.05*(Pen_x-i->pos.x);
				i->vel.y += 0.05*(Pen_y-i->pos.y);
				Vec_mul(&i->vel, 0.9);
			} else {
				Vec_mul(&i->vel, 0.3);
				i->held = false;
			}
		}
		// kicked by player/fighter
		Entity* en;
		forRange (en, =entitys, <Entity_next, ++) {
			if (en->type==Entity_FIGHTER||en->type==Entity_FIGHTER+1||en->type==Entity_PLAYER) {
				int f;
				for (f=4; f<=5; f++) {
					double dx = abs(en->parts[f].pos.x - i->pos.x);
					double dy = abs(en->parts[f].pos.y - i->pos.y);
					if (dx<=9 && dy<=9) {
						i->vel.x += 0.1*(en->parts[f].pos.x - en->parts[f].oldPos.x);
						i->vel.y += 0.2*(en->parts[f].pos.y - en->parts[f].oldPos.y);
					}
				}
			}
		}
		int touched = 0;
		int newType = 0;
		Vector vel = i->vel;
		// chcek movement
		int q = (int)(Vec_dist(&i->vel)/2)+1;
		double n = 1.0/q;
		int v,g;
		for (v=g=0; v<q; v++) {
			double nextx = i->pos.x+i->vel.x*n;
			double nexty = i->pos.y+i->vel.y*n;
			// way offscreen
			if (nextx<4 || nextx>=WIDTH-4 || nexty<4 || nexty>=H+12) {
				i->used = false;
				break;
			}
			// edge loop
			if (Menu_edgeMode==1) {
				if (nextx<8) {
					if (Part_pos(nextx+W,nexty)[0]<=Part_BGFAN) {
						i->pos.x += W;
						i->vel.x *= 0.8;
					} else
						i->vel.x *= -0.8;
					nextx = i->pos.x+i->vel.x*n;
				} else if (nextx>=W+8) {
					if (Part_pos(nextx-W,nexty)[0]<=Part_BGFAN) {
						i->pos.x -= W;
						i->vel.x *= 0.8;
					} else
						i->vel.x *= -0.8;
					nextx = i->pos.x+i->vel.x*n;
				}
				if (nexty<8) {
					if (Part_pos(nextx,nexty+H)[0]<=Part_BGFAN) {
						i->pos.y += H;
						i->vel.y *= 0.8;
					} else
						i->vel.y *= -0.8;
					nexty = i->pos.y+i->vel.y*n;
				} else if (nexty>=H+8) {
					if (Part_pos(nextx,nexty-H)[0]<=Part_BGFAN) {
						i->pos.y -= H;
						i->vel.y *= 0.8;
					} else
						i->vel.y *= -0.8;
					nexty = i->pos.y+i->vel.y*n;
				}
			}
			Vector z = {0,0};
			Part** pc = Part_pos(nextx,nexty);
			int d;
			int y=0;
			for (d=0;d<37;d++) {
				Part* near = pc[neighbors[d].offset];
				if (near<=Part_BGFAN) continue;
				if (near>=Part_0) {
					touched = near->type;
					if (Ball_react(i, near, &newType))
						continue;
				} else {
					touched = near-Part_0;
				}
				Vec_sub(&z, &neighbors[d].breakVel);
				y++;
			}
			if (y==0) {
				i->pos.x = nextx;
				i->pos.y = nexty;
			} else {
				Vec_normalize(&z);
				i->vel.y -= weight;
				double d = 0.999*Vec_dist(&i->vel);
				Vec_mul(&z, -(z.x*i->vel.x + z.y*i->vel.y));
				Vec_add(&i->vel, &z);
				Vec_mul(&i->vel, 0.999);
				Vec_mul(&z, 0.1);
				Vec_add(&i->vel, &z);
				Vec_normalize(&i->vel);
				Vec_mul(&i->vel, d);
				i->pos.x += i->vel.x*n;
				i->pos.y += i->vel.y*n;
				i->vel.y += weight;
			}
			pc = Part_pos2(&i->pos);
			z = (Vector){0,0};
			y=0;
			for (d=0;d<21;d++) {
				Part* near = pc[neighbors[d].offset];
				if (near<Part_BGFAN) continue;
				if (near>=Part_0) {
					int btype = i->type;
					int ptype = near->type;
					if (
						(ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state==State_LIQUID && btype!=ptype) ||
						(ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state!=State_LIQUID) ||
						(ELEMENTS[ptype].state==State_GAS && ELEMENTS[btype].state!=State_GAS) ||
						(ptype==Elem_LASER && ELEMENTS[btype].state==State_LIQUID) ||
						(ptype==Elem_FIRE) ||
						(ptype==Elem_FIRE && btype==Elem_THUNDER)
					)
						continue;
				}
				Vec_sub(&z, &neighbors[d].breakVel);
				y++;
			}
			if (y) {
				Vec_normalize(&z);
				Vec_add(&i->pos, &z);
			}
		}
		if (i->pos.x<4 || i->pos.x>=WIDTH-4 || i->pos.y<4 || i->pos.y>=H+12) {
			i->used = false;
			break;
		}
		Ball* ball = i;
		switch (i->type) {
#define UPDATE_BALL 1
#include "elements/All.c"
#undef UPDATE_BALL
		}
		if (newType != 0) {
			i->type = newType;
			i->meta = 0;
			newType = 0;
		}
		if (i->used) {
			Part** pc = Part_pos2(&i->pos);
			int d;
			for (d=0;d<21;d++) {
				Part** p = &pc[neighbors[d].offset];
				if (*p<=Part_BGFAN)
					*p = Part_BALL;
			}
		}
	}
}
