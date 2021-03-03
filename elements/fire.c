break; case Elem_FIRE:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	if (p->meta == 2) {
		Vec_mul(&p->vel, .8);
		Vec_add(&airvel, &p->vel);
	}
	Vec_mul(&airvel, .2);
	if (p->meta==0 || p->meta==2) {
		real q = Random_2(-0.01, -0.05);
		c->vel.x += Random_2(-0.02, 0.02);
		c->vel.y += q;
		c->pres += -q;
		pd -= -q;
	} else if (p->meta==1) {
		real q = Random_2(-0.01, -0.05);
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
			Part_remove(p--);
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
	if (Random_(100)<r)
		Part_remove(p--);
#elif defined UPDATE_BALL
	if (touched==Elem_WATER||touched==Elem_SOAPY||touched==Elem_SALTWATER||touched==Elem_ACID)
		Ball_break(ball, 0, Elem_FIRE, 0, 0, 0, 0);
#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_POWDER: case Elem_SEED: case Elem_WOOD: case Elem_GUNPOWDER: case Elem_OIL: case Elem_C4: case Elem_NITRO: case Elem_ANT: case Elem_GAS: case Elem_VINE: case Elem_BIRD: case Elem_FUSE: {
		part->type = Elem_FIRE;
		part->meta = 0;
	} break;	case Elem_ICE: case Elem_SNOW: //make #define when use {
		part->type = Elem_WATER;
		part->meta = 0;
		break;
	case Elem_FIREWORKS:
		if (part->meta>0 && part->meta<100) {
			part->vel.y -= 50;
			part->meta += 100;
		}
	}
#endif
}
