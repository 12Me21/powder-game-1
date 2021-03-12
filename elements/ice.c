break; case Elem_ICE:
{
#ifdef UPDATE_PART
	// if air velocity>1, 50% chance to turn into snow
	if (Vec_fastDist(c->vel)>1 && Rnd_perchance(50))
		p->type = Elem_SNOW;
	Part_toGrid(p);

	// pick a random particle within 9x9, melt self if it's hot
	Part* near = Part_rndNear(p->pos, 9);
	if (near>=Part_0 && near->type[ELEMENTS].state==State_HOT)
		p->type = Elem_WATER;

#elif defined UPDATE_BALL
	real d = Vec_dist(ball->vel);
	// break if touching thunder/acid, or
	// if touching block,wheel,stone,metal,bomb, with velocity>5
	if (touched==Elem_THUNDER||touched==Elem_ACID|| 
		((touched==Elem_BLOCK||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB)&&d>5))
		Ball_break(ball, 0, Elem_SNOW, 0, ball->vel.x, ball->vel.y, d);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		// turn water particles into ice
		part->type = Elem_ICE;
		part->meta = 0;
	when(Elem_FIRE): case Elem_SPARK: case Elem_LASER: case Elem_TORCH:;
		// melt after touching 20 of these type particles
		if (++ball->meta>=20)
			*newType = Elem_WATER;
	when(Elem_ICE): case Elem_SNOW:
		// reset melt counter
		ball->meta = 0;
	when(Elem_MAGMA):;
		// melt instantly
		*newType = Elem_WATER;
	when(Elem_THUNDER):;
		return 1;
	}
#endif
}
