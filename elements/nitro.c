break; case Elem_NITRO:
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
		//powders except stone
		if (dir<7 && (ELEMENTS[g->type].state==State_POWDER && (g->type!=Elem_STONE))) {
			if (Random_(100)<10)
				Part_swap(p, g);
		// fuse
		} else if (g->type==Elem_FUSE && g->meta<256) {
			g->meta = Elem_NITRO;
			Part_remove(p--);
		//put water into pump
		} else if (g->type==Elem_PUMP && !g->pumpType) {
			g->meta = 4|(dir<5?2:dir<6?1:dir<7?3:0);
			g->pumpType = Elem_NITRO;
			Part_remove(p--);
		}
	}
	if (Vec_fastDist(&p->vel)<10) {
		int x = Random_int(5)-2;
		int y = Random_int(5)-2;
		Part* near = Part_pos2(&p->pos)[Part_ofs(x, y)];
		if (near<Part_0 || ELEMENTS[near->type].state != State_HOT)
			break;
	}
	int f=10;
	int gg=(int)p->pos.x&0xFFFC;
	int q=(int)p->pos.y&0xFFFC;
	int n=gg-f;
	if (n<4) n=4;
	int z=q-f;
	if (z<4) z=4;
	int v=gg+f;
	if (v>WIDTH-4-1) v=WIDTH-4-1;
	int r=q+f;
	if (r>H+12-1) r = H+12-1;
	for (int b=z;b<=r;b++)
		for (int e=n;e<=v;e++) {
			if ((e-gg)*(e-gg)+(b-q)*(b-q)<=f*f) {
				Part* d = Part_pos(e, b)[0];
				if (d>=Part_0) {
					d->vel.x += 10*(e-gg);
					d->vel.y += 10*(b-q);
				}
				if ((b&3)+(e&3)==0){
					Block* cell = &Part_blocks[b>>2][e>>2];
					if (cell->block<=0) {
						if (abs(e-gg)>=1)
							cell->vel.x += 10/(e-gg);
						if (abs(b-q)>=1)
							cell->vel.y += 10/(b-q);
					}
				}
			}
		}
	p->type = Elem_FIRE;

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (ELEMENTS[touched].state==State_HOT) {
		int f=10;
		int g=(int)ball->pos.x&0xFFFC;
		int q=(int)ball->pos.x&0xFFFC;
		int n=g-f;
		if (n<4) n=4;
		int z=q-f;
		if (z<4) z=4;
		int v=g+f;
		if (v>WIDTH-4-1) v=WIDTH-4-1;
		int r=q+f;
		if (r>H+12-1) v = H+12-1;
		for (int b=z;b<=r;b++)
			for (int e=n;e<=v;e++) {
				if ((e-g)*(e-g)+(b-q)*(b-q)<=f*f) {
					Part* d = Part_pos(e, b)[0];
					if (d>=Part_0) {
						d->vel.x += 10*(e-g);
						d->vel.y += 10*(b-q);
					}
					if (d<=Part_BGFAN)
						Part_create(e,b,Elem_FIRE);
					if ((b&3)+(e&3)==0){
						Block* cell = &Part_blocks[b>>2][e>>2];
						if (cell->block<=0) {
							if (abs(e-g)>=1)
								cell->vel.x += 100/(e-g);
							if (abs(b-q)>=1)
								cell->vel.y += 100/(b-q);
						}
					}
				}
			}
		ball->used = false;
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_NITRO, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_FUSE && part->meta<256)
		part->meta = Elem_NITRO;
#endif
}
