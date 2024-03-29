break; case Elem_SUPERBALL:
{
#ifdef UPDATE_PART
	Point airvel = c->vel;
	airvel.xy *= 0.05;
	p->vel.xy += airvel.xy;
	p->vel.y += 0.01;
	p->vel.xy *= 0.999;
	airvel = p->vel;
	airvel.xy *= 3.8/(Vec_fastDist(airvel)+1);
	
	Dot* near = *Dot_pos(p->pos.x+airvel.x, p->pos.y);
	// empty
	if (near <= Dot_BGFAN)
		p->pos.x += airvel.x;
	// fake parts
	else if (near < Dot_0) {
		p->vel.x *= -0.9;
		p->vel.y *= 0.9;
		// real parts
	} else if (near >= Dot_0) {
		// liquids other than mercury
		if (ELEMENTS[near->type].state == State_LIQUID && near->type != Elem_MERCURY) {
			near->vel.x -= p->vel.x;
			p->vel.x *= 0.5;
			real c = p->pos.x;
			p->pos.x = near->pos.x;
			near->pos.x = c;
		} else if (near->type == Elem_FIRE) {
			real c = p->pos.x;
			p->pos.x = near->pos.x;
			near->pos.x = c;
		} else if (near->type == Elem_SUPERBALL) {
			real c = 0.9*p->vel.x;
			p->vel.x = 0.9*near->vel.x;
			near->vel.x = c;
		} else {
			p->vel.x *= -ELEMENTS[near->type].ze;
			p->vel.y *= ELEMENTS[near->type].Ae;
		}
	}
	*Dot_pos2(p->pos) = Dot_EMPTY;
	near = *Dot_pos(p->pos.x, p->pos.y+airvel.y);
	if (near <= Dot_BGFAN)
		p->pos.y += airvel.y;
	else if (near < Dot_0) {
		p->vel.x *= 0.9;
		p->vel.y *= -0.9;
	} else if (near >= Dot_0) {
		// liquids other than mercury
		if (ELEMENTS[near->type].state == State_LIQUID && near->type != Elem_MERCURY) {
			near->vel.y -= p->vel.y;
			p->vel.y *= 0.5;
			real c = p->pos.y;
			p->pos.y = near->pos.y;
			near->pos.y = c;
		} else if (near->type == Elem_FIRE) {
			real c = p->pos.y;
			p->pos.y = near->pos.y;
			near->pos.y = c;
		} else if (near->type == Elem_SUPERBALL) {
			if (p->vel.y > 0) {
				real c = 0.45*p->vel.y;
				p->vel.y *= -0.45;
				p->vel.y += near->vel.y;
				near->vel.y = c;
			} else {
				real c = 0.45*near->vel.y;
				near->vel.y *= -0.45;
				near->vel.y += p->vel.y;
				p->vel.y = c;
			}
		} else {
			p->vel.y *= -ELEMENTS[near->type].ze;
			p->vel.x *= ELEMENTS[near->type].Ae;
		}
	}
	*Dot_pos2(p->pos) = p;
	if (p->pos.y < 0 || p->pos.x<0 || p->pos.x>=WIDTH || p->pos.y>=HEIGHT) {
		Dot_print(p);
		Dot_remove(p--);
	}
#endif
}
