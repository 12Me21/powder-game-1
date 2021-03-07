break; case Elem_BOMB:
{
#if defined UPDATE_PART || defined UPDATE_BALL
	// this is used by the ball and particle update code
	Point getNearbyDir(Point pos) {
		Point airvel = (Point){0,0};
		void func1(axis x, axis y, axis sx, axis sy) {
			Part* c = *Part_pos(x,y);
			if (c>=Part_0 && c->type!=Elem_BOMB) {
				airvel.x += sx-x;
				airvel.y += sy-y;	
			}
		}
		Part_doRadius(pos.x, pos.y, 4, func1);
		Vec_fastNormalize(&airvel);
		return airvel;
	}
#endif

#ifdef UPDATE_PART
	
	p->vel.y += 0.03;
	p->vel.xy *= 0.92;
	Point airvel = c->vel;
	airvel.xy += p->vel.xy;
	Part_blow(p, airvel);

	// bomb particles produced by explosion
	if (p->meta) {
		if (p->meta==Elem_BOMB) {
			Part_KILL();
		} else if (Random_(100)<=5) { // <=, not <
			// turn shrapnel into destroyed versions of the source particle
			switch (p->meta) {
			case Elem_ICE:
				p->type = Elem_SNOW;
				p->meta = 0;
			when(Elem_WOOD): case Elem_STONE: case Elem_VINE:
				p->type = Elem_POWDER;
				p->meta = 0;
			when(Elem_NITRO): case Elem_TORCH:
				p->type = Elem_FIRE;
				p->meta = 1;
			when(Elem_SOAPY):;
				p->type = Elem_STEAM;
				p->meta = 0;
			when(Elem_METAL):;
				p->type = Elem_METAL;
				p->meta = 0;
			when(Elem_GLASS):;
				p->type = Elem_STONE;
				p->meta = 0;
			when(Elem_PUMP):;
				p->type = Elem_SPARK;
				p->meta = 0;
			otherwise:
				Part_KILL();
			}
		}
		break;
	}
	// otherwise, check if bomb should explode:
	
	// random part in 3x3 radius
	Part* near = Part_rndNear(p->pos,3);
	// return if it hasn't hit anything explodable
	if (near<Part_0 || near->type==Elem_BOMB || near->type==Elem_CLONE)
		break;
	// calculate average direction to nearby parts
	airvel = getNearbyDir(p->pos);

	// turn nearby parts into charged bomb, and push them away:
	void func2(axis x, axis y, axis sx, axis sy) {
		Part* c = *Part_pos(x,y);
		if (c>=Part_0 && c->type!=Elem_CLONE) {
			c->vel.x += airvel.x+1*(p->pos.x-x);
			c->vel.y += airvel.y+1*(p->pos.y-y);
			if (c->type!=Elem_BOMB||c->meta==0) {
				c->pumpType = 0;
				c->meta = c->type;
				c->type = Elem_BOMB;
			}
		}
	}
	Part_doRadius(p->pos.x, p->pos.y, 4, func2);

	Part_KILL();

#elif defined UPDATE_BALL
	// this is similar to the part update code
	if (touched>=0 && touched!=Elem_BOMB && touched!=Elem_FIRE && touched!=Elem_GAS && touched!=Elem_LASER && ELEMENTS[touched].state>0) {
		Point airvel = getNearbyDir(ball->pos);

		// unlike normal bomb, bomb balls blow up all part types
		void func2(axis x, axis y, axis sx, axis sy) {
			Part* c = *Part_pos(x,y);
			if (c>=Part_0) {
				c->meta = c->type;
				c->type = Elem_BOMB;
				c->pumpType = 0;
				c->vel.x += 0.5*airvel.x+0.5*(ball->pos.x-x);
				c->vel.y += 0.5*airvel.y+0.5*(ball->pos.y-y);
			}
		}
		Part_doRadius(ball->pos.x, ball->pos.y, 10, func2);
		ball->used = false;
	}

#elif defined UPDATE_BALL_PART
	//nothing
#endif
}
