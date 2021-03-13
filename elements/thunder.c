break; case Elem_THUNDER:
{
#ifdef UPDATE_PART
	Dot_toGrid(p);
	p->vel = (Point){0,0};
	
	/////////////////////////
	// thunder in the air: //
	/////////////////////////
	if (p->charge<4096) {
		// update the random number generator
		if (!p->Cthunder1.prng)
			p->Cthunder1.prng = ((int)p->pos.y/4*(WIDTH/4)+(int)p->pos.x/4)%1000;//yes
		int c = p->Cthunder1.dir;
		int n = p->Cthunder1.prng;
		n = 73*n%955+44;
		int vx,vy;
		if (c==0) { // down
			if (n%3==0)     { vx=-1; vy=0; c=1; } // -> left
			else if (n%3==1){ vx= 1; vy=0; c=3; } // -> right
			else            { vx= 0; vy=1; c=0; } // -> down
		} else if (c==1) { // left
			if (n%2==0) { vx=-1; vy=0; c=1; } // -> left
			else        { vx= 0; vy=1; c=0; } // -> down
		} else { // right (or up)
			if (n%2==0) { vx=1; vy=0; c=3; } // -> right
			else        { vx=0; vy=1; c=0; } // -> down
		}
		// check part at next position
		Dot* near = Dot_pos3(p->pos,vx,vy);
		if (near<=Dot_BGFAN) { // empty, move thunder
			*Dot_pos2(p->pos) = Dot_EMPTY;
			p->pos.x += vx;
			p->pos.y += vy;
			Dot_toGrid(p);
			p->Cthunder1.prng = n;
			p->Cthunder1.dir = c;
		} else if (near>=Dot_0) { // hit other particle
			if (near->type==Elem_THUNDER && (near->Cthunder1.prng!=n || near->Cthunder1.dir!=c)) {
				Dot_KILL();
			}
			if (near->type!=Elem_THUNDER) {
				Elem type = near->type;
				if (type==Elem_METAL || type==Elem_MERCURY) {
					near->charge = type==Elem_METAL ? 6000 : 6100;
					near->Cthunder2.dir = c;
					near->type = Elem_THUNDER;
					Dot_KILL();
				} else if (ELEMENTS[type].state==State_POWDER||ELEMENTS[type].state==State_LIQUID||type==Elem_MAGMA||type==Elem_WOOD||type==Elem_ICE||type==Elem_VINE||type==Elem_GLASS) { //powders, liquids, magma, wood, ice, vine, glass
					p->charge = 5000; //set meta to 5000, will explode on next frame
				} else if (type==Elem_CLOUD) {
					Dot_swap(p,near);
				} else
					Dot_KILL();
			}
		} else if (near>Dot_BGFAN) { // hit a block or something
			Dot_KILL();
		}

		/////////////
		// Explode //
		/////////////
	} else if (p->charge==5000) { //Air.vel forget
		void func(axis x, axis y, axis sx, axis sy) {
			Dot* near = Dot_at[y][x];
			if (near>=Dot_0 && near->type!=Elem_THUNDER) {
				if (near->type==Elem_ICE)
					near->type = Elem_SNOW; //❤️💚💙
				else if (near->type==Elem_FIREWORKS && near->charge>0 && near->charge<5000)
					near->charge += 100;
				near->vel.x -= 3*(x-p->pos.x);
				near->vel.y -= 3*(y-p->pos.y);
			}
		}
		Dot_doRadius(p->pos.x, p->pos.y, 6, func);
		Dot_KILL();

		///////////
		// Glass //
		///////////
	} else if (p->charge>=7000) {
		// first frame, try to conduct to surrounding glass particles
		if (p->charge==7000) {
			void checkGlass(int x, int y) {
				Dot* near = Dot_pos3(p->pos,x,y);
				if (near>=Dot_0 && near->type==Elem_GLASS) {
					near->type = Elem_THUNDER;
					near->charge = 7000;
				}
			}
			checkGlass(0,1);
			checkGlass(-1,0);
			checkGlass(0,-1);
			checkGlass(1,0);
		}
		// turn off after 20 frames
		p->charge++;
		if (p->charge>7020) {
			p->type = Elem_GLASS;
			p->charge = 0;
		}

		///////////////////
		// Metal/Mercury //
		///////////////////
	} else if (p->charge>=6000) {
		int c = p->Cthunder2.dir;
		int inside = p->Cthunder2.type==6000>>2 ? Elem_METAL : Elem_MERCURY;
		Dot* pdir(int dir) {
			return Dot_pos2(p->pos)[(Offset[]){WIDTH,-1,-WIDTH,1}[dir]];
		}
		//check locations in front/left/right, for places to conduct to
		for (int b=0; b<4; b++) {
			if (b==2) continue; //2 = behind
			Dot* near = pdir((c+b)&3);
			if (near<Dot_0) continue;
			// hit metal/mercury
			if (near->type==Elem_METAL||near->type==Elem_MERCURY) {
				Dot_swap(p, near);
				p->Cthunder2.type = near->type==Elem_METAL ? 6000>>2 : 6100>>2; //todo: thinking about it, we could probably use pumptype for this...
				p->Cthunder2.dir = c+b;
				near->type = inside;
				near->charge = 0;
				goto conducted;
			// another thunder inside metal/mercury
			} else if (near->type==Elem_THUNDER && near->charge>=6000 && near->charge<7000) {
				p->type = inside;
				p->charge = 0;
				goto conducted;
			// glass
			} else if (near->type==Elem_GLASS) {
				near->type = Elem_THUNDER;
				near->charge = 7000;
			}
		}
		// did not conduct, send out into the air if possible
		if (pdir(c)<=Dot_BGFAN) {
			axis x = p->pos.x;
			axis y = p->pos.y;
			if (c==0) y++;
			else if (c==1) x--;
			else if (c==2) y--;
			else if (c==3) x++;
			Dot_create(x,y,Elem_THUNDER);
		}
		// then turn back into the conductor element
		p->type = inside;
		p->charge = 0;
	conducted:;
	}

#elif defined UPDATE_BALL
	//nothing

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_SEAWATER):;
		part->type = Elem_THUNDER;
		part->charge = 0;
		return 0;
	when(Elem_THUNDER):;
		return 1;
	when(Elem_METAL):;
		part->type = Elem_THUNDER;
		part->charge = 6000;
	when(Elem_MERCURY):;
		part->type = Elem_THUNDER;
		part->charge = 6100;
		return 1;
	}
#endif
}
