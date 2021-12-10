#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#include "menu.h"
#include "input.h"
#include "object.h"
#include "elements.h"
#include "block.h"
#include "save.h"
#include "vector.h"
#include "random.h"

Ball balls[Ball_MAX];
Ball* const Ball_END = &balls[Ball_MAX];

void Ball_create(int x, int y, Elem type) {
	Ball_FOR (ball) {
		if (!ball->used) {
			*ball = (Ball){
				.pos={x+0.5, y+0.5},
				.vel={0,0},
				.used=true,
				.charge=0,
				.held=false,
				.type=type,
			};
			break;
		}
	}
}

#define XYOFS(x,y) x,y,Dot_ofs(x,y)

const BallNeighbor Ball_NEIGHBORS[] = {
	{(Point){-0.7 ,-0.7 },XYOFS(-1,-1),},
	{(Point){ 0   ,-1   },XYOFS( 0,-1),},
	{(Point){ 0.7 ,-0.7 },XYOFS( 1,-1),},
	{(Point){-1   , 0   },XYOFS(-1, 0),}, // [][][]
	{(Point){ 0   , 0   },XYOFS( 0, 0),}, // [][][]
	{(Point){ 1   , 0   },XYOFS( 1, 0),}, // [][][]
	{(Point){-0.7 , 0.7 },XYOFS(-1, 1),},
	{(Point){ 0   , 1   },XYOFS( 0, 1),},
	{(Point){ 0.7 , 0.7 },XYOFS( 1, 1),},

	{(Point){-0.44,-0.89},XYOFS(-1,-2),}, //   [][][]
	{(Point){ 0   ,-1   },XYOFS( 0,-2),}, // []      []
	{(Point){ 0.44,-0.89},XYOFS( 1,-2),}, // []      []
	{(Point){-0.44, 0.89},XYOFS(-1, 2),}, // []      []
	{(Point){ 0   , 1   },XYOFS( 0, 2),}, //   [][][]
	{(Point){ 0.44, 0.89},XYOFS( 1, 2),},
	{(Point){-0.89,-0.44},XYOFS(-2,-1),},
	{(Point){-1   , 0   },XYOFS(-2, 0),},
	{(Point){-0.89, 0.44},XYOFS(-2, 1),},
	{(Point){ 0.89,-0.44},XYOFS( 2,-1),},
	{(Point){ 1   , 0   },XYOFS( 2, 0),},
	{(Point){ 0.89, 0.44},XYOFS( 2, 1),},
   
	{(Point){-0.31,-0.94},XYOFS(-1,-3),}, //     [][][]  
	{(Point){ 0   ,-1   },XYOFS( 0,-3),}, //   []      []
	{(Point){ 0.31,-0.94},XYOFS( 1,-3),}, // []          []
	{(Point){-0.31, 0.94},XYOFS(-1, 3),}, // []          []
	{(Point){ 0   , 1   },XYOFS( 0, 3),}, // []          []
	{(Point){ 0.31, 0.94},XYOFS( 1, 3),}, //   []      []
	{(Point){-0.94,-0.31},XYOFS(-3,-1),}, //     [][][]  
	{(Point){-1   , 0   },XYOFS(-3, 0),},
	{(Point){-0.94, 0.31},XYOFS(-3, 1),},
	{(Point){ 0.94,-0.31},XYOFS( 3,-1),},
	{(Point){ 1   , 0   },XYOFS( 3, 0),},
	{(Point){ 0.94, 0.31},XYOFS( 3, 1),},
	{(Point){-0.7 ,-0.7 },XYOFS(-2,-2),},
	{(Point){ 0.7 ,-0.7 },XYOFS( 2,-2),},
	{(Point){-0.7 , 0.7 },XYOFS(-2, 2),},
	{(Point){ 0.7 , 0.7 },XYOFS( 2, 2),},
};

// mode:
// 0 - create parts in normal ball shape
// 1 - same as 0, but replace existing parts which are in the way
// 2 - same as 1, but fill the inside of the circle too

void Ball_break(Ball* ball, int mode, int createType, int charge, Point vel, real speed) {
	Dot** pc = Dot_pos2(ball->pos);
	for (int i=mode==2 ? 0 : 9; i<21; i++) {
		BallNeighbor n = Ball_NEIGHBORS[i];
		Dot* near = pc[n.offset];
		if (near<=Dot_BGFAN) {
			near = Dot_create(
				(int)(ball->pos.x)+n.breakX,
				(int)(ball->pos.y)+n.breakY,
				createType
			);
			if (near) {
				near->vel.xy += vel.xy + n.breakVel.xy * speed;
				near->charge = charge;
			}
		} else if (mode>=1 && near>=Dot_0) {
			near->type = createType;
			near->charge = 0;
		}
	}
	ball->used = false;
}

