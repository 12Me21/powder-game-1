break; case Elem_POWDER:
{
	Vector airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	Vec_add(&airvel, &p->vel);
	Vec_mul(&p->vel, 0.7);
	Part_blow(p, &airvel);
}
