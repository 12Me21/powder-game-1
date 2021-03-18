break; case Elem_SNOW: //❄
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.08);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.7;
	Dot_blow(p, airvel);
	
	Dot* near = Dot_rndNear(p->pos, 3);
	if (near>=Dot_0) {
		Elem type = near->type;
		if (type == Elem_ICE)
			p->type = Elem_ICE;
		// melt on contact with elements except for:
		// wood, wheel, snow, clone, vine, cloud
		// wait how could the type ever be wheel?
		else if (type!=Elem_WOOD && type!=Elem_WHEEL && type!=Elem_SNOW && type!=Elem_SNOW && type!=Elem_CLONE && type!=Elem_VINE && type!=Elem_CLOUD)
			p->type = Elem_WATER;
	}
#endif
}
