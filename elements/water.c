#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = atLeast(Random_int(8)-4, 0); //0 to 3
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = near->type;
		if (dir<3 && ((type[ELEMENTS].state==State_POWDER && type!=Elem_STONE && type!=Elem_CONCRETE)||type==Elem_NITRO||type==Elem_SOAPY||type==Elem_SEAWATER)) {
			if (Rnd_perchance(10))
				Dot_swap(p, near);
		//freeze water
		} else if (type==Elem_ICE) {
			if (Rnd_perchance(50))
				p->type = Elem_ICE;
		//put water into pump
		} else if (Dot_checkPump(p, near, dir))
			return true;
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched==Elem_MAGMA || touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_WATER, 0, Point(0), 0);
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	switch(part->type) {
	case Elem_FIRE:;
		Dot_remove(part);
		return 1;
	case Elem_WOOD:;
		part->type = Elem_SEED;
		part->charge = 0;
		break;
	case Elem_ICE:;
		*newType = Elem_ICE;
		break;
	case Elem_SNOW:;
		if (++ball->charge>=20)
			*newType = Elem_ICE;
		break;
	case Elem_MAGMA: case Elem_THUNDER: case Elem_LASER:;
		return 1;
	case Elem_TORCH:;
		Dot_remove(part);
		break;
	case Elem_METAL:;
		if (Rnd_perchance(10)) {
			part->type = Elem_POWDER;
			part->charge = 0;
		}
		if (++ball->charge>=20) //hmm this is the same as for snow
			*newType = Elem_SEAWATER;
		break;
	case Elem_FUSE:;
		part->type = Elem_GUNPOWDER;
		part->charge = 0;
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_WATER] = (ElementDef){
		.name = "WATER",
		.color = 0x4040FF,
		.state = State_LIQUID,
		.playerValid = true,
		.dissolveRate = 40,
		.friction = 0.8,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.4,
		.wheelWeight = 4,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,
	};
}
