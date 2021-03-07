break; case Elem_METAL:
{
#ifdef UPDATE_PART
	Part_toGrid(p);
	p->vel = (Point){0,0};
	
	Part* near = Part_rndNear(p->pos, 5);
	if (near>=Part_0) {
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
	when(Elem_SALTWATER):;
		Ball_break(ball, 1, Elem_POWDER, 0, 0, 0, 0);
	when(Elem_THUNDER):;
		Ball_break(ball, 2, Elem_METAL, 0, 0, 0, 0);
	when(Elem_LASER):;
		Ball_break(ball, 1, Elem_METAL, 0, 0, 0, 0);
	when(Elem_ACID):;
		Ball_break(ball, 0, Elem_METAL, 0, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->meta = 0;
	when(Elem_MAGMA):;
		if (++ball->meta>=20)
			*newType = Elem_MAGMA;
	when(Elem_METAL):;
		if (Part_limit1000() && ball->vel.x*ball->vel.x+ball->vel.y*ball->vel.y > 10) {
			int x = floor(ball->pos.x) + floor(Random_(5))-2;
			int y = floor(ball->pos.y) + floor(Random_(5))-2;
			if (Part_pos(x, y)[0]<=Part_BGFAN)
				Part_create(x, y, Elem_SPARK);
		}
	when(Elem_THUNDER): case Elem_LASER: case Elem_SPARK:
		return 1;
	}
#endif
}
