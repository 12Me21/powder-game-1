break; case Elem_C4:
{
#ifdef UPDATE_PART
	Part_blow(p, (Point){0,0});
	
	if (p->meta==0) {
		Part* near = Part_rndNear(p->pos, 3);
		if (near>=Part_0 && near->type[ELEMENTS].state==State_HOT)
			p->meta = 1;
	} else {
		//spread explodeystate
		for (int b=0; b<8; b++) {
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
		Part_KILL();
	}

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (ELEMENTS[touched].state==State_HOT) {
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
	//none
#endif
}