bool Ball_react(Ball* ball, Dot* part, Elem* newType) {
	//return 0;
	Elem partType = part->type; //this is stored now, incase the particle is deleted!
	bool (*update)(Dot* p, Ball* ball, Elem* newType) = ball->type[ELEMENTS].update_ball_touching;
	if (update) {
		if (update(part, ball, newType))
			return true;
	}
	
	int pstate = ELEMENTS[partType].state;
	int bstate = ELEMENTS[ball->type].state;
	//if (ball->type==Elem_ACID)
		//printf("touching type %s\n",ELEMENTS[part->type].name);
	return (pstate==State_LIQUID && bstate==State_LIQUID && ball->type!=partType) || // liquid part + liquid ball of different type
		(pstate==State_LIQUID && bstate!=State_LIQUID) || // liquid part + non-liquid ball
		(pstate==State_GAS && bstate!=State_GAS) || // gas part + non-gas ball
		partType==Elem_FIRE; // fire part
}

static void checkDragging(Ball* i) {
	if (!i->held) {
		if (Menu_dragStart) {
			if (Vec_fastDist((Point){Pen_x-i->pos.x, Pen_y-i->pos.y})<20)
				i->held = true;
		}
	} else if (Menu_dragging) {
		i->vel.xy += 0.05*(Menu_pen.xy - i->pos.xy);
		i->vel.xy *= 0.9;
	} else {
		i->vel.xy *= 0.3;
		i->held = false;
	}

}

static void checkEntities(Ball* ball) {
	Object_FOR (en) {
		if (en->type==Object_FIGHTER||en->type==Object_FIGHTER+1||en->type==Object_PLAYER) {
			// nodes 4 and 5 are the feet
			for (int f=4; f<=5; f++) {
				ObjectNode* node = &en->parts[f];
				real dx = abs(node->pos.x - ball->pos.x);
				real dy = abs(node->pos.y - ball->pos.y);
				if (dx<=9 && dy<=9) {
					ball->vel.xy += 0.1*(node->pos.xy - node->oldPos.xy);
				}
			}
		}
	}
}

bool movementStep(Ball* i, real n, Elem* touched, Elem* newType, real weight) {
	real nextx = i->pos.x+i->vel.x*n;
	real nexty = i->pos.y+i->vel.y*n;
	// way offscreen
	if (nextx<4 || nextx>=WIDTH-4 || nexty<4 || nexty>=HEIGHT-4) {
		i->used = false;
		return true;
	}
	// edge loop mode
	if (Menu_edgeMode==1) {
		if (nextx<8) {
			if (*Dot_pos(nextx+W,nexty)<=Dot_BGFAN) {
				i->pos.x += W;
				i->vel.x *= 0.8;
			} else
				i->vel.x *= -0.8;
			nextx = i->pos.x+i->vel.x*n;
		} else if (nextx>=W+8) {
			if (*Dot_pos(nextx-W,nexty)<=Dot_BGFAN) {
				i->pos.x -= W;
				i->vel.x *= 0.8;
			} else
				i->vel.x *= -0.8;
			nextx = i->pos.x+i->vel.x*n;
		}
		if (nexty<8) {
			if (*Dot_pos(nextx,nexty+H)<=Dot_BGFAN) {
				i->pos.y += H;
				i->vel.y *= 0.8;
			} else
				i->vel.y *= -0.8;
			nexty = i->pos.y+i->vel.y*n;
		} else if (nexty>=H+8) {
			if (*Dot_pos(nextx,nexty-H)<=Dot_BGFAN) {
				i->pos.y -= H;
				i->vel.y *= 0.5; // this is not 0.8 like the others
			} else
				i->vel.y *= -0.8;
			nexty = i->pos.y+i->vel.y*n;
		}
	}
	// collision with parts
	Point z = {0,0};
	Dot** pc = Dot_pos(nextx,nexty);
	int touches=0;
	for (int d=0;d<37;d++) {
		BallNeighbor n = Ball_NEIGHBORS[d];
		Dot* near = pc[n.offset];
		if (near<=Dot_BGFAN) continue;
		if (near>=Dot_0) {
			*touched = near->type;
			if (Ball_react(i, near, newType))
				continue;
		} else {
			*touched = near-Dot_0;
		}
		z.xy -= n.breakVel.xy;
		touches++;
	}
	//printf("touching: %f %f\n", z.x, z.y);
	if (touches==0) {
		i->pos.x = nextx;
		i->pos.y = nexty;
	} else {
		Vec_normalize(&z);
		i->vel.y -= weight;
		real speed = 0.999*Vec_dist(i->vel);
		z.xy *= -(z.x*i->vel.x + z.y*i->vel.y);
		i->vel.xy += z.xy;
		i->vel.xy *= 0.999;
		z.xy *= 0.1;
		i->vel.xy += z.xy;
		Vec_normalize(&i->vel);
		i->vel.xy *= speed;
		i->pos.xy += i->vel.xy*n;
		i->vel.y += weight;
	}
	pc = Dot_pos2(i->pos);
	z = (Point){0,0};
	touches = 0;
	for (int d=0;d<21;d++) {
		BallNeighbor n = Ball_NEIGHBORS[d];
		Dot* near = pc[n.offset];
		if (near<=Dot_BGFAN) continue;
		if (near>=Dot_0) {
			int btype = i->type;
			int ptype = near->type;
			if (ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state==State_LIQUID && btype!=ptype)
				continue;
			if (ELEMENTS[ptype].state==State_LIQUID && ELEMENTS[btype].state!=State_LIQUID)
				continue;
			if (ELEMENTS[ptype].state==State_GAS && ELEMENTS[btype].state!=State_GAS)
				continue;
			if (ptype==Elem_LASER && ELEMENTS[btype].state==State_LIQUID)
				continue;
			if (ptype==Elem_FIRE)
				continue;
			if (ptype==Elem_THUNDER && btype==Elem_THUNDER)
				continue;
		}
		z.xy -= n.breakVel.xy;
		touches++;
	}
	if (touches) {
		Vec_normalize(&z);
		i->pos.xy += z.xy;
	}
	return false;
}

