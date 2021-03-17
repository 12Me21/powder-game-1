break; case Elem_SPARK:
{
#ifdef UPDATE_PART
	Point airvel = Vec_mul2(c->vel, 0.05);
	p->vel.xy += airvel.xy;
	p->vel.y += 0.01;
	Dot** at = Dot_pos2(p->pos);
	if (at[1]>=Dot_WHEEL)
		p->vel.x -= Random_(0.5);
	if (at[-1]>=Dot_WHEEL)
		p->vel.x += Random_(0.5);
	if (at[Dot_ofs(0,1)]>=Dot_WHEEL)
		p->vel.y -= Random_(0.5);
	if (at[Dot_ofs(0,2)]>=Dot_WHEEL)
		p->vel.y -= Random_(0.5);
	if (at[Dot_ofs(0,-1)]>=Dot_WHEEL)
		p->vel.y += Random_(0.5);
	p->vel.xy *= 0.98;
	airvel = p->vel;
	Dot_blow(p, airvel);
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	Dot* near = Dot_pos3(p->pos, x, y);
	if (near>=Dot_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_ANT:
			near->type = Elem_FIRE;
		when(Elem_WATER): case Elem_SEAWATER: case Elem_SOAPY:
			Dot_remove(p--);
			goto SPARK_brk;
		when(Elem_SNOW):;
			near->type = Elem_WATER;
		}
	}
	if (Rnd_perchance(15)) {
		Dot_remove(p--);
		break;
	}
 SPARK_brk:;
#endif
}
