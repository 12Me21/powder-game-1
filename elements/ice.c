break; case Elem_ICE:
{
#ifdef UPDATE_PART
	if (Vec_fastDist(&c->vel) > 1 && Random_(100)<50)
		p->type = Elem_SNOW;
	Vector airvel = {0,0};
	Part_blow(p, &airvel);
	axis x = Random_int(9)-4;
	Part* g = Part_pos2(&p->pos)[Part_ofs(x, Random_int(9)-4)];
	if (g >= Part_0 && ELEMENTS[g->type].state == State_HOT)
		p->type = Elem_WATER;

#elif defined UPDATE_BALL
	double d = Vec_dist(&ball->vel);
	if (touched==Elem_THUNDER||touched==Elem_ACID||((touched==-1||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB)&&d>5)) {
		Ball_break(ball, 0, Elem_SNOW, 0, ball->vel.x, ball->vel.y, d);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		part->type = Elem_ICE;
		part->meta = 0;
	when(Elem_FIRE): case Elem_SPARK: case Elem_LASER: case Elem_TORCH:;
		if (++ball->meta>=20)
			*newType = Elem_WATER;
	when(Elem_ICE): case Elem_SNOW:
		ball->meta = 0;
	when(Elem_MAGMA):;
		*newType = Elem_WATER;
	when(Elem_THUNDER):;
		return 1;
	}
#endif
}
