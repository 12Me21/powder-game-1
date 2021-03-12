break; case Elem_NITRO:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = Random_int(8)-4;
	if (dir<0) dir=0;

	Dot* g = Dot_pos2(p->pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
	if (g>=Dot_0) {
		//powders except stone
		if (dir<3 && (ELEMENTS[g->type].state==State_POWDER && (g->type!=Elem_STONE))) {
			if (Rnd_perchance(10))
				Dot_swap(p, g);
		// fuse
		} else if (g->type==Elem_FUSE && !g->Cfuse.burning) {
			g->Cfuse.type = Elem_NITRO;
			Dot_KILL();
		//put water into pump
		} else if (Dot_checkPump(p,g,dir))
			Dot_KILL();
	}
	if (Vec_fastDist(p->vel)<10) {
		Dot* near = Dot_rndNear(p->pos, 5);
		if (near<Dot_0 || ELEMENTS[near->type].state != State_HOT)
			break;
	}
	void func(axis x, axis y, axis sx, axis sy) {
		Dot* d = Dot_pos(x, y)[0];
		if (d>=Dot_0) {
			d->vel.x += 10*(x-sx);
			d->vel.y += 10*(y-sy);
		}
		if ((y&3)+(x&3)==0){
			Block* cell = &Dot_blocks[y>>2][x>>2];
			if (cell->block<=0) {
				if (x!=sx)
					cell->vel.x += 10/(x-sx);
				if (y!=sy)
					cell->vel.y += 10/(y-sy);
			}
		}
	}
	Dot_doRadius((int)p->pos.x&~3, (int)p->pos.y&~3, 10, func);
	p->type = Elem_FIRE;

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (ELEMENTS[touched].state==State_HOT) {
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* d = Dot_pos(x, y)[0];
			if (d>=Dot_0) {
				d->vel.x += 10*(x-sx);
				d->vel.y += 10*(y-sy);
			}
			if (d<=Dot_BGFAN)
				Dot_create(x,y,Elem_FIRE);
			if ((y&3)+(x&3)==0){
				Block* cell = &Dot_blocks[y>>2][x>>2];
				if (cell->block<=0) {
					if (x!=sx)
						cell->vel.x += 100/(x-sx);
					if (y!=sy)
						cell->vel.y += 100/(y-sy);
				}
			}
		}
		Dot_doRadius((int)ball->pos.x&~3, (int)ball->pos.y&~3, 10, func);
		ball->used = false;
	} else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_NITRO, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	if (part->type==Elem_FUSE && !part->Cfuse.burning)
		part->Cfuse.type = Elem_NITRO;
#endif
}
