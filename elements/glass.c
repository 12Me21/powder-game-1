break; case Elem_GLASS:
{
#ifdef UPDATE_PART
	if (p->meta==0) {
		if (Vec_fastDist(&p->vel)>1)
			p->meta = 1;
		else
			p->vel = (Vector){0,0};
		//breakystate, and the spreading of such things
	} else if (p->meta==1) {
		Vector airvel = p->vel;
		double v = Vec_fastNormalize(&airvel)*0.5;
		if (v<1) v=1;
		int b;
		// spread cracks
		for (b=1; b<6; b++) {
			Part* near = Part_at[(int)(p->pos.y+0.5+airvel.y*b)][(int)(p->pos.x+0.5+airvel.x*b)];
			if (near>=Part_0 && near->type==Elem_GLASS) {
				near->meta = 1;
				Vec_mul2(&near->vel, &p->vel, 0.98);
			} else
				break;
		}
		void nb(int x, int y) {
			Part* near = Part_at[(int)p->pos.y+y][(int)p->pos.x+x];
			if (near>=Part_0 && near->type==Elem_GLASS && near->meta==0) {
				near->meta = 1;
				int y = Random_int(512);
				Vec_mul2(&near->vel, Vec_unit(y), v);
			}
		}
		nb(1,0);
		nb(-1,0);
		nb(0,1);
		nb(0,-1);
		p->type = Elem_STONE;
		p->meta = 0;
	}
	Part_at[(int)p->pos.y][(int)p->pos.x] = p;
#endif
}
