break; case Elem_CLOUD:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(-0.01, -0.02);
	airvel.xy += p->vel.xy;
	p->vel.xy *= 0.9;
	Dot_blow(p, airvel);

	int dir = Random_int(4);
	Dot* near = Dot_dirNear(p->pos, dir);
	if (near>=Dot_0) {
		if (dir<3 && (ELEMENTS[near->type].state==State_POWDER || ELEMENTS[near->type].state==State_LIQUID)) {
			Dot_swap(p,near);
		} else if (near->type==Elem_CLOUD) {
			p->vel.xy += Rnd_point(-0.1,0.1, -0.1,0.1).xy;
		} else if (near->type==Elem_WOOD || near->type==Elem_C4 || near->type==Elem_TORCH || near->type==Elem_VINE || near->type==Elem_FUSE) {
			p->type = Elem_WATER;
		} else if (near->type==Elem_ICE) {
			p->type = Elem_SNOW;
		} else if (near->type==Elem_METAL) {
			p->type = Elem_THUNDER;
		} else if (Dot_checkPump(p, near, dir)) {
			near->Cpump.type = Elem_WATER;
			Dot_KILL();
		}
	} else if (near==Dot_BLOCK)
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
