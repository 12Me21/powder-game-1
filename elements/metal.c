break; case Elem_METAL:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	p->vel = (Point){0,0};
	
	Dot* near = Dot_rndNear(p->pos, 5);
	if (near>=Dot_0) {
		switch (near->type) {
		when(Elem_WATER):;
			if (Rnd_perchance(2))
				p->type = Elem_POWDER;
		when(Elem_MAGMA):;
			if (Rnd_perchance(2))
				p->type = Elem_MAGMA;
		}
	}

#elif defined UPDATE_BALL
	switch (touched) {
	when(Elem_SEAWATER):;
		Ball_break(ball, 1, Elem_POWDER, 0, Point(0), 0);
	when(Elem_THUNDER):;
		Ball_break(ball, 2, Elem_METAL, 0, Point(0), 0);
	when(Elem_LASER):;
		Ball_break(ball, 1, Elem_METAL, 0, Point(0), 0);
	when(Elem_ACID):;
		Ball_break(ball, 0, Elem_METAL, 0, Point(0), 0);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->charge = 0;
	when(Elem_MAGMA):;
		if (++ball->charge>=20)
			*newType = Elem_MAGMA;
	when(Elem_METAL):;
		if (Dot_limit1000() && ball->vel.x*ball->vel.x+ball->vel.y*ball->vel.y > 10) {
			axis x = (int)ball->pos.x + Random_int(5)-2;
			axis y = (int)ball->pos.y + Random_int(5)-2;
			if (*Dot_pos(x,y)<=Dot_BGFAN)
				Dot_create(x,y, Elem_SPARK);
		}
	when(Elem_THUNDER): case Elem_LASER: case Elem_SPARK:
		return 1;
	}
#endif
}
