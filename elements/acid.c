break; case Elem_ACID:
{
#ifdef UPDATE_PART
	if (p->meta>=100)
		Part_KILL();
	Part_liquidUpdate(p, c, 0.2, 0,0.1, 0.01, 0.02,0.05, 0.9);
	int dir = Random_int(8)-4; //-4 to 3
	if (dir<0) dir=0; //0 to 3
	
	Part* g = Part_dirNear(p->pos, dir);
	if (g>=Part_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int rate = ELEMENTS[g->type].dissolveRate;
		if (rate) {
			if (Random_(200)<200-p->meta) {
				p->meta = clamp(p->meta+rate,0,100);
				g->type = Elem_ACID;
				g->meta = 100; //will die instantly next update
			}
		} else if (Part_checkPump(p, g, dir))
			Part_KILL();
	}

#elif defined UPDATE_BALL
	//none

#elif defined UPDATE_BALL_PART
	if (ELEMENTS[part->type].dissolveRate || part->type==Elem_CLONE)
		Part_remove(part);
	if (part->type==Elem_THUNDER || part->type==Elem_LASER)
		return 1;
#endif
}
