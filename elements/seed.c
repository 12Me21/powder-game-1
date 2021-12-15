#include "../common.h"
#include "../dot.h"
#include "../elements.h"
#include "../ball.h"
#include "../random.h"

static bool dot(Dot* p, Block* c) {
	if (p->charge==0) {
		Point airvel = c->vel;
		airvel.y += Random_2(0.01, 0.09);
		airvel.xy += p->vel.xy;
		p->vel.xy *= 0.8;
		Dot_blow(p, airvel);
	} else
		Dot_toGrid(p);
	
	if (p->charge==0) {
		Dot* below = Dot_pos3(p->pos, 0, 1);
		if (below<Dot_0)
			return false;
		if (below->type!=Elem_POWDER && below->type!=Elem_WOOD && below->type!=Elem_VINE)
			return false;
		if (!Dot_limit1000())
			return false;
	}
	
	p->charge=1;
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y - (int)Random_(1.5);
	if (Dot_at[y][x] <= Dot_BGFAN) {
		if (Dot_at[y+1][x] <= Dot_BGFAN) {
			*Dot_pos2(p->pos) = Dot_EMPTY;
			p->pos = (Point){x,y};
			Dot_at[y][x] = p;
			Dot_create(x, y+1, Elem_WOOD);
		}
		if (Rnd_perchance(5))
			return true;
	}
	return false;
}

static void ball(Ball* ball, Elem touched, Elem* newType, Point vel) {
	if (touched<0) return;
	// destroyed by acid
	if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SEED, 0, Point(0.5f*ball->vel.xy), 0.5f);
	// burned by hot elements (except spark)
	else if (touched!=Elem_SPARK && touched[ELEMENTS].state==State_HOT)
		Ball_break(ball, 0, Elem_FIRE, 0, Point(0.5f*ball->vel.xy), 0.5f);
}

static bool ball_touching(Dot* part, Ball* ball, Elem* newType) {
	switch (part->type) {
	when(Elem_POWDER):;
		if (ball->charge==1)
			// when hydrated, turn into wood ball
			*newType = Elem_WOOD;
		else {
			// otherwise, turn powder into seed
			part->type = Elem_SEED;
			part->charge = 0;
		}
	when(Elem_WATER):;
		// hydrated
		ball->charge = 1;
	when(Elem_VINE):;
		// turn vine into wood
		part->type = Elem_WOOD;
		part->charge = 0;
	}
	return false;
}

AUTORUN {
	ELEMENTS[Elem_SEED] = (ElementDef){
		.name = "SEED",
		.color = 0x90C040,
		.state = State_POWDER,
		.playerValid = true,
		.temperature = 500,
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
