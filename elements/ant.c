break; case Elem_ANT:
{
#ifdef UPDATE_PART
	Part** at = Part_pos2(&p->pos);
	Part* below = at[Part_ofs(0,1)];
	if (p->meta==0 && below>=Part_0) {
		int type = below->type;
		if (type==Elem_WOOD||type==Elem_ICE||type==Elem_C4||type==Elem_METAL||type==Elem_VINE||type==Elem_GLASS||type==Elem_FUSE||type==Elem_PUMP)
			p->meta = type<<2;
	}
	Vector airvel;
	if (p->meta==0) {
		airvel = c->vel;
		airvel.y += Random_2(0.01, 0.2);
		if (below!=Part_EMPTY) {
			if (at[-1]==Part_EMPTY)
				p->vel.x -= Random_2(0, 0.1);
			if (at[1]==Part_EMPTY)
				p->vel.x += Random_2(0, 0.1);
		}
	} else {
		airvel = (Vector){0,0};
	}
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.85);
	Part_blow(p, &airvel);
	//todo check dot limit
	if (p->meta==0)
		break;
	int g = p->meta&0b11;
	Offset k = (Offset[]){1,Part_ofs(0,1),-1,Part_ofs(0,-1)}[g];
	Part* near = Part_pos2(&p->pos)[k];
	if (near<=Part_BGFAN) {
		p->meta = (p->meta&0xFFFFFC)|((g+1)&0b11);
		Part* new = Part_create(p->pos.x+k%WIDTH, p->pos.y+k/WIDTH, Elem_ANT);
		if (new)
			new->meta = p->meta;
		p->type = p->meta>>2;
		p->meta=0;
	} else {
		if (near>=Part_0) {
			if (near->type==p->meta>>2)
				p->meta = (p->meta&0xFFFFFC)|((g-1)&0b11);
			near->type = p->type;
			near->meta = p->meta;
			near->pumpType = 0;
			Part_remove(p--);
			break;
		}
		p->meta = (p->meta&0xFFFFFC)|((g+1)&0b11);
	}
#endif
}
