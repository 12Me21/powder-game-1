break; case Elem_SALT:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.y += Random_2(0.01, 0.1);
	Vec_add(&airvel, p->vel);
	Vec_mul(&p->vel, 0.75);
	Part_blow(p, airvel);
	axis x = Random_int(3)-1;
	axis y = Random_int(3)-1;
	Part* near = Part_pos3(p->pos, x, y);
	if (near>=Part_0) {
		if (near->type==Elem_WATER) {
			near->type = Elem_SALTWATER;
			near->meta = 0;
			Part_remove(p--);
			break;
		} else if (near->type==Elem_MAGMA && Rnd_perchance(50)) {
			Part_remove(p--);
			break;
		}
	}

#elif defined UPDATE_BALL
	if (touched==Elem_MAGMA || touched==Elem_THUNDER || touched==Elem_ACID)
		Ball_break(ball, 0, Elem_SALT, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_WATER:
		*newType = Elem_SALTWATER;
	when(Elem_MAGMA): case Elem_THUNDER:
		return 1;
	}
#endif
}