static void undraw(Ball* i) {
	// erase fake parts from grid
	Dot** p = Dot_pos2(i->pos);
	for (int d=0; d<21; d++) {
		BallNeighbor n = Ball_NEIGHBORS[d];
		if (p[n.offset] == Dot_BALL)
			p[n.offset] = Dot_EMPTY;
	}
}

void Ball_update(void) {
	Ball_FOR (i) {
		if (!i->used) continue;
		// remove invalid balls
		if (!ELEMENTS[i->type].ballValid) {
			i->used = false;
			continue;
		}
		undraw(i);
		real weight = ELEMENTS[i->type].ballWeight;
		i->vel.y += weight;

		real adv = ELEMENTS[i->type].ballAdvection;
		if (adv!=0) {
			Block* cell = Block_at(i->pos.x,i->pos.y);
			i->vel.x += cell->vel.x*adv;
			i->vel.y += cell->vel.y*adv;
			if (Vec_fastDist(cell->vel)>0.3)
				i->vel.xy *= 0.9+(1-adv)/10;
		}

		checkDragging(i);
		checkEntities(i);

		// chcek movement
		Elem touched = 0;
		Elem newType = 0;
		Point vel = i->vel; //this is used way later
		int q = (int)(Vec_dist(i->vel)/2)+1;
		for (int v=0; v<q; v++) {
			if (movementStep(i, 1.0/q, &touched, &newType, weight))
				break;
		}

		if (i->pos.x<4 || i->pos.x>=WIDTH-4 || i->pos.y<4 || i->pos.y>=HEIGHT-4) {
			i->used = false;
			break;
		}
		
		void (*update)(Ball* c, Elem touched, Elem* newType, Point vel) = i->type[ELEMENTS].update_ball;
		if (update)
			update(i, touched, &newType, vel);
		
		if (newType) {
			i->type = newType;
			i->charge = 0;
		}
		
		if (i->used) {
			// draw new fake parts to grid
			Dot** pc = Dot_pos2(i->pos);
			for (int d=0; d<21; d++) {
				Dot** p = &pc[Ball_NEIGHBORS[d].offset];
				if (*p<=Dot_BGFAN)
					*p = Dot_BALL;
			}
		}
	}
}

void Ball_save(SavePixel save[H][W]) {
	Ball_FOR (ball) {
		if (!ball->used) continue;
		axis x = ball->pos.x;
		axis y = ball->pos.y;
		if (Save_onscreen(x,y)) {
			if (save[y-8][x-8].type == 0)
				save[y-8][x-8] = (SavePixel){Elem_SAVE_BALL, ball->type};
		}
	}
}

void Ball_reset(void) {
	Ball_FOR (ball) {
		ball->used = false;
	}
}
