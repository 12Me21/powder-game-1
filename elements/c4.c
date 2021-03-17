break; case Elem_C4:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	// note: we do not set velocity to 0 here
	
	if (p->charge==0) {
		Dot* near = Dot_rndNear(p->pos, 3);
		if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT)
			p->charge = 1;
	} else {
		//spread explodeystate
		for (int b=0; b<8; b++) {
			Dot* near = Dot_pos2(p->pos)[Dot_ofs8(b)];
			if (near >= Dot_0 && near->type==Elem_C4)
				near->charge = 1;
		}
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* near = Dot_at[y][x];
			if (near>=Dot_0) {
				near->vel.x += 10*(x-sx);
				near->vel.y += 10*(y-sy);
			}
			if ((y&3)+(x&3)==0) {
				Block* cell = &Blocks[y>>2][x>>2];
				if (cell->block<=0) {
					if (x!=sx)
						cell->vel.x += 1/(x-sx);
					if (y!=sy)
						cell->vel.y += 1/(y-sy);
				}
			}
		}
		Dot_doRadius((int)p->pos.x&0xFFF4, (int)p->pos.y&0xFFF4, 10, func); //fff4, really?
		Dot_KILL();
	}

#elif defined UPDATE_BALL
	if (touched<0) break;
	if (ELEMENTS[touched].state==State_HOT) {
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* d = Dot_pos(x, y)[0];
			if (d>=Dot_0) {
				d->vel.x += 10*(x-sx);
				d->vel.y += 10*(y-sy);
			}
			if ((y&3)+(x&3)==0){
				Block* cell = &Blocks[y>>2][x>>2];
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
	//none
#endif
}
