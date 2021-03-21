break; case Elem_FIRE:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	if (p->charge == 2) {
		p->vel.xy *= 0.8;
		airvel.xy += p->vel.xy;
	}
	airvel.xy *= 0.2;
	if (p->charge==0 || p->charge==2) {
		real q = Random_2(-0.01, -0.05);
		c->vel.x += Random_2(-0.02, 0.02);
		c->vel.y += q;
		Block_addPressure(c,-q);
	} else if (p->charge==1) {
		Block_addPressure(c, -Random_2(-0.01, -0.05));
	}
	Dot_blow(p, airvel);
	
	Dot* g = Dot_rndNear(p->pos,5);
	if (g>=Dot_0) {
		switch (g->type) {
		when(Elem_POWDER):; case Elem_ANT: case Elem_VINE:
			g->type = Elem_FIRE;
		when(Elem_WATER): case Elem_SEAWATER:
			Dot_KILL();
		when(Elem_SEED):;
			if (Rnd_perchance(50))
				g->type = Elem_FIRE;
		when(Elem_SNOW):;
			g->type = Elem_WATER;
		}
	}
	if (Rnd_perchance(p->charge==1 ? 20 : 5))
		Dot_KILL();

#elif defined UPDATE_BALL
	if (touched==Elem_WATER||touched==Elem_SOAPY||touched==Elem_SEAWATER||touched==Elem_ACID)
		Ball_break(ball, 0, Elem_FIRE, 0, Point(0), 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_POWDER: case Elem_SEED: case Elem_WOOD: case Elem_GUNPOWDER: case Elem_OIL: case Elem_C4: case Elem_NITRO: case Elem_ANT: case Elem_GAS: case Elem_VINE: case Elem_BIRD: case Elem_FUSE: {
		part->type = Elem_FIRE;
		part->charge = 0;
	} break;	case Elem_ICE: case Elem_SNOW: //make #define when use {
		part->type = Elem_WATER;
		part->charge = 0;
		break;
	case Elem_FIREWORKS:
		if (part->charge>0 && part->charge<100) {
			part->vel.y -= 50;
			part->charge += 100;
		}
	}
#endif
}
