break; case Elem_POWDER:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (ELEMENTS[touched].state==State_LIQUID)
			Ball_break(i, 0, Elem_POWDER, 0, 0.5*i->vel.x, 0.5*i->vel.y, 0.5);
		else if (ELEMENTS[touched].state==State_HOT)
			Ball_break(i, 0, Elem_FIRE, 0, 0.5*i->vel.x, 0.5*i->vel.y, 0.5);
	}

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
