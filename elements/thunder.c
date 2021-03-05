break; case Elem_THUNDER:
{
#ifdef UPDATE_PART
	*Part_pos2(p->pos) = p;
	p->vel = (Point){0,0};
	if (p->meta<4096) {
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
		Part* near = Part_pos3(p->pos,vx,vy);
		if (near<=Part_BGFAN) {
			*Part_pos2(p->pos) = Part_EMPTY;
			p->pos.x += vx;
			p->pos.y += vy;
			*Part_pos2(p->pos) = p;
			p->Cthunder1.prng = n;
			p->Cthunder1.dir = c;
		} else if (near>=Part_0) {
			if (near->type==Elem_THUNDER && (near->Cthunder1.prng!=n && near->Cthunder1.dir!=c)) {
				Part_remove(p--);
				break;
			}
			if (near->type!=Elem_THUNDER) {
				Elem type = near->type;
				if (type==Elem_METAL || type==Elem_MERCURY) {
					if (type==Elem_METAL)
						near->meta = 6000+c;
					else
						near->meta = 6100+c;
					near->type = Elem_THUNDER;
					Part_remove(p--);
				} else if (ELEMENTS[type].state==State_POWDER||ELEMENTS[type].state==State_LIQUID||type==Elem_MAGMA||type==Elem_WOOD||type==Elem_ICE||type==Elem_VINE||type==Elem_GLASS) { //powders, liquids, magma, wood, ice, vine, glass
					p->meta = 5000;
				} else if (type==Elem_CLOUD) {
					Part_swap(p,near);
				} else {
					Part_remove(p--);
				}
			}
		} else if (near>Part_BGFAN) {
			Part_remove(p--);
			break;
		}
	} else if (p->meta==5000) { //Air.vel forget
		void func(axis x, axis y, axis sx, axis sy) {
			Part* near = Part_at[y][x];
			if (near>=Part_0 && near->type!=Elem_THUNDER) {
				if (near->type==Elem_ICE)
					near->type = Elem_SNOW; //❤️💚💙
				else if (near->type==Elem_FIREWORKS && near->meta>0 && near->meta<5000)
					near->meta += 100;
				near->vel.x -= 3*(x-p->pos.x);
				near->vel.y -= 3*(y-p->pos.y);
			}
		}
		Part_doRadius(p->pos.x, p->pos.y, 6, func);
		Part_remove(p--);
	} else if (p->meta>=7000) { //glass things
		if (p->meta==7000) {
			void checkGlass(int x, int y) {
				Part* near = Part_pos3(p->pos,x,y);
				if (near>=Part_0 && near->type==Elem_GLASS) {
					near->type = Elem_THUNDER;
					near->meta = 7000;
				}
			}
			checkGlass(0,1);
			checkGlass(-1,0);
			checkGlass(0,-1);
			checkGlass(1,0);
		}
		p->meta++;
		//turn off glass
		if (p->meta>7020) {
			p->type = Elem_GLASS;
			p->meta = 0;
		}
		//metal/mercury
	} else if (p->meta>=6000) {
		int c = p->Cthunder2.dir;
		int inside = p->Cthunder2.type==6000>>2 ? Elem_METAL : Elem_MERCURY;
		Part* pdir(int dir) {
			return Part_pos2(p->pos)[(Offset[]){WIDTH,-1,-WIDTH,1}[dir]];
		}
		for (int b=0; b<4; b++) { //check locations in front/left/right
			if (b==2) continue; //2 = behind
			Part* near = pdir((c+b)&3);
			if (near<Part_0) continue;
			if (near->type==Elem_METAL||near->type==Elem_MERCURY) {
				Part_swap(p, near);
				p->Cthunder2.type = near->type==Elem_METAL ? 6000>>2 : 6100>>2; //todo: thinking about it, we could probably use pumptype for this...
				p->Cthunder2.dir = c+b;
				near->type = inside;
				near->meta = 0;
				goto conducted;
			} else if (near->type==Elem_THUNDER && near->meta>=6000 && near->meta<7000) {
				p->type = inside;
				p->meta = 0;
				goto conducted;
			} else if (near->type==Elem_GLASS) {
				near->type = Elem_THUNDER;
				near->meta = 7000;
			}
		}
		// did not conduct
		if (pdir(c)<=Part_BGFAN) {
			axis g = p->pos.x;
			axis q = p->pos.y;
			if (c==0)
				Part_create(g,q+1,Elem_THUNDER);
			else if (c==1)
				Part_create(g-1,q,Elem_THUNDER);
			else if (c==2)
				Part_create(g,q-1,Elem_THUNDER);
			else if (c==3)
				Part_create(g+1,q,Elem_THUNDER);
		}
		p->type = inside;
		p->meta = 0;
	conducted:;
	}

#elif defined UPDATE_BALL
	//nothing

#elif defined UPDATE_BALL_PART
	switch (part->type) {
	when(Elem_SALTWATER):;
		part->type = Elem_THUNDER;
		part->meta = 0;
		return 0;//why?
	when(Elem_THUNDER):;
		return 1;
	when(Elem_METAL):;
		part->type = Elem_THUNDER;
		part->meta = 6000;
		// no return?
	when(Elem_MERCURY):;
		part->type = Elem_THUNDER;
		part->meta = 6100;
		return 1;
	}
#endif
}
