break; case Elem_BIRD:
{
#ifdef UPDATE_PART
	if (p->charge==0) {
		// when particle is initially created, set random velocity
		p->charge = 1;
		p->vel.xy = Rnd_point(-1,1, -1,1).xy;
	} else if (p->charge==2) {
		// charge = 2: bird is sitting on wood
		if (Rnd_perchance(2)) {
			// 2% chance of flying away
			p->charge = 1;
			p->vel.xy *= -1;
		} else { //otherwise stay put
			Dot_toGrid(p);
			break;
		}
	}
	int ox = p->pos.x;
	int oy = p->pos.y;

	Point airvel = c->vel;
	airvel.xy += 0.5*p->vel.xy;
	Dot_blow(p, airvel);
	//bad
	//if we didn't move
	if ((int)p->pos.x==ox && (int)p->pos.y==oy) {
		// randomly switch direction
		if (Rnd_perchance(50))
			p->vel = (Point){p->vel.y, -p->vel.x};
		else
			p->vel = (Point){-p->vel.y, p->vel.x};
	}
	// check a nearby particle
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	Dot* near = Dot_pos3(p->pos, x, y);
	if (near>=Dot_0) {
		// if it's a liquid particle, and below the bird:
		if (y<=0 && near->type[ELEMENTS].state==State_LIQUID) {
			// splash the liquid I guess?
			Dot_swap(p, near);
		// eat seed/ant:
		} else if (near->type==Elem_SEED || near->type==Elem_ANT) {
			near->type = Elem_BIRD;
			near->vel = p->vel;
			near->charge = 1;
			Dot_KILL();
		// land on wood:
		} else if (near->type==Elem_WOOD) {
			p->charge = 2;
		// burn
		} else if (near->type[ELEMENTS].state==State_HOT) {
			p->type = Elem_FIRE;
		}
	}
	// here we check surrounding particles, and calculate:
	// the amount and average velocity of birds
	// the amount and average position of other particles
	int nearBirds = 0;
	Point nearBirdDir = {0,0};
	int nearOthers = 0;
	Point nearOtherDir = {0,0};
	inline void func(axis x, axis y, axis sx, axis sy) {
		Dot* near = *Dot_pos(x,y);
		if (near>=Dot_0) {
			if (near->type==Elem_BIRD) {
				nearBirdDir.xy += near->vel.xy;
				nearBirds++;
			} else if (near->type!=Elem_SEED && near->type!=Elem_ANT && near->type!=Elem_WOOD) {
				nearOtherDir.xy += (Point){x,y}.xy;
				nearOthers++;
			}
		} else if (near>Dot_BGFAN) {
			nearOtherDir.xy += (Point){x,y}.xy;
			nearOthers++;
		}
	}
	Dot_doRadius(p->pos.x+4*p->vel.x, p->pos.y+4*p->vel.y, 9, func);
	// yes, these are different:
	if (nearBirds>0)
		nearBirdDir.xy *= 1/nearBirds;
	if (nearOthers>0)
		nearOtherDir.xy /= nearOthers;

	// now, we alter the bird's velocity to match surrounding birds
	Vec_fastNormalize(&p->vel);
	p->vel.xy =
		0.5*p->vel.xy +
		0.5*nearBirdDir.xy +
		Rnd_point(-0.1,0.1, -0.1,0.1).xy;

	// if there were non-bird particles nearby, update the bird's velocity to avoid them (I think)
	if (nearOthers>0) {
		nearOtherDir.x = (int)(nearOtherDir.x); //idk why this is done...
		nearOtherDir.y = (int)(nearOtherDir.y);
		nearOtherDir.xy -= p->pos.xy;
		Point vel;
		if (p->vel.y*nearOtherDir.x - p->vel.x*nearOtherDir.y < 0)
			vel = (Point){p->vel.y, -p->vel.x};
		else
			vel = (Point){-p->vel.y, p->vel.x};
		p->vel.xy = 0.9*p->vel.xy + 0.1*vel.xy;
	}

#elif defined UPDATE_BALL
	if (touched>=0) {
		if (ELEMENTS[touched].state==State_HOT) {
			Ball_break(ball, 0, Elem_FIRE, 0, 0.5*ball->vel.x, 0.5*ball->vel.y, 0.5);
		} else if (touched==Elem_ACID)
			Ball_break(ball, 0, Elem_BIRD, 0, 0, 0, 0);
	}

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	case Elem_SEED: case Elem_ANT:
		Dot_remove(part);
		break;
	case Elem_WOOD:
		ball->vel.xy *= 0.9;
	}
#endif
}
