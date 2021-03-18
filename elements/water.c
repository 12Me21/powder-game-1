break; case Elem_WATER:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = atLeast(Random_int(8)-4, 0); //0 to 3
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = near->type;
		if (dir<3 && ((type[ELEMENTS].state==State_POWDER && type!=Elem_STONE && type!=Elem_CONCRETE)||type==Elem_NITRO||type==Elem_SOAPY||type==Elem_SEAWATER)) {
			if (Rnd_perchance(10))
				Dot_swap(p, near);
		//freeze water
		} else if (type==Elem_ICE) {
			if (Rnd_perchance(50))
				p->type = Elem_ICE;
		//put water into pump
		} else if (Dot_checkPump(p, near, dir))
			Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA || touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_WATER, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	case Elem_FIRE:;
		Dot_remove(part);
		return 1;
		break;
	case Elem_WOOD:;
		part->type = Elem_SEED;
		part->charge = 0;
		break;
	case Elem_ICE:;
		*newType = Elem_ICE;
		break;
	case Elem_SNOW:;
		if (++ball->charge>=20)
			*newType = Elem_ICE;
		break;
	case Elem_MAGMA: case Elem_THUNDER: case Elem_LASER:;
		return 1;
		break;
	case Elem_TORCH:;
		Dot_remove(part);
		break;
	case Elem_METAL:;
		if (Rnd_perchance(10)) {
			part->type = Elem_POWDER;
			part->charge = 0;
		}
		if (++ball->charge>=20) //hmm this is the same as for snow
			*newType = Elem_SEAWATER;
		break;
	case Elem_FUSE:;
		part->type = Elem_GUNPOWDER;
		part->charge = 0;
	}
#endif
}
