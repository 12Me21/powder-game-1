break; case Elem_C4:
{
#ifdef UPDATE_PART
	Part_blow(p, &(Vector){0,0});
	if (p->meta==0) {
		int x = p->pos.x+Random_int(3)-1;
		Part* near = *Part_pos(x, p->pos.y+Random_int(3)-1);
		if (near>=Part_0 && ELEMENTS[near->type].state==State_HOT)
			p->meta = 1;
	} else {
		//spread explodeystate
		int b;
		for (b=0; b<8; b++) {
			Part* near = Part_pos2(&p->pos)[(axis[]){1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1}[b]];
			if (near >= Part_0 && near->type==Elem_C4)
				near->meta = 1;
		}
		b=10;
		int n = (int)p->pos.x & 0xFFF4;
		int r = (int)p->pos.y & 0xFFF4;
		int w = n-b;
		if (w<4) w=4;
		int c = r-b;
		if (c<4) c=4;
		int y = n+b;
		if (y>WIDTH-4-1) y=WIDTH-4-1;
		int z = r+b;
		if (z>HEIGHT-4-1) z=HEIGHT-4-1;
		int q;
		for (q=c;q<=z;q++) {
			for (c=w;c<=y;c++) {
				if ((c-n)*(c-n)+(q-r)*(q-r)<=b*b) {
					Part* near = Part_at[q][c];
					if (near>=Part_0) {
						near->vel.x += 10*(c-n);
						near->vel.y += 10*(q-r);
					}
					if ((q&3)+(c&3)==0) {
						Block* cell = &Part_blocks[q>>2][c>>2];
						if (cell->block<=0) {
							if (abs(c-n)>=1)
								cell->vel.x += 1/(c-n);
							if (abs(q-r)>=1)
								cell->vel.y += 1/(q-r);
						}
					}
				}
			}
		}
		Part_remove(p--);
		break;
	}
#endif
}
