break; case Elem_POWDER:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (touched[ELEMENTS].state==State_LIQUID)
			Ball_break(ball, 0, Elem_POWDER, 0, Point(0.5*ball->vel.xy), 0.5);
		else if (touched[ELEMENTS].state==State_HOT)
			Ball_break(ball, 0, Elem_FIRE, 0, Point(0.5*ball->vel.xy), 0.5);
	}

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
