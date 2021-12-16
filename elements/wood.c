#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Point airvel = p->vel;
	p->vel.xy *= 0.3;
	Dot_blow(p, airvel);
	
	//not burning
	if (p->charge==0) {
		int x = p->pos.x + Random_int(5)-2;
		int y = p->pos.y + Random_int(7)-3;
		Dot* near = Dot_at[y][x];
		if (near >= Dot_0) {
			switch (near->type) {
			when(Elem_FIRE): case Elem_MAGMA:
				if (Rnd_perchance(50))
					p->charge = 1;
				//wood creates seed when near water
			when(Elem_WATER):;
				if (Dot_limit1000()) {
					axis x = p->pos.x + Random_int(3)-1;
					axis y = p->pos.y + Random_int(3)-1;
					if (Dot_at[y][x] <= Dot_BGFAN && Rnd_perchance(10))
						Dot_create(x, y, Elem_SEED);
				}
			}
		}
		//burning
	} else if (p->charge==1) {
		axis x = p->pos.x + Random_int(3)-1;
		axis y = p->pos.y + Random_int(3)-1;
		Dot* near = *Dot_pos(x,y);
		//make fires
		if (near <= Dot_BGFAN) {
			if (Rnd_perchance(30)) {
				Dot* g = Dot_create(x, y, Elem_FIRE);
				if (g>=Dot_0)
					g->charge = 1;
			}
			//water puts out the fire and breaks the wood into powder
		} else if (near->type==Elem_WATER) {
			p->charge = 0;
			p->type = Elem_POWDER;
		}
		//generate powder sometimes
		if (Random_(1000)<5)
			p->type = Elem_POWDER;
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched==Elem_TORCH)
		Ball_break(ball, 0, Elem_TORCH, 0, Point(0), 0);
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_POWDER, 0, Point(0), 0);
	else if (touched==Elem_THUNDER)
		Ball_break(ball, 0, Elem_POWDER, 0, Point(0), 1);
	else if (touched>=0 && ELEMENTS[touched].state==State_HOT) {
		if (ball->charge==1) //if oiled
			Ball_break(ball, 0, Elem_WOOD, 1, Point(0), 0);
		else
			Ball_break(ball, 0, Elem_FIRE, 1, Point(0), 0);
	}
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	if (part->type==Elem_SEED)
		part->charge = 1; // make seed grow
	else if (part->type==Elem_OIL)
		ball->charge = 1; // make ball burn longer
	return false;
}

AUTORUN {
	ELEMENTS[Elem_WOOD] = (ElementDef){
		"WOOD", RGB(0x80,0x50,0x20), State_SOLID,
		
		.temperature = 500,
		.dissolveRate = 10,
		.friction = 0.5,
		.ze = 0.7, .Ae = 0.7,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.4,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,	
	};
}
