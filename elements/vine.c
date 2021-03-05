break; case Elem_VINE:
{
#ifdef UPDATE_PART
	Point airvel = p->vel;
	Vec_mul(&p->vel, 0.3);
	Part_blow(p, airvel);
	// todo check part limit

	inline void tryGrow(void) {
		if (Part_pos3(p->pos, 0, 1)<=Part_BGFAN && Part_pos3(p->pos, 0, 2)<=Part_BGFAN && Part_pos3(p->pos, -1, 1)<=Part_BGFAN && Part_pos3(p->pos, 1, 1)<=Part_BGFAN && Rnd_perchance(20)) {
			Part* f = Part_create(p->pos.x, p->pos.y+1, Elem_VINE);
			if (f)
				f->meta = 1;
		}
	}
	
	if (p->meta==0) {
		axis x = p->pos.x + Random_int(3)-1;
		axis y = p->pos.y + Random_int(2);
		Part* near = Part_at[y][x];
		if (near <= Part_BGFAN) {
			for (int i=0; i<8; i++) {
				near = Part_pos(x,y)[(Offset[]){1,-1,WIDTH,-WIDTH,WIDTH+1,WIDTH-1,-WIDTH+1,-WIDTH-1}[i]];
				if (near>=Part_0 && near->type!=Elem_VINE && near->type!=Elem_ANT) {
					if (Rnd_perchance(50))
						Part_create(x,y,Elem_VINE);
					break;
				}
			}
		}
		tryGrow();
	} else if (p->meta==1) {
		tryGrow();
		if (Rnd_perchance(4))
			p->meta = 2;
	}
#endif
}
