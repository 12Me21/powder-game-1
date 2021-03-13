break; case Elem_ACID:
{
#ifdef UPDATE_PART
	if (p->charge>=100)
		Dot_KILL();
	Dot_liquidUpdate(p, c, 0.2, 0,0.1, 0.01, 0.02,0.05, 0.9);
	int dir = atLeast(Random_int(8)-4, 0); //0 to 3
	
	Dot* g = Dot_dirNear(p->pos, dir);
	if (g>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int rate = ELEMENTS[g->type].dissolveRate;
		if (rate) {
			if (Random_(200)<200-p->charge) {
				p->charge = clamp(p->charge+rate,0,100);
				g->type = Elem_ACID;
				g->charge = 100; //will die instantly next update
			}
		} else if (Dot_checkPump(p, g, dir))
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
