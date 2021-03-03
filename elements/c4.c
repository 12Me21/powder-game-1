break; case Elem_C4:
{
#ifdef UPDATE_PART
	Part_blow(p, (Point){0,0});
	if (p->meta==0) {
		int x = p->pos.x+Random_int(3)-1;
		Part* near = *Part_pos(x, p->pos.y+Random_int(3)-1);
		if (near>=Part_0 && ELEMENTS[near->type].state==State_HOT)
			p->meta = 1;
	} else {
		//spread explodeystate
		int b;
		for (b=0; b<8; b++) {
			Part* near = Part_pos2(p->pos)[(axis[]){1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1}[b]];
			if (near >= Part_0 && near->type==Elem_C4)
				near->meta = 1;
		}
		void func(axis x, axis y, axis sx, axis sy) {
			Part* near = Part_at[y][x];
			if (near>=Part_0) {
				near->vel.x += 10*(x-sx);
				near->vel.y += 10*(y-sy);
			}
			if ((y&3)+(x&3)==0) {
				Block* cell = &Part_blocks[y>>2][x>>2];
				if (cell->block<=0) {
					if (x!=sx)
						cell->vel.x += 1/(x-sx);
					if (y!=sy)
						cell->vel.y += 1/(y-sy);
				}
			}
		}
		Part_doRadius((int)p->pos.x&0xFFF4, (int)p->pos.y&0xFFF4, 10, func); //fff4, really?
		Part_remove(p--);
		break;
	}
#elif defined UPDATE_BALL
	//todo
#elif defined UPDATE_BALL_PART
	//todo
#endif
}
