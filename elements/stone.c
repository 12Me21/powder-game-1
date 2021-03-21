break; case Elem_STONE:
{
#ifdef UPDATE_PART
	p->vel.xy += 0.05*c->vel.xy;
	p->vel.y += Random_2(0.01,0.05);
	p->vel.xy *= 0.95;

	Point airvel = p->vel;
	real mag = Vec_fastDist(airvel);
	if (mag>10 && Rnd_perchance(50))
		p->type = Elem_POWDER;
	airvel.xy *= 3.8/(mag+1);
	
	Dot* near = *Dot_pos(p->pos.x+airvel.x, p->pos.y);
	if (near <= Dot_BGFAN) {
		p->pos.x += airvel.x;
	} else {
		// act like stone is heavier than some things
		if (near >= Dot_0) {
			// magma, and liquids other than mercury
			if ((ELEMENTS[near->type].state == State_LIQUID && near->type!=Elem_MERCURY) || near->type==Elem_MAGMA) {
				near->vel.x -= p->vel.x;
				
				real temp = p->pos.x;
				p->pos.x = near->pos.x;
				near->pos.x = temp;
				
				*Dot_pos2(p->pos) = near;
				//powder seed gunpowder fireworks ant
			} else if (near->type==Elem_POWDER||near->type==Elem_SEED||near->type==Elem_GUNPOWDER||near->type==Elem_FIREWORKS||near->type==Elem_ANT)
				near->vel.x += Random_(p->vel.x);
		}
		p->vel.x *= 0.5;
	}
	*Dot_pos2(p->pos) = Dot_EMPTY;

	// this is a copy of the code above, but with the other axis
	near = *Dot_pos(p->pos.x, p->pos.y+airvel.y);
	if (near<=Dot_BGFAN) {
		p->pos.y += airvel.y;
	} else {
		if (near>=Dot_0) {
			// magma, and liquids other than mercury
			if ((ELEMENTS[near->type].state == State_LIQUID && near->type!=Elem_MERCURY) || near->type==Elem_MAGMA) {
				near->vel.y -= p->vel.y;
				
				real temp = p->pos.y;
				p->pos.y = near->pos.y;
				near->pos.y = temp;
				
				*Dot_pos2(p->pos) = near;
				//powder seed gunpowder fireworks ant
			} else if (near->type==Elem_POWDER||near->type==Elem_SEED||near->type==Elem_GUNPOWDER||near->type==Elem_FIREWORKS||near->type==Elem_ANT)
				near->vel.y += Random_(p->vel.y);
		}
		p->vel.y *= 0.5;
	}
	Dot_toGrid(p);

#elif defined UPDATE_BALL
	real dist = Vec_dist(vel);
	if (dist>7 && (touched==-1 || touched==Elem_METAL || touched==Elem_BOMB))
		ball->type = Elem_POWDER;
	else if (touched==Elem_ACID)
		Ball_break(ball, 0, Elem_STONE, 0, Point(0), 0);

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_WATER):;
		ball->charge = 0;
	when(Elem_MAGMA):;
		if (++ball->charge>=20)
			*newType = Elem_MAGMA;
	when(Elem_STONE):;
		if (Dot_limit1000() && ball->vel.x*ball->vel.x+ball->vel.y*ball->vel.y > 10) {//so, radius is sqrt(10)
			int x = floor(ball->pos.x) + floor(Random_(5))-2;
			int y = floor(ball->pos.y) + floor(Random_(5))-2;
			if (*Dot_pos(x, y)<=Dot_BGFAN)
				Dot_create(x, y, Elem_SPARK);
		}
	when(Elem_SPARK):;
		return 1;
	}
#endif
}
