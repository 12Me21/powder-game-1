break; case Elem_ANT:
{
#ifdef UPDATE_PART
	Dot** at = Dot_pos2(p->pos);
	Dot* below = at[Dot_ofs(0,1)];
	// charge=0: ant hasn't picked up an element yet
	if (p->meta==0 && below>=Dot_0) {
		int type = below->type;
		if (type==Elem_WOOD||type==Elem_ICE||type==Elem_C4||type==Elem_METAL||type==Elem_VINE||type==Elem_GLASS||type==Elem_FUSE||type==Elem_PUMP)
			p->Cant.holding = type;
	}
	
	Point airvel;
	if (p->meta==0) {
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
	
	if (p->meta==0 || !Dot_limit1000())
		break;
	Offset k = (Offset[]){1,Dot_ofs(0,1),-1,Dot_ofs(0,-1)}[p->Cant.dir];
	Dot* near = Dot_pos2(p->pos)[k];
	// if moving into an empty space
	if (near<=Dot_BGFAN) {
		p->Cant.dir++;
		// create a new ant
		Dot* new = Dot_create(p->pos.x+k%WIDTH, p->pos.y+k/WIDTH, Elem_ANT);
		if (new)
			new->meta = p->meta;
		// transform into carried type
		p->type = p->Cant.holding;
		p->meta=0;
	} else {
		// if moving into another particle
		if (near>=Dot_0) {
			if (near->type==p->Cant.holding)
				p->Cant.dir--;
			near->type = Elem_ANT;
			near->meta = p->meta;
			near->pumpType = 0;
			Dot_KILL();
		}
		p->Cant.dir++;
	}
#endif
}
