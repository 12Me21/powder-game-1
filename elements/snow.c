#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	Vector airvel = c->vel;
	airvel.y += Random_2(0.01, 0.08);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y + Random_int(3)-1;
	Part* g = Part_at[y][x];
	if (g>=Part_0) {
		if (g->type == Elem_ICE)
			p->type = Elem_ICE;
		else if (g->type!=Elem_WOOD && g->type!=Elem_WHEEL && g->type!=Elem_SNOW && g->type!=Elem_SNOW && g->type!=Elem_CLONE && g->type!=Elem_VINE && g->type!=Elem_CLOUD)
			p->type = Elem_WATER;
	}
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_SNOW].update = update; //snow~
}
