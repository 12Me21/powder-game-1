break; case Elem_VINE:
{
#ifdef UPDATE_PART
	Point airvel = p->vel;
	p->vel.xy *= 0.3;
	Dot_blow(p, airvel);
	// todo check part limit

	inline void tryGrow(void) {
		if (Dot_pos3(p->pos, 0, 1)<=Dot_BGFAN && Dot_pos3(p->pos, 0, 2)<=Dot_BGFAN && Dot_pos3(p->pos, -1, 1)<=Dot_BGFAN && Dot_pos3(p->pos, 1, 1)<=Dot_BGFAN && Rnd_perchance(20)) {
			Dot* f = Dot_create(p->pos.x, p->pos.y+1, Elem_VINE);
			if (f)
				f->charge = 1;
		}
	}
	
	if (p->charge==0) {
		axis x = p->pos.x + Random_int(3)-1;
		axis y = p->pos.y + Random_int(2);
		Dot* near = Dot_at[y][x];
		if (near <= Dot_BGFAN) {
			for (int i=0; i<8; i++) {
				near = Dot_pos(x,y)[Dot_ofs8(i)];
				if (near>=Dot_0 && near->type!=Elem_VINE && near->type!=Elem_ANT) {
					if (Rnd_perchance(50))
						Dot_create(x,y,Elem_VINE);
					break;
				}
			}
		}
		tryGrow();
	} else if (p->charge==1) {
		tryGrow();
		if (Rnd_perchance(4))
			p->charge = 2;
	}
#endif
}
