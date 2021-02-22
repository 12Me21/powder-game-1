break; case Elem_GUNPOWDER:
{
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
}
