break; case Elem_SALT:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.75;
	Dot_blow(p, airvel);
	
	Dot* near = Dot_rndNear(p->pos, 3);
	if (near>=Dot_0) {
		if (near->type==Elem_WATER) {
			near->type = Elem_SEAWATER;
			near->charge = 0;
			Dot_KILL();
		} else if (near->type==Elem_MAGMA && Rnd_perchance(50)) {
			Dot_KILL();
		}
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA || touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SALT, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_WATER:
		*newType = Elem_SEAWATER;
	when(Elem_MAGMA): case Elem_THUNDER:
		return 1;
	}
#endif
}
