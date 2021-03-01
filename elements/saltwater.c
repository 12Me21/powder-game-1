break; case Elem_SALTWATER:
{
#ifdef UPDATE_PART
	Part_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	Part* near = Part_pos3(&p->pos, x, y);
	if (near>=Part_0 &&(near->type==Elem_SEED||near->type==Elem_WOOD||near->type==Elem_METAL)) {
		near->type = Elem_POWDER;
		near->meta = 0;
	}
	int dir = Random_int(8)-4; //-4 to 3
	if (dir<0) dir=0; //0 to 3
	
	Part* g = Part_pos2(&p->pos)[(Offset[]){Part_ofs(0,-1),-1,1,Part_ofs(0,1)}[dir]];
	if (g>=Part_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = g->type;
		if (dir!=3 && ((ELEMENTS[type].state==State_POWDER && type!=Elem_STONE)||type==Elem_NITRO)) {
			if (Rnd_perchance(10))
				Part_swap(p, g);
			//freeze water
		} else if (type==Elem_VINE) {
			g->type = Elem_POWDER;
			g->meta = 0;
			//put water into pump
		} else if (Part_checkPump(p, g, (int[]){2,1,3,0}[dir]))
			p--;
	}

#elif defined UPDATE_BALL
	if (touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SALTWATER, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_WATER):;
		ball->meta = 0;
	when(Elem_FIRE):;
		if (++ball->meta>=20)
			*newType = Elem_SALT;
		Part_remove(part);
		return 1;
	when(Elem_WOOD): case Elem_SEED: case Elem_METAL: case Elem_VINE:
		part->type = Elem_POWDER;
		part->meta = 0;
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_SNOW):;
		if (++ball->meta>=20)
			*newType = Elem_ICE;
	when(Elem_MAGMA):;
		*newType = Elem_SALT;
	when(Elem_TORCH): case Elem_SPARK:
		if (++ball->meta>=20)
			*newType = Elem_SALT;
		Part_remove(part);
	when(Elem_THUNDER):;
		return 1;
	when(Elem_LASER):;
		if (++ball->meta>=20)
			*newType = Elem_SALT;
		return 1;
	when(Elem_SALT):;
		if (ball->meta++<20)
			Part_remove(part);
	when(Elem_FUSE):;
		part->type = Elem_GUNPOWDER;
		part->meta = 0;
	}
#endif
}
