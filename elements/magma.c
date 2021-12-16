#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	Dot_liquidUpdate(p, c, 0.1, 0,0.1, 0.01, 0.01,0.1, 0.9);

	Dot* near = Dot_rndNear5(p->pos);
	if (near>=Dot_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_SEED: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			break;
			//magma+water/soapy = stone+steam
		case Elem_WATER: case Elem_SOAPY:
			if (Rnd_perchance(50))
				return true;
			p->type = Elem_STONE;
			near->type = Elem_STEAM;
			break;
			//melt stone
		case Elem_STONE:
			near->vel.x += Random_2(-0.1,0.1);
			if (Rnd_perchance(5))
				near->type = Elem_MAGMA;
			break;
			//magma+saltwater=stone+salt (no steam, note)
		case Elem_SEAWATER:
			if (Rnd_perchance(50))
				return true;
			p->type = Elem_STONE;
			near->type = Elem_SALT;
			break;
			//melt glass
		case Elem_GLASS:
			if (Rnd_perchance(50))
				near->type = Elem_MAGMA;
			//slowly melt mercury
			break;
		case Elem_MERCURY:
			if (Rnd_perchance(1))
				near->type = Elem_MAGMA;
		}
	}
	int dir = Random_int(4);
	near = Dot_dirNear(p->pos, dir);
	//enter pump
	if (near>=Dot_0 && Dot_checkPump(p, near, dir))
		return true;
	
	return false;
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	switch (part->type) {
	when(Elem_WATER):;
		if (++ball->charge>=20)
			*newType = Elem_METAL;
		part->type = Elem_STEAM;
		part->charge = 0;
	when(Elem_MAGMA):;
		ball->charge = 0;
	when(Elem_SOAPY):;
		if (++ball->charge>=20)
			*newType = Elem_GLASS;
		part->type = Elem_STEAM;
		part->charge = 0;
	when(Elem_SEAWATER):;
		if (++ball->charge>=20)
			*newType = Elem_STONE;
		part->type = Elem_STEAM;
		part->charge = 0;
	when(Elem_POWDER): case Elem_SEED: case Elem_WOOD: case Elem_GUNPOWDER: case Elem_SUPERBALL: case Elem_OIL: case Elem_C4: case Elem_NITRO: case Elem_ANT: case Elem_GAS: case Elem_VINE: case Elem_BIRD: case Elem_FUSE:
		part->type = Elem_FIRE;
		part->charge = 0;
	when(Elem_ICE): case Elem_SNOW:
		part->type = Elem_WATER;
		part->charge = 0;
	when(Elem_FIREWORKS):;
		if (part->charge>0 && part->charge<100) {
			part->vel.y -= 50;
			part->charge += 100;
		}
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_MAGMA] = (ElementDef){
		"MAGMA", RGB(0xFF,0x66,0x33), State_HOT,
		.playerValid = true,
		.temperature = 10000,
		.dissolveRate = 50,
		.friction = 0.5,
		.ballLight = true,
		.ze = 0.2, .Ae = 0.2,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0,
		.wheelWeight = 9,
		
		.update_dot = dot,
		.update_ball_touching = ball_touching,
	};
}
