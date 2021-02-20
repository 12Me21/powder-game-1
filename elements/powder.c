#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	Vector airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_POWDER].update = update;
}
