break; case Elem_TORCH:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	
	Dot* near = Dot_rndNear(p->pos, 5);
	if (near>=Dot_0) {
		switch (near->type) {
		case Elem_POWDER: case Elem_SEED: case Elem_SUPERBALL: case Elem_ANT: case Elem_VINE:
			near->type = Elem_FIRE;
			break;
		case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER:
			Dot_KILL();
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
	case Elem_WATER: case Elem_SOAPY: case Elem_SEAWATER: case Elem_ACID:
		Ball_break(ball, 0, Elem_TORCH, 0, 0, 0, 0);
	when(Elem_THUNDER):;
		Ball_break(ball, 0, Elem_FIRE, 0, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_POWDER:case Elem_SEED:case Elem_GUNPOWDER:case Elem_SUPERBALL:case Elem_OIL:case Elem_C4:case Elem_NITRO:case Elem_ANT:case Elem_GAS:case Elem_VINE:case Elem_BIRD:case Elem_FUSE:
		part->type = Elem_FIRE;
		part->charge = 0;
		break;
	case Elem_ICE: case Elem_SNOW: case Elem_CLOUD:
		part->type = Elem_WATER;
		part->charge = 0;
		break;
	case Elem_FIREWORKS:
		if (part->charge>0 && part->charge<100) {
			part->vel.y -= 50;
			part->charge += 100;
		}
	}
#endif
}
