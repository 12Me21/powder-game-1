break; case Elem_MERCURY:
{
#ifdef UPDATE_PART
	Dot_liquidUpdate(p, c, 0.2, 0.1,0.2, 0.01, 0.01,0.05, 0.9);
	// 0 1 2 3 3 3 3 3
	int dir = atMost(Random_int(8), 3);
	
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		//solids (except stone),nitro,soapy, and saltwater, diffuse through water
		int type = near->type;
		if (dir>0 && (ELEMENTS[type].state==State_POWDER||(ELEMENTS[type].state==State_LIQUID&&type!=Elem_MERCURY))) {
			Dot_swap(p, near);
			//freeze water
		} else if (Dot_checkPump(p, near, dir))
			Dot_KILL();
	}
#endif
}
