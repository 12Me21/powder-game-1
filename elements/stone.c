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

#elif defined UPDATE_BALL
	double dist = Vec_dist(&vel);
	if (dist>7 && (touched==-1 || touched==Elem_METAL || touched==Elem_BOMB))
		ball->type = Elem_POWDER;
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_STONE, 0, 0, 0, 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->meta = 0;
	when(Elem_MAGMA):;
		if (++ball->meta>=20)
			*newType = Elem_MAGMA;
	when(Elem_METAL):;
		// todo check limit
		if (ball->vel.x*ball->vel.x+ball->vel.y*ball->vel.y > 10) {
			int x = floor(ball->pos.x) + floor(Random_(5))-2;
			int y = floor(ball->pos.y) + floor(Random_(5))-2;
			if (Part_pos(x, y)[0]<=Part_BGFAN)
				Part_create(x, y, Elem_SPARK);
		}
	when(Elem_SPARK):;
		return 1;
	}
#endif
}
