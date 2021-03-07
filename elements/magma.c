break; case Elem_MAGMA:
{
#ifdef UPDATE_PART
	Part_liquidUpdate(p, c, 0.1, 0,0.1, 0.01, 0.01,0.1, 0.9);

	Part* near = Part_rndNear5(p->pos);
	if (near>=Part_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_SEED: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			break;
			//magma+water/soapy = stone+steam
		case Elem_WATER: case Elem_SOAPY:
			if (Rnd_perchance(50))
				Part_KILL();
			p->type = Elem_STONE;
			near->type = Elem_STEAM;
			break;
			//melt stone
		case Elem_STONE:
			near->vel.x += Random_2(-0.1,0.1);
			if (Rnd_perchance(5))
				near->type = Elem_MAGMA;
			break;
			//magma+saltwater=stone+salt (no steam, note)
		case Elem_SALTWATER:
			if (Rnd_perchance(50))
				Part_KILL();
			p->type = Elem_STONE;
			near->type = Elem_SALT;
			break;
			//melt glass
		case Elem_GLASS:
			if (Rnd_perchance(50))
				near->type = Elem_MAGMA;
			//slowly melt mercury
			break;
		case Elem_MERCURY:
			if (Rnd_perchance(1))
				near->type = Elem_MAGMA;
		}
	}
	int g = Random_int(4);
	near = Part_pos2(p->pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[g]];
	//enter pump
	if (near>=Part_0 && Part_checkPump(p, near, g))
		Part_KILL();
#elif defined UPDATE_BALL
	//nothing
#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		if (++ball->meta>=20)
			*newType = Elem_METAL;
		part->type = Elem_STEAM;
		part->meta = 0;
	when(Elem_MAGMA):;
		ball->meta = 0;
	when(Elem_SOAPY):;
		if (++ball->meta>=20)
			*newType = Elem_GLASS;
		part->type = Elem_STEAM;
		part->meta = 0;
	when(Elem_SALTWATER):;
		if (++ball->meta>=20)
			*newType = Elem_STONE;
		part->type = Elem_STEAM;
		part->meta = 0;
	when(Elem_POWDER): case Elem_SEED: case Elem_WOOD: case Elem_GUNPOWDER: case Elem_SUPERBALL: case Elem_OIL: case Elem_C4: case Elem_NITRO: case Elem_ANT: case Elem_GAS: case Elem_VINE: case Elem_BIRD: case Elem_FUSE:
		part->type = Elem_FIRE;
		part->meta = 0;
	when(Elem_ICE): case Elem_SNOW:
		part->type = Elem_WATER;
		part->meta = 0;
	when(Elem_FIREWORKS):;
		if (part->meta>0 && part->meta<100) {
			part->vel.y -= 50;
			part->meta += 100;
		}
	}
#endif
}
