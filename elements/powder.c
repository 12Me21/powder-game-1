#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched>=0) {
		if (touched[ELEMENTS].state==State_LIQUID)
			Ball_break(ball, 0, Elem_POWDER, 0, Point(0.5f*ball->vel.xy), 0.5);
		else if (touched[ELEMENTS].state==State_HOT)
			Ball_break(ball, 0, Elem_FIRE, 0, Point(0.5f*ball->vel.xy), 0.5);
	}
}

AUTORUN {
	ELEMENTS[Elem_POWDER] = (ElementDef){
		.name = "POWDER",
		.color = 0xF2BD6B,
		.state = State_POWDER,
		.playerValid = true,
		.dissolveRate = 5,
		.friction = 0.5,
		.ze = 0.2, .Ae = 0.2,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.5,
		.wheelWeight = 1,
		
		.update_dot = dot,
		.update_ball = ball,
	};
}
