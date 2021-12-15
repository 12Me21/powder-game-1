#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Point airvel = c->vel;
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	
	if (Rnd_perchance(10))
		return true;
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	// if touch anything, break into that type
	if (touched>=0 && ELEMENTS[touched].state>0)
		Ball_break(ball, 0, touched, 0, Point(0.5f*ball->vel.xy), 0.5f);
}

AUTORUN {
	ELEMENTS[Elem_STEAM] = (ElementDef){
		.name = "STEAM",
		.color = 0xE0E0E0,
		.state = State_NONE,
		.playerValid = true,
		.dissolveRate = 30,
		.friction = 1,
		.ze = 0.2, .Ae = 0.2,
		.ballValid = true,
		.ballWeight = 0.05,
		.ballAdvection = 0.5,
		.wheelWeight = 1,
		
		.update_dot = dot,
		.update_ball = ball,
	};
}
