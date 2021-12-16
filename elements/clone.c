#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Dot_toGrid(p);
	
	// if not cloning
	if (!p->charge) {
		// check random nearby part
		axis x = Random_int(5)-1; // 5-1, really?
		axis y = Random_int(5)-1;
		Dot* near = Dot_pos3(p->pos, x, y);
		if (near>=Dot_0) {
			if (near->type == Elem_CLONE)
				p->charge = near->charge;
			else
				p->charge = near->type;
		}
	} else if (Dot_limit1000()) { // create particles
		int x = p->pos.x + Random_int(3)-1;
		int y = p->pos.y + Random_int(3)-1;
		if (*Dot_pos(x,y)<=Dot_BGFAN && Rnd_perchance(10))
			Dot_create(x,y,p->charge);
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (ball->charge==0 && touched>0)
		ball->charge = touched;
	else if (ball->charge && Dot_limit1000()) {
		int x = ball->pos.x;
		int y = ball->pos.y;
		if (ELEMENTS[ball->charge].state==State_POWDER || ball->charge==Elem_MAGMA || ball->charge==Elem_SPARK)
			y+=4;
		if (*Dot_pos(x,y)<=Dot_BGFAN)
			Dot_create(x, y, ball->charge);
	}
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return true;
	return false;
}

AUTORUN {
	ELEMENTS[Elem_CLONE] = (ElementDef){
		"CLONE", RGB(0x90,0x70,0x10), State_SOLID,
		
		.friction = 0.5,
		.ze = 0.2, .Ae = 0.2,
		.wheelWeight = 3,

		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.3,

		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,	
	};
}
