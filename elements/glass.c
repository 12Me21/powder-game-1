break; case Elem_GLASS:
{
#ifdef UPDATE_PART
	// normal
	if (p->charge==0) {
		if (Vec_fastDist(p->vel)>1)
			p->charge = 1;
		else
			p->vel = (Point){0,0};
	// charge=1: breaking
	} else if (p->charge==1) {
		Point airvel = p->vel;
		real mag = atLeast(Vec_fastNormalize(&airvel)*0.5, 1);
		// spread cracks
		for (int b=1; b<6; b++) {
			Dot* near = *Dot_pos(
				p->pos.x+0.5+airvel.x*b,
				p->pos.y+0.5+airvel.y*b
			);
			if (near>=Dot_0 && near->type==Elem_GLASS) {
				near->charge = 1;
				near->vel.xy = p->vel.xy*0.98;
			} else
				break;
		}
		void nb(int x, int y) {
			Dot* near = Dot_pos3(p->pos, x, y);
			if (near>=Dot_0 && near->type==Elem_GLASS && near->charge==0) {
				near->charge = 1;
				near->vel.xy = Vec_unit[Random_int(512)].xy * mag;
			}
		}
		nb(1,0);
		nb(-1,0);
		nb(0,1);
		nb(0,-1);
		p->type = Elem_STONE;
		p->charge = 0;
	}
	Dot_toGrid(p);

#elif defined UPDATE_BALL
	real dist = Vec_dist(vel);
	if (dist>5 && (touched==-1||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB))
		Ball_break(ball, 0, Elem_STONE, 0, Point(0), 0.1*adv);//mmm
	else if (touched==Elem_THUNDER)
		Ball_break(ball, 1, Elem_GLASS, 0, Point(0), 0);
	else if (touched==Elem_LASER)
		Ball_break(ball, 2, Elem_GLASS, 0, Point(0), 0);
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_GLASS, 0, Point(0), 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->charge = 0;
	when(Elem_MAGMA):;
		if (++ball->charge>=20)
			*newType = Elem_MAGMA;
	when(Elem_THUNDER): case Elem_LASER:;
		return 1;
	}
#endif
}
