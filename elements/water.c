break; case Elem_WATER:
{
#ifdef UPDATE_PART
	p->vel.x += 0.2*c->vel.x;
	p->vel.y += 0.2*c->vel.y;
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
		if (dir<7 && (ELEMENTS[g->type].state==State_POWDER && (g->type!=Elem_STONE||g->type==Elem_NITRO||g->type==Elem_SOAPY||g->type==Elem_SALTWATER))) {
			if (Random_(100)<10)
				Part_swap(p, g);
			//freeze water
		} else if (g->type==Elem_ICE) {
			if (Random_(100)<50)
				p->type = Elem_ICE;
			//put water into pump
		} else if (g->type==Elem_PUMP && !g->pumpType) {
			g->meta = 4|(dir<5?2:dir<6?1:dir<7?3:0);
			g->pumpType = Elem_WATER;
			Part_remove(p--);
		}
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
		if (Random_(100)<10) {
			part->type = Elem_POWDER;
			part->meta = 0;
		}
	when(Elem_SALT):;
		if (++ball->meta>=20) //hmm this is the same as for snow
			*newType = Elem_SALTWATER;
	when(Elem_FUSE):;
		part->type = Elem_GUNPOWDER;
		part->meta = 0;
	}
#endif
}
