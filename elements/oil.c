break; case Elem_OIL:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = atLeast(Random_int(8)-4, 0);
	
	Dot* g = Dot_dirNear(p->pos, dir);
	if (g>=Dot_0) {
		//powders (except stone), water, nitro, saltwater
		if (dir<3 && ((ELEMENTS[g->type].state==State_POWDER && g->type!=Elem_STONE) || g->type==Elem_WATER || g->type==Elem_NITRO || g->type==Elem_SEAWATER)) {
			if (Rnd_perchance(10))
				Dot_swap(p, g);
		//burn
		} else if (ELEMENTS[g->type].state==State_HOT) {
			p->meta = 1;
		//oil is absorbed by FUSE
		} else if (g->type==Elem_FUSE && !g->Cfuse.burning) {
			g->Cfuse.type = Elem_OIL;
			Dot_KILL();
		//and PUMP
		} else if (Dot_checkPump(p,g,dir))
			Dot_KILL();
	}
	if (p->meta==1) {
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
	if (ELEMENTS[touched].state==State_HOT) {
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
			part->meta = Elem_OIL;
	}
#endif
}
