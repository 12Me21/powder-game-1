break; case Elem_TORCH:
{
#ifdef UPDATE_PART
	Part_blow(p, &(Vector){0,0});
	axis x = Random_int(5)-2;
	axis y = Random_int(5)-2;
	Part* near = Part_pos2(&p->pos)[Part_ofs(x,y)];
	if (near>=Part_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_SEED: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			break;
		case Elem_WATER: case Elem_SOAPY: case Elem_SALTWATER:
			Part_remove(p--);
			break;
		case Elem_WOOD:
			near->type = Elem_TORCH;
			break;
		case Elem_SNOW:
			near->type = Elem_WATER;
		}
	}

#elif defined UPDATE_BALL
	switch (touched) {
	case Elem_WATER: case Elem_SOAPY: case Elem_SALTWATER: case Elem_ACID:
		Ball_break(ball, 0, Elem_TORCH, 0, 0, 0, 0);
	when(Elem_THUNDER):;
		Ball_break(ball, 0, Elem_FIRE, 0, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_POWDER:case Elem_SEED:case Elem_GUNPOWDER:case Elem_SUPERBALL:case Elem_OIL:case Elem_C4:case Elem_NITRO:case Elem_ANT:case Elem_GAS:case Elem_VINE:case Elem_BIRD:case Elem_FUSE:
		part->type = Elem_FIRE;
		part->meta = 0;
		break;
	case Elem_ICE: case Elem_SNOW: case Elem_CLOUD:
		part->type = Elem_WATER;
		part->meta = 0;
		break;
	case Elem_FIREWORKS:
		if (part->meta>0 && part->meta<100) {
			part->vel.y -= 50;
			part->meta += 100;
		}
	}
#endif
}
