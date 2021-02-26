break; case Elem_GUNPOWDER:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	airvel.y += Random_2(0.01, 0.2);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.8);
	Part_blow(p, &airvel);
	int x = p->pos.x+Random_int(5)-2;
	Part* g = Part_at[(int)p->pos.y+Random_int(5)-2][x];
	if (g<Part_0 || ELEMENTS[g->type].state != State_HOT)
		break;
	int b = 10;
	int n = (int)p->pos.x & 0xFFF4;
	int r = (int)p->pos.y & 0xFFF4;
	int w = n-b;
	if (w<4) w = 4;
	int cc = r-b;
	if (cc<4) cc = 4;
	int y = n+b;
	if (y>W+12-1) y=W+12-1;
	int z=r+b;
	if (z>H+12-1) z=H+12-1;
	int q;
	for (q=cc; q<=z; q++) {
		for (cc=w; cc<=y; cc++) {
			int dist=(cc-n)*(cc-n)+(q-r)*(q-r);
			if (dist<=b*b) {
				Part* g = Part_at[q][cc];
				if (g>=Part_0 && g->type != Elem_GUNPOWDER) {
					g->vel.x += 10*(cc-n);
					g->vel.y += 10*(q-r);
				}
				if ((q&3)+(cc&3)==0) {
					Block* cell = &Part_blocks[q>>2][cc>>2];
					if (cell->block<=0) {
						if (abs(cc-n)>=1)
							cell->vel.x += 10.0/(cc-n);
						if (abs(q-r)>=1)
							cell->vel.y += 10.0/(q-r);
					}
				}
			}
		}
	}
	p->type = Elem_FIRE;

#elif defined UPDATE_BALL
	if (touched<0) break;
	// explode when touching a hot element AND meta is 0
	if (ball->meta==0 && ELEMENTS[touched].state==State_HOT) {
		for (int i=0;i<37;i++) {
			Part* near = Part_pos2(&ball->pos)[neighbors[i].offset];
			if (near<=Part_BGFAN) {
				Part* e = Part_create((int)ball->pos.x+neighbors[i].breakX, (int)ball->pos.y+neighbors[i].breakY, Elem_FIRE);
				if (e>=Part_0) {
					double f = Random_(20);
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
	case Elem_WATER: case Elem_SOAPY: case Elem_SALTWATER:
		if (ball->meta<20)
			ball->meta++;
	when(Elem_FIRE): case Elem_MAGMA: case Elem_TORCH: case Elem_LASER: case Elem_SPARK:
		if (ball->meta>0)
			ball->meta--;
	}
#endif
}
