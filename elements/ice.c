break; case Elem_ICE:
{
#ifdef UPDATE_PART
	// if air velocity>1, 50% chance to turn into snow
	if (Vec_fastDist(c->vel)>1 && Rnd_perchance(50))
		p->type = Elem_SNOW;
	Dot_toGrid(p);

	// pick a random particle within 9x9, melt self if it's hot
	Dot* near = Dot_rndNear(p->pos, 9);
	if (near>=Dot_0 && near->type[ELEMENTS].state==State_HOT)
		p->type = Elem_WATER;

#elif defined UPDATE_BALL
	real vel = Vec_dist(ball->vel);
	// break if touching thunder/acid, or
	// if touching block,wheel,stone,metal,bomb, with velocity>5
	if (touched==Elem_THUNDER||touched==Elem_ACID|| 
		((touched==Elem_BLOCK||touched==-3||touched==Elem_STONE||touched==Elem_METAL||touched==Elem_BOMB)&&vel>5))
		Ball_break(ball, 0, Elem_SNOW, 0, ball->vel, vel);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		// turn water particles into ice
		part->type = Elem_ICE;
		part->charge = 0;
	when(Elem_FIRE): case Elem_SPARK: case Elem_LASER: case Elem_TORCH:;
		// melt after touching 20 of these type particles
		if (++ball->charge>=20)
			*newType = Elem_WATER;
	when(Elem_ICE): case Elem_SNOW:
		// reset melt counter
		ball->charge = 0;
	when(Elem_MAGMA):;
		// melt instantly
		*newType = Elem_WATER;
	when(Elem_THUNDER):;
		return 1;
	}
#endif
}
