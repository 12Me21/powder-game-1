#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	if (Vec_fastDist(&c->vel) > 1 && Random_(100)<50)
		p->type = Elem_SNOW;
	Vector airvel = {0,0};
	Part_blow(p, &airvel);
	int x = p->pos.x + Random_int(9)-4;
	Part* g = Part_at[(int)p->pos.y+Random_int(9)-4][x];
	if (g >= Part_0 && ELEMENTS[g->type].state == State_HOT)
		p->type = Elem_WATER;
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_ICE].update = update;
}
