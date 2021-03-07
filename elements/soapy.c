break; case Elem_SOAPY:
{
#ifdef UPDATE_PART
	if (p->meta==1)
		Part_KILL();
	Part_liquidUpdate(p, c, 0.3, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = Random_int(8)-4;
	if (dir<0) dir=0;

	Part* g = Part_pos2(p->pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
	if (g>=Part_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		switch (g->type) {
		when(Elem_ICE):;
			if (Rnd_perchance(50))
				p->type = Elem_ICE;
		when(Elem_OIL):;
			g->type = Elem_SOAPY;
			g->meta = p->meta = 1; //both particles promise to die
		when(Elem_FUSE):;
			if (!g->Cfuse.burning) {
				g->Cfuse.type = Elem_SOAPY;
				Part_KILL();
			}
		when(Elem_PUMP):;
			if (Part_checkPump(p,g,dir))
				Part_KILL();
		otherwise:;
			int type = g->type;
			if ((ELEMENTS[type].state==State_POWDER && type!=Elem_STONE)||type==Elem_NITRO||type==Elem_SEAWATER)
				if (dir<3 && Rnd_perchance(10))
					Part_swap(p, g);
		}
	}
	if (Vec_fastDist(p->vel)>2) {
		int f = 0;
		void func(axis x, axis y, axis sx, axis sy) {
			Part* near = *Part_pos(x, y);
			if (near>=Part_0 && near->type==Elem_SOAPY && near->meta==0) {
				near->meta = 1;
				f++;
			}
		}
		Part_doRadius(p->pos.x, p->pos.y, 4, func);
		// todo: make sure f isn't > amount of free bubble nodes
		if (f<5) break;
		// todo: create bubble
		Part_KILL();
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA||touched==Elem_THUNDER||touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SOAPY, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_TORCH): case Elem_OIL: case Elem_SPARK:
		Part_remove(part);
	when(Elem_MAGMA):; case Elem_THUNDER: case Elem_LASER:
		return 1;
	when(Elem_FUSE):;
		if (!part->Cfuse.burning)
			part->Cfuse.type = Elem_SOAPY;
	}
#endif
}
