break; case Elem_GUNPOWDER:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.2);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.8;
	Dot_blow(p, airvel);
	
	Dot* g = Dot_rndNear(p->pos,5);
	if (g<Dot_0 || ELEMENTS[g->type].state != State_HOT)
		break;
	void func(axis x, axis y, axis sx, axis sy) {
		Dot* g = Dot_at[y][x];
		if (g>=Dot_0 && g->type != Elem_GUNPOWDER) {
			g->vel.x += 10*(x-sx);
			g->vel.y += 10*(y-sy);
		}
		if ((y&3)+(x&3)==0) {
			Block* cell = &Dot_blocks[y>>2][x>>2];
			if (cell->block<=0) {
				if (x!=sx)
					cell->vel.x += 10.0/(x-sx);
				if (y!=sy)
					cell->vel.y += 10.0/(y-sy);
			}
		}
	}
	Dot_doRadius((int)p->pos.x & 0xFFF4, (int)p->pos.y & 0xFFF4, 10, func);
	p->type = Elem_FIRE;

#elif defined UPDATE_BALL
	if (touched<0) break;
	// explode when touching a hot element AND meta is 0
	if (ball->meta==0 && ELEMENTS[touched].state==State_HOT) {
		for (int i=0;i<37;i++) {
			Dot* near = Dot_pos2(ball->pos)[neighbors[i].offset];
			if (near<=Dot_BGFAN) {
				Dot* e = Dot_create((int)ball->pos.x+neighbors[i].breakX, (int)ball->pos.y+neighbors[i].breakY, Elem_FIRE);
				if (e>=Dot_0) {
					real f = Random_(20);
					e->vel.x += ball->vel.x*f+neighbors[i].breakVel.x*f/2;
					e->vel.y += ball->vel.y*f+neighbors[i].breakVel.y*f/2;
					e->meta = 2;
				}
			}
		}
		ball->used = false;
	// destroyed by acid
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_GUNPOWDER, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	// meta is increased by water types and decreased by some hot elements
	switch (part->type) {
	case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER:
		if (ball->meta<20)
			ball->meta++;
	when(Elem_FIRE): case Elem_MAGMA: case Elem_TORCH: case Elem_LASER: case Elem_SPARK:
		if (ball->meta>0)
			ball->meta--;
	}
#endif
}
