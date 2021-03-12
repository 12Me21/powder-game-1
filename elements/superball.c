break; case Elem_SUPERBALL:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	Vec_mul(&airvel, 0.05);
	Vec_add(&p->vel, airvel);
	p->vel.y += 0.01;
	Vec_mul(&p->vel, 0.999);
	airvel = p->vel;
	Vec_mul(&airvel, 3.8/(Vec_fastDist(airvel)+1));

	Dot* f = *Dot_pos(p->pos.x+airvel.x, p->pos.y);
	// empty
	if (f <= Dot_BGFAN)
		p->pos.x += airvel.x;
	// fake parts
	else if (f < Dot_0) {
		p->vel.x *= -0.9;
		p->vel.y *= 0.9;
		// real parts
	} else if (f >= Dot_0) {
		// liquids other than mercury
		if (ELEMENTS[f->type].state == State_LIQUID && f->type != Elem_MERCURY) {
			f->vel.x -= p->vel.x;
			p->vel.x *= 0.5;
			real c = p->pos.x;
			p->pos.x = f->pos.x;
			f->pos.x = c;
		} else if (f->type == Elem_FIRE) {
			real c = p->pos.x;
			p->pos.x = f->pos.x;
			f->pos.x = c;
		} else if (f->type == Elem_SUPERBALL) {
			real c = 0.9*p->vel.x;
			p->vel.x = 0.9*f->vel.x;
			f->vel.x = c;
		} else {
			p->vel.x *= -ELEMENTS[f->type].ze;
			p->vel.y *= ELEMENTS[f->type].Ae;
		}
	}
	*Dot_pos2(p->pos) = Dot_EMPTY;
	f = *Dot_pos(p->pos.x, p->pos.y+airvel.y);
	if (f <= Dot_BGFAN)
		p->pos.y += airvel.y;
	else if (f < Dot_0) {
		p->vel.x *= 0.9;
		p->vel.y *= -0.9;
	} else if (f >= Dot_0) {
		// liquids other than mercury
		if (ELEMENTS[f->type].state == State_LIQUID && f->type != Elem_MERCURY) {
			f->vel.y -= p->vel.y;
			p->vel.y *= 0.5;
			real c = p->pos.y;
			p->pos.y = f->pos.y;
			f->pos.y = c;
		} else if (f->type == Elem_FIRE) {
			real c = p->pos.y;
			p->pos.y = f->pos.y;
			f->pos.y = c;
		} else if (f->type == Elem_SUPERBALL) {
			if (p->vel.y > 0) {
				real c = 0.45*p->vel.y;
				p->vel.y *= -0.45;
				p->vel.y += f->vel.y;
				f->vel.y = c;
			} else {
				real c = 0.45*f->vel.y;
				f->vel.y *= -0.45;
				f->vel.y += p->vel.y;
				p->vel.y = c;
			}
		} else {
			p->vel.y *= -ELEMENTS[f->type].ze;
			p->vel.x *= ELEMENTS[f->type].Ae;
		}
	}
	*Dot_pos2(p->pos) = p;
	if (p->pos.y < 0 || p->pos.x<0 || p->pos.x>=WIDTH || p->pos.y>=HEIGHT) {
		//printf("out of bounds part! %s pos: %f %f, airvel: %f,%f\n", ELEMENTS[p->type].name, p->pos.x, p->pos.y, c->vel.x, c->vel.y);
		Dot_print(p);
		Dot_remove(p--);
	}
#endif
}
