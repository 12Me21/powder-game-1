#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
	if (Random_(100)<10) {
		Part_remove(p);
		return 1;
	}
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_STEAM].update = update;
}
