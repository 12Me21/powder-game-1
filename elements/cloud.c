break; case Elem_CLOUD:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(-0.01, -0.02);
	airvel.xy += p->vel.xy;
	airvel.xy *= 0.9;
	Part_blow(p, airvel);
	int dir = Random_int(4);
	Part* f = Part_pos2(p->pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
	if (f>=Part_0) {
		if (dir<3 && (ELEMENTS[f->type].state==State_POWDER || ELEMENTS[f->type].state==State_LIQUID)) {
			Part_swap(p,f);
		} else if (f->type==Elem_CLOUD) {
			p->vel.x += Random_2(-0.1, 0.1);
			p->vel.y += Random_2(-0.1, 0.1);
		} else if (f->type==Elem_WOOD || f->type==Elem_C4 || f->type==Elem_TORCH || f->type==Elem_VINE || f->type==Elem_FUSE) {
			p->type = Elem_WATER;
		} else if (f->type==Elem_ICE) {
			p->type = Elem_SNOW;
		} else if (f->type==Elem_METAL) {
			p->type = Elem_THUNDER;
		} else if (Part_checkPump(p, f, (int[]){2,1,3,0}[dir])) {
			p--;
		}
	} else if (f==Part_BLOCK)
		p->type = Elem_WATER;

#elif defined UPDATE_BALL
	if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_CLOUD, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch(part->type) {
	when(Elem_WOOD): case Elem_C4: case Elem_FUSE: case Elem_VINE: case Elem_TORCH:
		*newType = Elem_WATER;
	when(Elem_ICE):;
		*newType = Elem_ICE;
	when(Elem_METAL):;
		*newType = Elem_THUNDER;
	when(Elem_THUNDER): case Elem_LASER:
		return 1;
	}
#endif
}
