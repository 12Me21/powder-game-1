break; case Elem_OIL:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	// 0 0 0 0 0 1 2 3
	int dir = atLeast(Random_int(8)-4, 0);
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		Elem type = near->type;
		//powders (except stone), water, nitro, saltwater
		if (dir<3 && ((type[ELEMENTS].state==State_POWDER && type!=Elem_STONE) || type==Elem_WATER || type==Elem_NITRO || type==Elem_SEAWATER)) {
			if (Rnd_perchance(10))
				Dot_swap(p, near);
		//burn
		} else if (type[ELEMENTS].state==State_HOT) {
			p->charge = 1;
		//oil is absorbed by FUSE
		} else if (type==Elem_FUSE && !near->Cfuse.burning) {
			near->Cfuse.type = Elem_OIL;
			Dot_KILL();
		//and PUMP
		} else if (Dot_checkPump(p,near,dir))
			Dot_KILL();
	}
	// burning
	if (p->charge==1) {
		int x = p->pos.x+Random_int(3)-1;
		int y = p->pos.y+Random_int(3)-1;
		Dot* near = Dot_at[y][x];
		if (near<=Dot_BGFAN)
			Dot_create(x, y, Elem_FIRE);
		if (Rnd_perchance(10))
			Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (touched[ELEMENTS].state==State_HOT) {
		for (int i=9;i<21;i++) {
			Dot* near = Dot_pos2(ball->pos)[neighbors[i].offset];
			if (near<=Dot_BGFAN && Rnd_perchance(50))
				Dot_create((int)ball->pos.x+neighbors[i].breakX, (int)ball->pos.y+neighbors[i].breakY, Elem_FIRE);
		}
		if (Rnd_perchance(1))
			Ball_break(ball, 0, Elem_OIL, 0, 0, 0, 0);
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_OIL, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_MAGMA): case Elem_THUNDER: case Elem_LASER:
		return 1;
	when(Elem_SOAPY):;
		Dot_remove(part);
	when(Elem_FUSE):;
		if (!part->Cfuse.burning)
			part->charge = Elem_OIL;
	}
#endif
}
