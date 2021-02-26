break; case Elem_VIRUS:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	airvel.y += Random_2(0, 0.1);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
	if (p->meta==0) {
		int x = Random_int(3)-1;
		Part* f = Part_pos2(&p->pos)[Part_ofs(x, Random_int(3)-1)];
		if (f>=Part_0 && f->type!=Elem_VIRUS)
			p->meta = f->type;
	} else if (p->meta<=0x800) {
		int x = Random_int(3)-1;
		int y = Random_int(3)-1;
		Part* f = Part_pos2(&p->pos)[Part_ofs(x, y)];
		if (x&&y && f>=Part_0 && (f->type!=Elem_VIRUS || f->meta==0)) {
			f->type = Elem_VIRUS;
			f->meta = p->meta & 0xFF;
			f->pumpType = 0;
		}
		p->meta += 0x100;
	} else {
		p->meta += 0x100;
		if (p->meta>=0x8000) {
			p->type = p->meta&0xFF;
			p->meta = 0;
			p->vel = (Vector){0,0};
		}
	}

#elif defined UPDATE_BALL
	// nothing

#elif defined UPDATE_BALL_PART
	if (part->type>0) {
		if (ball->meta==0)
			ball->meta = part->type;
		else {
			part->type = ball->meta;
			part->meta = 0;
			part->pumpType = 0;
		}
	}
#endif
}
