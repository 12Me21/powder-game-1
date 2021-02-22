break; case Elem_STEAM:
{
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
	if (Random_(100)<10)
		Part_remove(p--);
}
