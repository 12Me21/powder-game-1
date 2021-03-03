break; case Elem_NITRO:
{
#ifdef UPDATE_PART
	Part_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
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
			if (Rnd_perchance(10))
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
	if (Vec_fastDist(p->vel)<10) {
		int x = Random_int(5)-2;
		int y = Random_int(5)-2;
		Part* near = Part_pos2(p->pos)[Part_ofs(x, y)];
		if (near<Part_0 || ELEMENTS[near->type].state != State_HOT)
			break;
	}
	void func(axis x, axis y, axis sx, axis sy) {
		Part* d = Part_pos(x, y)[0];
		if (d>=Part_0) {
			d->vel.x += 10*(x-sx);
			d->vel.y += 10*(y-sy);
		}
		if ((y&3)+(x&3)==0){
			Block* cell = &Part_blocks[y>>2][x>>2];
			if (cell->block<=0) {
				if (x!=sx)
					cell->vel.x += 10/(x-sx);
				if (y!=sy)
					cell->vel.y += 10/(y-sy);
			}
		}
	}
	Part_doRadius((int)p->pos.x&~3, (int)p->pos.y&~3, 10, func);
	p->type = Elem_FIRE;

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (ELEMENTS[touched].state==State_HOT) {
		void func(axis x, axis y, axis sx, axis sy) {
			Part* d = Part_pos(x, y)[0];
			if (d>=Part_0) {
				d->vel.x += 10*(x-sx);
				d->vel.y += 10*(y-sy);
			}
			if (d<=Part_BGFAN)
				Part_create(x,y,Elem_FIRE);
			if ((y&3)+(x&3)==0){
				Block* cell = &Part_blocks[y>>2][x>>2];
				if (cell->block<=0) {
					if (x!=sx)
						cell->vel.x += 100/(x-sx);
					if (y!=sy)
						cell->vel.y += 100/(y-sy);
				}
			}
		}
		Part_doRadius((int)ball->pos.x&~3, (int)ball->pos.y&~3, 10, func);
		ball->used = false;
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_NITRO, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_FUSE && part->meta<256)
		part->meta = Elem_NITRO;
#endif
}
