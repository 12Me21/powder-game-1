break; case Elem_SOAPY:
{
#ifdef UPDATE_PART
	if (p->meta==1) {
		Part_remove(p--);
		break;
	}
	p->vel.x += 0.3*c->vel.x;
	p->vel.y += 0.3*c->vel.y;
	if (Part_at[(int)p->pos.y+1][(int)p->pos.x] != Part_EMPTY) {
		if (Part_at[(int)p->pos.y][(int)p->pos.x-1] == Part_EMPTY)
			p->vel.x -= Random_2(0.1, 0.2);
		if (Part_at[(int)p->pos.y][(int)p->pos.x+1] == Part_EMPTY)
			p->vel.x += Random_2(0.1, 0.2);
	}
	p->vel.x += Random_2(-0.01, 0.01);
	p->vel.y += Random_2(0.01, 0.05);
	Vec_mul(&p->vel, 0.9);
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Part_blow(p, &airvel);
	int dir = Random_int(8);
		
	Part* g;
	if (dir<5)
		g = Part_at[(int)p->pos.y-1][(int)p->pos.x];
	else if (dir<6)
		g = Part_at[(int)p->pos.y][(int)p->pos.x-1];
	else if (dir<7)
		g = Part_at[(int)p->pos.y][(int)p->pos.x+1];
	else
		g = Part_at[(int)p->pos.y+1][(int)p->pos.x];
	if (g>=Part_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		switch (g->type) {
		when(Elem_ICE):;
			if (Random_(100)<50)
				p->type = Elem_ICE;
		when(Elem_OIL):;
			g->type = Elem_SOAPY;
			g->meta = p->meta = 1; //both particles promise to die
		when(Elem_FUSE):;
			if (g->meta<256) {
				g->meta = Elem_SOAPY;
				Part_remove(p--);
				break;
			}
		when(Elem_PUMP):;
			if (g->pumpType==0) {
				g->meta = 0b100|(dir<5?0b10:dir<6?0b01:dir<7?0b11:0b00);
				g->pumpType = Elem_SOAPY;
				Part_remove(p--);
				break;
			}
		otherwise:;
			int type = g->type;
			if ((ELEMENTS[type].state==State_POWDER && type!=Elem_STONE)||type==Elem_NITRO||type==Elem_SALTWATER)
				if (dir<7 && Random_(100)<10)
					Part_swap(p, g);
		}
	}
	if (Vec_fastDist(&p->vel)>2) {
		int f = 0;
		int range = 4;
		int px = p->pos.x;
		int py = p->pos.y;
		int xs=px-range;
		if (xs<4) xs=4;
		int ys=py-range;
		if (ys<4) ys=4;
		int xe=px+range;
		if (xe>WIDTH-4-1) xe=WIDTH-4-1;
		int ye=py+range;
		if (ye>H+12-1) ye=H+12-1;
		for (int y=ys;y<=ye;y++) {
			for (int x=xs;x<=xe;x++) {
				if ((x-px)*(x-px)+(y-py)*(y-py)>range*range) continue;
				Part* near = Part_pos(x, y)[0];
				if (near>=Part_0 && near->type==Elem_SOAPY && near->meta==0) {
					near->meta = 1;
					f++;
				}
			}
		}
		// todo: make sure f isn't > amount of free bubble nodes
		if (f<5) break;
		// todo: create bubble
		Part_remove(p--);
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
		if (part->meta<256)
			part->meta = Elem_SOAPY;
	}
#endif
}
