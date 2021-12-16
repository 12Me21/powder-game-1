#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Dot_toGrid(p);
	
	Dot* near = Dot_rndNear(p->pos, 5);
	if (near>=Dot_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_SEED: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			break;
		case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER:
			return true;
			break;
		case Elem_WOOD:
			near->type = Elem_TORCH;
			break;
		case Elem_SNOW:
			near->type = Elem_WATER;
		}
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	switch (touched) {
	case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER: case Elem_ACID:
		Ball_break(ball, 0, Elem_TORCH, 0, Point(0), 0);
	when(Elem_THUNDER):;
		Ball_break(ball, 0, Elem_FIRE, 0, Point(0), 0);
	}
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	switch (part->type) {
	case Elem_POWDER:case Elem_SEED:case Elem_GUNPOWDER:case Elem_SUPERBALL:case Elem_OIL:case Elem_C4:case Elem_NITRO:case Elem_ANT:case Elem_GAS:case Elem_VINE:case Elem_BIRD:case Elem_FUSE:
		part->type = Elem_FIRE;
		part->charge = 0;
		break;
	case Elem_ICE: case Elem_SNOW: case Elem_CLOUD:
		part->type = Elem_WATER;
		part->charge = 0;
		break;
	case Elem_FIREWORKS:
		if (part->charge>0 && part->charge<100) {
			part->vel.y -= 50;
			part->charge += 100;
		}
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_WATER] = (ElementDef){
		"TORCH", RGB(0xFF,0xA0,0x20), State_HOT,
		
		.temperature = 4000,
		.dissolveRate = 10,
		.ballLight = 1,
		.ballValid = 1,
		.ballWeight = 0.1,
		.ballAdvection = 0.3,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,
	};
}
