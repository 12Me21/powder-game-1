#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

void func(axis x, axis y, axis sx, axis sy) {
	Dot* near = Dot_at[y][x];
	if (near>=Dot_0 && near->type != Elem_GUNPOWDER) {
		near->vel.x += 10*(x-sx);
		near->vel.y += 10*(y-sy);
	}
	if (!(y&3) && !(x&3)) {
		Block* cell = Block_at(x,y);
		if (cell->block!=Block_BLOCK) {
			if (x!=sx)
				cell->vel.x += 10.0/(x-sx);
			if (y!=sy)
				cell->vel.y += 10.0/(y-sy);
		}
	}
}

static bool dot(Dot* p, Block* c) {
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.2);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.8;
	Dot_blow(p, airvel);
	
	Dot* near = Dot_rndNear(p->pos,5);
	if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT) {
		// explode
		Dot_doRadius((int)p->pos.x & 0xFFF4, (int)p->pos.y & 0xFFF4, 10, func);
		p->type = Elem_FIRE;
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched<0) return;
	// explode when touching a hot element AND charge is 0
	if (ball->charge==0 && touched[ELEMENTS].state==State_HOT) {
		for (int i=0;i<37;i++) {
			const BallNeighbor* n = &Ball_NEIGHBORS[i];
			Dot* near = Dot_pos2(ball->pos)[n->offset];
			if (near<=Dot_BGFAN) {
				Dot* new = Dot_create(
					(int)ball->pos.x+n->breakX,
					(int)ball->pos.y+n->breakY,
					Elem_FIRE
				);
				if (new>=Dot_0) {
					real f = Random_(20);
					new->vel.xy += ball->vel.xy*f+n->breakVel.xy*f/2;
					new->charge = 2;
				}
			}
		}
		ball->used = false;
	// destroyed by acid
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_GUNPOWDER, 0, Point(0), 0);
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	// charge is increased by water types and decreased by some hot elements
	switch (part->type) {
	case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER:
		if (ball->charge<20)
			ball->charge++;
	when(Elem_FIRE): case Elem_MAGMA: case Elem_TORCH: case Elem_LASER: case Elem_SPARK:
		if (ball->charge>0)
			ball->charge--;
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_GUNPOWDER] = (ElementDef){
		"G-POWDER", RGB(0xB0,0x80,0x50), State_POWDER,
		
		.playerValid = true,
		.dissolveRate = 10,
		.friction = 0.5,
		.ze = 0.2, .Ae = 0.2,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.4,
		.wheelWeight = 2,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,	
	};
}
