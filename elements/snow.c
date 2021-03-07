break; case Elem_SNOW: //❄
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.08);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Part_blow(p, airvel);
	
	int x = p->pos.x + Random_int(3)-1;
	int y = p->pos.y + Random_int(3)-1;
	Part* g = Part_at[y][x];
	if (g>=Part_0) {
		if (g->type == Elem_ICE)
			p->type = Elem_ICE;
		// melt on contact with elements except for:
		// wood, wheel, snow, clone, vine, cloud
		// wait how could the type ever be wheel?
		else if (g->type!=Elem_WOOD && g->type!=Elem_WHEEL && g->type!=Elem_SNOW && g->type!=Elem_SNOW && g->type!=Elem_CLONE && g->type!=Elem_VINE && g->type!=Elem_CLOUD)
			p->type = Elem_WATER;
	}
#endif
}
