break; case Elem_STONE:
{
#ifdef UPDATE_PART
	p->vel.x += 0.05*c->vel.x;
	p->vel.y += 0.05*c->vel.y;
	p->vel.y += Random_2(0.01,0.05);
	Vec_mul(&p->vel, 0.95);
	Vector airvel = p->vel;
	double mag = Vec_fastDist(&airvel);
	if (mag>10 && Random_(100)<50)
		p->type = Elem_POWDER;
	Vec_mul(&airvel, 3.8/(mag+1));
	Part* near = Part_at[(int)p->pos.y][(int)(p->pos.x+airvel.x)];
	if (near <= Part_BGFAN) {
		p->pos.x += airvel.x;
	} else {
		// act like stone is heavier than some things
		if (near >= Part_0) {
			// magma, and liquids other than mercury
			if ((ELEMENTS[near->type].state == State_LIQUID && near->type!=Elem_MERCURY) || near->type==Elem_MAGMA) {
				near->vel.x -= p->vel.x;
				double temp = p->pos.x;
				p->pos.x = near->pos.x;
				near->pos.x = temp;
				Part_at[(int)p->pos.y][(int)p->pos.x] = near;
				//powder seed gunpowder fireworks ant
			} else if (near->type==Elem_POWDER||near->type==Elem_SEED||near->type==Elem_GUNPOWDER||near->type==Elem_FIREWORKS||near->type==Elem_ANT)
				near->vel.x += Random_(p->vel.x);
		}
		p->vel.x *= 0.5;
	}
	Part_at[(int)p->pos.y][(int)p->pos.x] = Part_EMPTY;
	near = Part_at[(int)(p->pos.y+airvel.y)][(int)p->pos.x];
	if (near<=Part_BGFAN) {
		p->pos.y += airvel.y;
	} else {
		if (near>=Part_0) {
			// magma, and liquids other than mercury
			if ((ELEMENTS[near->type].state == State_LIQUID && near->type!=Elem_MERCURY) || near->type==Elem_MAGMA) {
				near->vel.y -= p->vel.y;
				double temp = p->pos.y;
				p->pos.y = near->pos.y;
				near->pos.y = temp;
				Part_at[(int)p->pos.y][(int)p->pos.x] = near;
				//powder seed gunpowder fireworks ant
			} else if (near->type==Elem_POWDER||near->type==Elem_SEED||near->type==Elem_GUNPOWDER||near->type==Elem_FIREWORKS||near->type==Elem_ANT)
				near->vel.y += Random_(p->vel.y);
		}
		p->vel.y *= 0.5;
	}
	Part_at[(int)p->pos.y][(int)p->pos.x] = p;
#endif
}
