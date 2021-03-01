break; case Elem_SPARK:
{
#ifdef UPDATE_PART
	Vector airvel;
	Vec_mul2(&airvel, &c->vel, 0.05);
	Vec_add(&p->vel, &airvel);
	p->vel.y += 0.01;
	Part** at = Part_pos2(&p->pos);
	if (at[1]>=Part_WHEEL)
		p->vel.x -= Random_(0.5);
	if (at[-1]>=Part_WHEEL)
		p->vel.x += Random_(0.5);
	if (at[Part_ofs(0,1)]>=Part_WHEEL)
		p->vel.y -= Random_(0.5);
	if (at[Part_ofs(0,2)]>=Part_WHEEL)
		p->vel.y -= Random_(0.5);
	if (at[Part_ofs(0,-1)]>=Part_WHEEL)
		p->vel.y += Random_(0.5);
	Vec_mul(&p->vel, 0.98);
	airvel = p->vel;
	Part_blow(p, &airvel);
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	Part* near = Part_pos3(&p->pos, x, y);
	if (near>=Part_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_ANT:
			near->type = Elem_FIRE;
		when(Elem_WATER): case Elem_SALTWATER: case Elem_SOAPY:
			Part_remove(p--);
			goto SPARK_brk;
		when(Elem_SNOW):;
			near->type = Elem_WATER;
		}
	}
	if (Rnd_perchance(15)) {
		Part_remove(p--);
		break;
	}
 SPARK_brk:;
#endif
}
