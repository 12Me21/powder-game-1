break; case Elem_WATER:
{
#ifdef UPDATE_PART
	Part_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = Random_int(8)-4; //-4 to 3
	if (dir<0) dir=0; //0 to 3
	
	Part* g = Part_dirNear(p->pos, dir);
	if (g>=Part_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = g->type;
		if (dir<3 && ((type[ELEMENTS].state==State_POWDER && type!=Elem_STONE)||type==Elem_NITRO||type==Elem_SOAPY||type==Elem_SEAWATER)) {
			if (Rnd_perchance(10))
				Part_swap(p, g);
			//freeze water
		} else if (type==Elem_ICE) {
			if (Rnd_perchance(50))
				p->type = Elem_ICE;
			//put water into pump
		} else if (Part_checkPump(p, g, dir))
			Part_KILL();
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA || touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_WATER, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_FIRE):;
		Part_remove(part);
		return 1;
	when(Elem_WOOD):;
		part->type = Elem_SEED;
		part->meta = 0;
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_SNOW):;
		if (++ball->meta>=20)
			*newType = Elem_ICE;
	when(Elem_MAGMA):; case Elem_THUNDER: case Elem_LASER:
		return 1;
	when(Elem_TORCH):;
		Part_remove(part);
	when(Elem_METAL):;
		if (Rnd_perchance(10)) {
			part->type = Elem_POWDER;
			part->meta = 0;
		}
	when(Elem_SALT):;
		if (++ball->meta>=20) //hmm this is the same as for snow
			*newType = Elem_SEAWATER;
	when(Elem_FUSE):;
		part->type = Elem_GUNPOWDER;
		part->meta = 0;
	}
#endif
}
