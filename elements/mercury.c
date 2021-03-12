break; case Elem_MERCURY:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	int dir = atMost(Random_int(8), 3);
	
	Dot* g = Dot_dirNear(p->pos, dir);
	if (g>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = g->type;
		if (dir>0 && (ELEMENTS[type].state==State_POWDER||(ELEMENTS[type].state==State_LIQUID&&type!=Elem_MERCURY))) {
			Dot_swap(p, g);
			//freeze water
		} else if (Dot_checkPump(p, g, dir))
			Dot_KILL();
	}
#endif
}
