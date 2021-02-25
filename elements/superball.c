break; case Elem_SUPERBALL:
{
#ifdef UPDATE_PART
	Vector airvel = c->vel;
	Vec_mul(&airvel, 0.05);
	Vec_add(&p->vel, &airvel);
	p->vel.y += 0.01;
	Vec_mul(&p->vel, 0.999);
	airvel = p->vel;
	Vec_mul(&airvel, 3.8/(Vec_fastDist(&airvel)+1));
	
	Part* f = Part_pos2(&p->pos)[Part_ofs(airvel.x,0)];
	// empty
	if (f <= Part_BGFAN)
		p->pos.x += airvel.x;
	// fake parts
	else if (f < Part_0) {
		p->vel.x *= -0.9;
		p->vel.y *= 0.9;
		// real parts
	} else if (f >= Part_0) {
		// liquids other than mercury
		if (ELEMENTS[f->type].state == State_LIQUID && f->type != Elem_MERCURY) {
			f->pos.x -= p->vel.x;
			p->vel.x *= 0.5;
			double c = p->pos.x;
			p->pos.x = f->pos.x;
			f->pos.x = c;
		} else if (f->type == Elem_FIRE) {
			double c = p->pos.x;
			p->pos.x = f->pos.x;
			f->pos.x = c;
		} else if (f->type == Elem_SUPERBALL) {
			double c = 0.9*p->vel.x;
			p->vel.x = 0.9*f->vel.x;
			f->vel.x = c;
		} else {
			p->vel.x *= -ELEMENTS[f->type].ze;
			p->vel.y *= ELEMENTS[f->type].Ae;
		}
	}
	*Part_pos2(&p->pos) = Part_EMPTY;
	f = *Part_pos(p->pos.y+airvel.y, p->pos.x);
	if (f <= Part_BGFAN)
		p->pos.y += airvel.y;
	else if (f < Part_0) {
		p->vel.x *= 0.9;
		p->vel.y *= -0.9;
	} else if (f >= Part_0) {
		// liquids other than mercury
		if (ELEMENTS[f->type].state == State_LIQUID && f->type != Elem_MERCURY) {
			f->pos.y -= p->vel.y;
			p->vel.y *= 0.5;
			double c = p->pos.y;
			p->pos.y = f->pos.y;
			f->pos.y = c;
		} else if (f->type == Elem_FIRE) {
			double c = p->pos.y;
			p->pos.y = f->pos.y;
			f->pos.y = c;
		} else if (f->type == Elem_SUPERBALL) {
			if (p->vel.y > 0) {
				double c = 0.45*p->vel.y;
				p->vel.y *= -0.45;
				p->vel.y += f->vel.y;
				f->vel.y = c;
			} else {
				double c = 0.45*f->vel.y;
				f->vel.y *= -0.45;
				f->vel.y += p->vel.y;
				p->vel.y = c;
			}
		} else {
			p->vel.y *= -ELEMENTS[f->type].ze;
			p->vel.x *= ELEMENTS[f->type].Ae;
		}
	}
	*Part_pos2(&p->pos) = p;
#endif
}
