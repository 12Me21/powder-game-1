break; case Elem_SOAPY:
{
#ifdef UPDATE_PART
	if (p->charge==1)
		Dot_KILL();
	Dot_liquidUpdate(p, c, 0.3, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = Random_int(8)-4;
	if (dir<0) dir=0;

	Dot* g = Dot_dirNear(p->pos,dir);
	if (g>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		switch (g->type) {
		when(Elem_ICE):;
			if (Rnd_perchance(50))
				p->type = Elem_ICE;
		when(Elem_OIL):;
			g->type = Elem_SOAPY;
			g->charge = p->charge = 1; //both particles promise to die
		when(Elem_FUSE):;
			if (!g->Cfuse.burning) {
				g->Cfuse.type = Elem_SOAPY;
				Dot_KILL();
			}
		when(Elem_PUMP):;
			if (Dot_checkPump(p,g,dir))
				Dot_KILL();
		otherwise:;
			int type = g->type;
			if ((ELEMENTS[type].state==State_POWDER && type!=Elem_STONE)||type==Elem_NITRO||type==Elem_SEAWATER)
				if (dir<3 && Rnd_perchance(10))
					Dot_swap(p, g);
		}
	}
	// if air vel > 2, turn into bubbles
	if (Vec_fastDist(p->vel)>2) {
		// find nearby soapy particles
		int f = 0;
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* near = *Dot_pos(x, y);
			if (near>=Dot_0 && near->type==Elem_SOAPY && near->charge==0) {
				near->charge = 1; //make them disappear next frame
				f++;
			}
		}
		Dot_doRadius(p->pos.x, p->pos.y, 4, func);
		// 
		f = atLeast(f, 5);
		f = atMost(f, Bubble_END - Bubble_next);
		if (f<5) break;
		// make bubble
		Point bb = {
			((int)between(p->pos.x, 8, WIDTH-8-1) & ~3) + 2,
			((int)between(p->pos.y, 8, HEIGHT-8-1) & ~3) + 2
		};
		Bubble_nextId();
		for (int i=0;i<f;i++) {
			Point offset = bb;
			offset.xy += 1.9*Vec_unit[(int)(512*i/f)].xy;
			Bubble_create(offset.x, offset.y);
		}
		Bubble_nextId();
		//
		Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA||touched==Elem_THUNDER||touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SOAPY, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_TORCH): case Elem_OIL: case Elem_SPARK:
		Dot_remove(part);
	when(Elem_MAGMA):; case Elem_THUNDER: case Elem_LASER:
		return 1;
	when(Elem_FUSE):;
		if (!part->Cfuse.burning)
			part->Cfuse.type = Elem_SOAPY;
	}
#endif
}
