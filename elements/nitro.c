#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static void func(axis x, axis y, axis sx, axis sy) {
	Dot* d = Dot_pos(x, y)[0];
	if (d>=Dot_0) {
		d->vel.x += 10*(x-sx);
		d->vel.y += 10*(y-sy);
	}
	if ((y&3)+(x&3)==0){
		Block* cell = Block_at(x,y);
		if (cell->block!=Block_BLOCK) {
			if (x!=sx)
				cell->vel.x += 10/(x-sx);
			if (y!=sy)
				cell->vel.y += 10/(y-sy);
		}
	}
}

static bool dot(Dot* p, Block* c) {
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	// 0 0 0 0 0 1 2 3
	int dir = atLeast(Random_int(8)-4, 0);
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		//powders except stone
		if (dir<3 && (near->type[ELEMENTS].state==State_POWDER && (near->type!=Elem_STONE))) {
			if (Rnd_perchance(10))
				Dot_swap(p, near);
		// fuse
		} else if (near->type==Elem_FUSE && !near->Cfuse.burning) {
			near->Cfuse.type = Elem_NITRO;
			return true;
		//put water into pump
		} else if (Dot_checkPump(p,near,dir))
			return true;
	}
	if (Vec_fastDist(p->vel)<10) {
		Dot* near = Dot_rndNear(p->pos, 5);
		if (near<Dot_0 || near->type[ELEMENTS].state != State_HOT)
			return false;
	}
	Dot_doRadius((int)p->pos.x&~3, (int)p->pos.y&~3, 10, func);
	p->type = Elem_FIRE;
	return false;
}

void func2(axis x, axis y, axis sx, axis sy) {
	Dot* d = *Dot_pos(x,y);
	if (d>=Dot_0) {
		d->vel.x += 10*(x-sx);
		d->vel.y += 10*(y-sy);
	}
	if (d<=Dot_BGFAN)
		Dot_create(x, y, Elem_FIRE);
	if ((y&3)+(x&3)==0){
		Block* cell = Block_at(x,y);
		if (cell->block!=Block_BLOCK) {
			if (x!=sx)
				cell->vel.x += 100/(x-sx);
			if (y!=sy)
				cell->vel.y += 100/(y-sy);
		}
	}
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched<0) return;
	if (ELEMENTS[touched].state==State_HOT) {
		Dot_doRadius((int)ball->pos.x&~3, (int)ball->pos.y&~3, 10, func);
		ball->used = false;
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_NITRO, 0, Point(0), 0);
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	if (part->type==Elem_FUSE && !part->Cfuse.burning)
		part->Cfuse.type = Elem_NITRO;
	return false;
}

AUTORUN {
	ELEMENTS[Elem_NITRO] = (ElementDef){
		"NITRO", RGB(0x44,0x77,0x00), State_LIQUID,
		
		.playerValid = true,
		.dissolveRate = 100,
		.friction = 0.8,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.3,
		.wheelWeight = 5,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,
	};
}
