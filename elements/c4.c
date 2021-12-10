#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"

static bool dot(Dot* p, Block* c) {
	Dot_toGrid(p);
	// note: we do not set velocity to 0 here
	
	if (p->charge==0) {
		Dot* near = Dot_rndNear(p->pos, 3);
		if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT)
			p->charge = 1;
	} else {
		//spread explodeystate
		for (int b=0; b<8; b++) {
			Dot* near = Dot_pos2(p->pos)[Dot_ofs8(b)];
			if (near >= Dot_0 && near->type==Elem_C4)
				near->charge = 1;
		}
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* near = Dot_at[y][x];
			if (near>=Dot_0) {
				near->vel.x += 10*(x-sx);
				near->vel.y += 10*(y-sy);
			}
			if ((y&3)+(x&3)==0) {
				Block* cell = Block_at(x,y);
				if (cell->block!=Block_BLOCK) {
					if (x!=sx)
						cell->vel.x += 1/(x-sx);
					if (y!=sy)
						cell->vel.y += 1/(y-sy);
				}
			}
		}
		Dot_doRadius((int)p->pos.x&0xFFF4, (int)p->pos.y&0xFFF4, 10, func); //fff4, really?
		return true;
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched<0) return;
	if (ELEMENTS[touched].state==State_HOT) {
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* near = Dot_pos(x, y)[0];
			if (near>=Dot_0) {
				near->vel.x += 10*(x-sx);
				near->vel.y += 10*(y-sy);
			}
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
		Dot_doRadius((int)ball->pos.x&~3, (int)ball->pos.y&~3, 10, func);
		ball->used = false;
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_NITRO, 0, Point(0), 0);
}

AUTORUN {
	ELEMENTS[Elem_C4] = (ElementDef){
		.name = "C4",
		.color = 0xFFFFCC,
		.state = State_SOLID,
		.dissolveRate = 100,
		.friction = 0.5,
		.ze = 0.5, .Ae = 0.5,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.2,
		.wheelWeight = 4,
		
		.update_dot = dot,
		.update_ball = ball,
	};
}
