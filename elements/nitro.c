break; case Elem_NITRO:
{
#ifdef UPDATE_PART
	Part_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = Random_int(8)-4;
	if (dir<0) dir=0;

	Part* g = Part_pos2(p->pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
	if (g>=Part_0) {
		//powders except stone
		if (dir<3 && (ELEMENTS[g->type].state==State_POWDER && (g->type!=Elem_STONE))) {
			if (Rnd_perchance(10))
				Part_swap(p, g);
		// fuse
		} else if (g->type==Elem_FUSE && !g->Cfuse.burning) {
			g->Cfuse.type = Elem_NITRO;
			Part_KILL();
		//put water into pump
		} else if (Part_checkPump(p,g,dir))
			Part_KILL();
	}
	if (Vec_fastDist(p->vel)<10) {
		Part* near = Part_rndNear(p->pos, 5);
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
	if (part->type==Elem_FUSE && !part->Cfuse.burning)
		part->Cfuse.type = Elem_NITRO;
#endif
}
