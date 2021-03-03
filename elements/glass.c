break; case Elem_GLASS:
{
#ifdef UPDATE_PART
	if (p->meta==0) {
		if (Vec_fastDist(p->vel)>1)
			p->meta = 1;
		else
			p->vel = (Point){0,0};
		//breakystate, and the spreading of such things
	} else if (p->meta==1) {
		Point airvel = p->vel;
		real v = Vec_fastNormalize(&airvel)*0.5;
		if (v<1) v=1;
		int b;
		// spread cracks
		for (b=1; b<6; b++) {
			Part* near = Part_pos(p->pos.x+0.5+airvel.x*b, p->pos.y+0.5+airvel.y*b)[0];
			if (near>=Part_0 && near->type==Elem_GLASS) {
				near->meta = 1;
				near->vel = Vec_mul2(p->vel, 0.98);
			} else
				break;
		}
		void nb(int x, int y) {
			Part* near = Part_pos2(p->pos)[Part_ofs(x,y)];
			if (near>=Part_0 && near->type==Elem_GLASS && near->meta==0) {
				near->meta = 1;
				int y = Random_int(512);
				near->vel = Vec_mul2(Vec_unit(y), v);
			}
		}
		nb(1,0);
		nb(-1,0);
		nb(0,1);
		nb(0,-1);
		p->type = Elem_STONE;
		p->meta = 0;
	}
	*Part_pos2(p->pos) = p;
#elif defined UPDATE_BALL
	real dist = Vec_dist(vel);
	if (dist>5 && (touched==-1||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB))
		Ball_break(ball, 0, Elem_STONE, 0, 0, 0, 0.1*d);
	else if (touched==Elem_THUNDER)
		Ball_break(ball, 1, Elem_GLASS, 0, 0, 0, 0);
	else if (touched==Elem_LASER)
		Ball_break(ball, 2, Elem_GLASS, 0, 0, 0, 0);
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_GLASS, 0, 0, 0, 0);
#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->meta = 0;
	when(Elem_MAGMA):;
		if (++ball->meta>=20)
			*newType = Elem_MAGMA;
	when(Elem_THUNDER): case Elem_LASER:;
		return 1;
	}
#endif
}
