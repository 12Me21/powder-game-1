#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	Vec_add(&c->vel, &p->vel);
	if (Part_at[(int)p->pos.y][(int)p->pos.x] == Part_EMPTY)
		Part_at[(int)p->pos.y][(int)p->pos.x] = Part_BGFAN;
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_FAN].update = update;
}
