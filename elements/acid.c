break; case Elem_ACID:
{
#ifdef UPDATE_PART
	if (p->charge>=100)
		Dot_KILL();
	Dot_liquidUpdate(p, c, 0.2, 0,0.1, 0.01, 0.02,0.05, 0.9);
	// 1/8 chance each of 1,2,3; 5/8 chance of 0
	int dir = atLeast(Random_int(8)-4, 0);
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		int rate = ELEMENTS[near->type].dissolveRate;
		if (rate) {
			if (Random_(200) < 200-p->charge) {
				p->charge = clamp(p->charge+rate,0,100);
				// destroy the nearby element
				// by turning it into an acid particle that will be destroyed on the next frame
				near->type = Elem_ACID;
				near->charge = 100;
			}
		} else if (Dot_checkPump(p, near, dir))
			Dot_KILL();
	}

#elif defined UPDATE_BALL
	//none

#elif defined UPDATE_BALL_PART
	if (ELEMENTS[part->type].dissolveRate || part->type==Elem_CLONE)
		Dot_remove(part);
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return 1;
#endif
}
