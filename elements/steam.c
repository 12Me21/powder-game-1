break; case Elem_STEAM:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	Vec_add(&airvel, p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, airvel);
	if (Random_(100)<10)
		Part_remove(p--);
#elif defined UPDATE_BALL
	// if touch anything, break into that type
	if (touched>=0 && ELEMENTS[touched].state>0)
		Ball_break(i, 0, touched, 0, 0.5*ball->vel.x, 0.5*ball->vel.y, 0.5);
#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
