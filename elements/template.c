#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"

static bool dot(Dot* p, Block* c) {
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType) {
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	return false;
}

AUTORUN {
	ELEMENTS[Elem_POWDER] = (ElementDef){
		.name = 
		.color = 
		.state = State_
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
		.update_ball_touching = ball_touching,	
	};
}
