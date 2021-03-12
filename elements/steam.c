break; case Elem_STEAM:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	
	if (Rnd_perchance(10))
		Dot_KILL();

#elif defined UPDATE_BALL
	// if touch anything, break into that type
	if (touched>=0 && ELEMENTS[touched].state>0)
		Ball_break(i, 0, touched, 0, 0.5*ball->vel.x, 0.5*ball->vel.y, 0.5);

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
