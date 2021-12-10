#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	// if air velocity>1, 50% chance to turn into snow
	if (Vec_fastDist(c->vel)>1 && Rnd_perchance(50))
		p->type = Elem_SNOW;
	Dot_toGrid(p);

	// pick a random particle within 9x9, melt self if it's hot
	Dot* near = Dot_rndNear(p->pos, 9);
	if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT)
		p->type = Elem_WATER;
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point v) {
	real vel = Vec_dist(ball->vel);
	// break if touching thunder/acid, or
	// if touching block,wheel,stone,metal,bomb, with velocity>5
	if (touched==Elem_THUNDER||touched==Elem_ACID|| 
		((touched==Elem_BLOCK||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB)&&vel>5))
		Ball_break(ball, 0, Elem_SNOW, 0, ball->vel, vel);
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	switch (part->type) {
	when(Elem_WATER):;
		// turn water particles into ice
		part->type = Elem_ICE;
		part->charge = 0;
	when(Elem_FIRE): case Elem_SPARK: case Elem_LASER: case Elem_TORCH:;
		// melt after touching 20 of these type particles
		if (++ball->charge>=20)
			*newType = Elem_WATER;
	when(Elem_ICE): case Elem_SNOW:
		// reset melt counter
		ball->charge = 0;
	when(Elem_MAGMA):;
		// melt instantly
		*newType = Elem_WATER;
	when(Elem_THUNDER):;
		return true;
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_ICE] = (ElementDef){
		.name = "ICE",
		.color = 0xD0D0FF,
		.state = State_SOLID,
		.temperature = -1000,
		.dissolveRate = 40,
		.friction = 1,
		.ze = 0.8, .Ae = 1.0,
		.ballValid = true,
		.ballWeight = 0.1,
		.ballAdvection = 0.3,
		.wheelWeight = 4,
		
		.update_dot = dot,
		.update_ball = ball,
		.update_ball_touching = ball_touching,	
	};
}
