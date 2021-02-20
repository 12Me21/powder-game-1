#include "../common.h"
#include "../part.h"
#include "../elements.h"
#include "../vector.h"
#include <stdio.h>

static bool update(Part* p, Block* c) {
	Vector airvel = c->vel;
	if (p->meta == 2) {
		Vec_mul(&p->vel, .8);
		Vec_add(&airvel, &p->vel);
	}
	Vec_mul(&airvel, .2);
	if (p->meta==0 || p->meta==2) {
		double q = Random_2(-0.01, -0.05);
		c->vel.x += Random_2(-0.02, 0.02);
		c->vel.y += q;
		c->pres += -q;
		pd -= -q;
	} else if (p->meta==1) {
		double q = Random_2(-0.01, -0.05);
		c->pres += -q;
		pd -= -q;
	}
	Part_blow(p, &airvel);
	int x = p->pos.x+Random_int(5)-2;
	Part* g = Part_at[(int)p->pos.y+Random_int(5)-2][x];
	if (g>=Part_0) {
		switch (g->type) {
		when(Elem_POWDER): case Elem_ANT: case Elem_VINE:
			g->type = Elem_FIRE;
		when(Elem_WATER): case Elem_SALTWATER:
			Part_remove(p);
			return 1;
		when(Elem_SEED):
			if (Random_(100)<50)
				g->type = Elem_FIRE;
		when(Elem_SNOW):
			g->type = Elem_WATER;
		}
	}
	int r=5;
	if (p->meta == 1)
		r = 20;
	if (Random_(100)<r) {
		Part_remove(p);
		return 1;
	}
	return 0;
}

AUTORUN {
	ELEMENTS[Elem_FIRE].update = update;
}
