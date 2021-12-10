#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"

static bool dot(Dot* p, Block* c) {
	c->vel.xy += p->vel.xy;

	// fan is special because other particles can pass through it.
	// this is achieved by putting a special value onto the part grid,
	// rather than a pointer to itself.
	Dot** n = Dot_pos2(p->pos);
	if (*n == Dot_EMPTY)
		*n = Dot_BGFAN;
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched>0) {
		Block* cell = Block_at(ball->pos.x, ball->pos.y);
		Block_addPressure(cell, 10);
	}
}

AUTORUN {
	ELEMENTS[Elem_FAN] = (ElementDef){
		.name = "FAN",
		.color = 0x8080FF,
		.state = State_NONE,
		.playerValid = true,
		.friction = 1,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.9,
		
		.update_dot = dot,
		.update_ball = ball,
	};
}
