break; case Elem_SEAWATER:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	Dot* near = Dot_rndNear(p->pos, 5);
	// turn seed, wood, metal into powder
	if (near>=Dot_0) {
		if (near->type==Elem_SEED||near->type==Elem_WOOD||near->type==Elem_METAL) {
			near->type = Elem_POWDER;
			near->charge = 0;
		}
	}
	// 0 0 0 0 0 1 2 3
	int dir = atLeast(Random_int(8)-4, 0);

	near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		int type = near->type;
		if (dir!=3 && ((type[ELEMENTS].state==State_POWDER && type!=Elem_STONE && type!=Elem_CONCRETE)||type==Elem_NITRO)) { //nitro, and solids except powder,stone
			if (Rnd_perchance(10))
				Dot_swap(p, near);
		// destroy vine AGAIN
		} else if (type==Elem_VINE) {
			near->type = Elem_POWDER;
			near->charge = 0;
		} else if (type==Elem_CONCRETE) {
			if (Rnd_perchance(1)) {
				near->type = Elem_STONE;
				near->charge = 0;
				Dot_swap(p, near);
			}
		//put water into pump
		} else if (Dot_checkPump(p, near, dir))
			Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SEAWATER, 0, Point(0), 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_WATER):;
		ball->charge = 0;
	when(Elem_FIRE):;
		if (++ball->charge>=20)
			*newType = Elem_SALT;
		Dot_remove(part);
		return 1;
	when(Elem_WOOD): case Elem_SEED: case Elem_METAL: case Elem_VINE:
		part->type = Elem_POWDER;
		part->charge = 0;
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_SNOW):;
		if (++ball->charge>=20)
			*newType = Elem_ICE;
	when(Elem_MAGMA):;
		*newType = Elem_SALT;
	when(Elem_TORCH): case Elem_SPARK:
		if (++ball->charge>=20)
			*newType = Elem_SALT;
		Dot_remove(part);
	when(Elem_THUNDER):;
		return 1;
	when(Elem_LASER):;
		if (++ball->charge>=20)
			*newType = Elem_SALT;
		return 1;
	when(Elem_SALT):;
		if (ball->charge++<20)
			Dot_remove(part);
	when(Elem_FUSE):;
		part->type = Elem_GUNPOWDER;
		part->charge = 0;
	}
#endif
}
