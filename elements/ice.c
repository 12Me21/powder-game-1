break; case Elem_ICE:
{
#ifdef UPDATE_PART
	if (Vec_fastDist(c->vel) > 1 && Rnd_perchance(50))
		p->type = Elem_SNOW;
	Part_toGrid(p);
	
	Part* near = Part_rndNear(p->pos, 9);
	if (near>=Part_0 && near->type[ELEMENTS].state==State_HOT)
		p->type = Elem_WATER;

#elif defined UPDATE_BALL
	real d = Vec_dist(ball->vel);
	// break immediately if touching thunder/acid
	// in other cases, break if velocity is >5
	if (touched==Elem_THUNDER||touched==Elem_ACID|| 
		((touched==-1||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB)&&d>5))
		Ball_break(ball, 0, Elem_SNOW, 0, ball->vel.x, ball->vel.y, d);

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
