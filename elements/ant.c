break; case Elem_ANT:
{
#ifdef UPDATE_PART
	Dot** at = Dot_pos2(p->pos);
	Dot* below = Dot_pos3(p->pos,0,1);
	// charge=0: ant hasn't picked up an element yet
	if (p->charge==0 && below>=Dot_0) {
		int type = below->type;
		if (type==Elem_WOOD||type==Elem_ICE||type==Elem_C4||type==Elem_METAL||type==Elem_VINE||type==Elem_GLASS||type==Elem_FUSE||type==Elem_PUMP)
			p->Cant.holding = type;
	}
	
	Point airvel;
	if (p->charge==0) {
		airvel = c->vel;
		airvel.y += Random_2(0.01, 0.2);
		if (below!=Dot_EMPTY) {
			if (at[-1]==Dot_EMPTY)
				p->vel.x -= Random_2(0, 0.1);
			if (at[1]==Dot_EMPTY)
				p->vel.x += Random_2(0, 0.1);
		}
	} else {
		airvel = (Point){0,0};
	}
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.85;
	Dot_blow(p, airvel);
	
	if (p->charge==0 || !Dot_limit1000())
		break;
	const Offset DIRS[4] = {WIDTH,-1,-WIDTH,1};
	Offset k = DIRS[p->Cant.dir-1 & 3]; // rotating this so it lines up with pump/thunder dir table
	Dot* near = Dot_pos2(p->pos)[k];
	// if moving into an empty space
	if (near<=Dot_BGFAN) {
		p->Cant.dir++;
		// create a new ant
		Dot* new = Dot_create(p->pos.x+k%WIDTH, p->pos.y+k/WIDTH, Elem_ANT);
		if (new)
			new->charge = p->charge;
		// transform into carried type
		p->type = p->Cant.holding;
		p->charge=0;
	} else {
		// if moving into another particle
		if (near>=Dot_0) {
			if (near->type==p->Cant.holding)
				p->Cant.dir--;
			near->type = Elem_ANT;
			near->charge = p->charge;
			Dot_KILL();
		}
		p->Cant.dir++;
	}
#endif
}
