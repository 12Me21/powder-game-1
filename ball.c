#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#include "menu.h"
#include "input.h"
#include "entity.h"
#include "elements.h"
#include "cell.h"

Ball balls[Ball_MAX];
Ball* const Ball_END = &balls[Ball_MAX];

void Ball_create(real x, real y, Elem type) {
	for (Ball* ball=balls; ball<Ball_END; ball++) {
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

#define XYOFS(x,y) x,y,Part_ofs(x,y)

static const struct neighbor {
	Point breakVel;
	int breakX;
	int breakY;
	int offset;
} neighbors[] = {
	{(Point){-0.7 ,-0.7 },XYOFS(-1,-1),},
   {(Point){ 0   ,-1   },XYOFS( 0,-1),},
   {(Point){ 0.7 ,-0.7 },XYOFS( 1,-1),},
   {(Point){-1   , 0   },XYOFS(-1, 0),},
   {(Point){ 0   , 0   },XYOFS( 0, 0),},
   {(Point){ 1   , 0   },XYOFS( 1, 0),},
   {(Point){-0.7 , 0.7 },XYOFS(-1, 1),},
   {(Point){ 0   , 1   },XYOFS( 0, 1),},
   {(Point){ 0.7 , 0.7 },XYOFS( 1, 1),},
   {(Point){-0.44,-0.89},XYOFS(-1,-2),},
   {(Point){ 0   ,-1   },XYOFS( 0,-2),},
   {(Point){ 0.44,-0.89},XYOFS( 1,-2),},
   {(Point){-0.44, 0.89},XYOFS(-1, 2),},
   {(Point){ 0   , 1   },XYOFS( 0, 2),},
   {(Point){ 0.44, 0.89},XYOFS( 1, 2),},
   {(Point){-0.89,-0.44},XYOFS(-2,-1),},
   {(Point){-1   , 0   },XYOFS(-2, 0),},
   {(Point){-0.89, 0.44},XYOFS(-2, 1),},
   {(Point){ 0.89,-0.44},XYOFS( 2,-1),},
   {(Point){ 1   , 0   },XYOFS( 2, 0),},
   {(Point){ 0.89, 0.44},XYOFS( 2, 1),},
   {(Point){-0.31,-0.94},XYOFS(-1,-3),},
   {(Point){ 0   ,-1   },XYOFS( 0,-3),},
   {(Point){ 0.31,-0.94},XYOFS( 1,-3),},
   {(Point){-0.31, 0.94},XYOFS(-1, 3),},
   {(Point){ 0   , 1   },XYOFS( 0, 3),},
   {(Point){ 0.31, 0.94},XYOFS( 1, 3),},
   {(Point){-0.94,-0.31},XYOFS(-3,-1),},
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

static void Ball_break(Ball* ball, int mode, int createType, int meta, real vx, real vy, real speed) {
	Part** pc = Part_pos2(ball->pos);
	if (mode==0) {
		for (int i=9;i<21;i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					(int)(ball->pos.x)+neighbors[i].breakX,
					(int)(ball->pos.y)+neighbors[i].breakY,
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
		for (int i=mode==1?9:0; i<21; i++) {
			Part* near = pc[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				near = Part_create(
					(int)(ball->pos.x)+neighbors[i].breakX,
					(int)(ball->pos.y)+neighbors[i].breakY,
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

static bool Ball_react(Ball* ball, Part* part, Elem* newType) {
	//return 0;
	Elem partType = part->type; //this is stored now, incase the particle is deleted!
	switch (ball->type) {
#define UPDATE_BALL_PART 1
#include "elements/All.c"
#undef UPDATE_BALL_PART
	}
	int pstate = ELEMENTS[partType].state;
	int bstate = ELEMENTS[ball->type].state;
	//if (ball->type==Elem_ACID)
		//printf("touching type %s\n",ELEMENTS[part->type].name);
	return (pstate==State_LIQUID && bstate==State_LIQUID && ball->type!=partType) ||
		(pstate==State_LIQUID && bstate!=State_LIQUID) ||
		(pstate==State_GAS && bstate!=State_GAS) ||
		partType==Elem_FIRE;
}

static void checkDragging(Ball* i) {
	if (!i->held) {
		if (Menu_dragStart) {
			if (Vec_fastDist((Point){Pen_x-i->pos.x, Pen_y-i->pos.y})<20)
				i->held = true;
		}
	} else if (Menu_dragging) {
		i->vel.x += 0.05*(Pen_x-i->pos.x);
		i->vel.y += 0.05*(Pen_y-i->pos.y);
		Vec_mul(&i->vel, 0.9);
	} else {
		Vec_mul(&i->vel, 0.3);
		i->held = false;
	}

}

static void checkEntities(Ball* i) {
	for (Entity* en=entitys; en<Entity_next; en++) {
		if (en->type==Entity_FIGHTER||en->type==Entity_FIGHTER+1||en->type==Entity_PLAYER) {
			for (int f=4; f<=5; f++) {
				real dx = abs(en->parts[f].pos.x - i->pos.x);
				real dy = abs(en->parts[f].pos.y - i->pos.y);
				if (dx<=9 && dy<=9) {
					i->vel.x += 0.1*(en->parts[f].pos.x - en->parts[f].oldPos.x);
					i->vel.y += 0.2*(en->parts[f].pos.y - en->parts[f].oldPos.y);
				}
			}
		}
	}
}

bool movementStep(Ball* i, real n, Elem* touched, Elem* newType, real weight) {
	real nextx = i->pos.x+i->vel.x*n;
	real nexty = i->pos.y+i->vel.y*n;
	// way offscreen
	if (nextx<4 || nextx>=WIDTH-4 || nexty<4 || nexty>=H+12) {
		i->used = false;
		return true;
	}
	// edge loop mode
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
				i->vel.y *= 0.5; // this is not 0.8 like the others
			} else
				i->vel.y *= -0.8;
			nexty = i->pos.y+i->vel.y*n;
		}
	}
	// collision with parts
	Point z = {0,0};
	Part** pc = Part_pos(nextx,nexty);
	int touches=0;
	for (int d=0;d<37;d++) {
		Part* near = pc[neighbors[d].offset];
		if (near<=Part_BGFAN) continue;
		if (near>=Part_0) {
			*touched = near->type;
			if (Ball_react(i, near, newType))
				continue;
		} else {
			*touched = near-Part_0;
		}
		Vec_sub(&z, neighbors[d].breakVel);
		touches++;
	}
	if (touches==0) {
		i->pos.x = nextx;
		i->pos.y = nexty;
	} else {
		Vec_normalize(&z);
		i->vel.y -= weight;
		real d = 0.999*Vec_dist(i->vel);
		Vec_mul(&z, -(z.x*i->vel.x + z.y*i->vel.y));
		Vec_add(&i->vel, z);
		Vec_mul(&i->vel, 0.999);
		Vec_mul(&z, 0.1);
		Vec_add(&i->vel, z);
		Vec_normalize(&i->vel);
		Vec_mul(&i->vel, d);
		i->pos.x += i->vel.x*n;
		i->pos.y += i->vel.y*n;
		i->vel.y += weight;
	}
	pc = Part_pos2(i->pos);
	z = (Point){0,0};
	touches = 0;
	for (int d=0;d<21;d++) {
		Part* near = pc[neighbors[d].offset];
		if (near<Part_BGFAN) continue;
		if (near>=Part_0) {
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
		Vec_sub(&z, neighbors[d].breakVel);
		touches++;
	}
	if (touches) {
		Vec_normalize(&z);
		Vec_add(&i->pos, z);
	}
	return false;
}

static void undraw(Ball* i) {
	// erase fake parts from grid
	Part** p = Part_pos2(i->pos);
	for (int d=0; d<21; d++)
		if (p[neighbors[d].offset] == Part_BALL)
			p[neighbors[d].offset] = Part_EMPTY;
}

void Ball_update(void) {
	for(Ball* i=balls; i<Ball_END; i++) {
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
		if (adv) {
			Block* cell = &Part_blocks[(int)i->pos.y>>2][(int)i->pos.x>>2];
			i->vel.x += cell->vel.x*adv;
			i->vel.y += cell->vel.y*adv;
			if (Vec_fastDist(cell->vel)>0.3)
				Vec_mul(&i->vel, 0.9+(1-adv)/10);
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
		} //end of movement loop
		// 

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
		if (newType) {
			i->type = newType;
			i->meta = 0;
		}
		
		if (i->used) {
			// draw new fake parts to grid
			Part** pc = Part_pos2(i->pos);
			for (int d=0; d<21; d++) {
				Part** p = &pc[neighbors[d].offset];
				if (*p<=Part_BGFAN)
					*p = Part_BALL;
			}
		}
	}
}
