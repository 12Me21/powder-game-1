break; case Elem_THUNDER:
{
	Part_at[(int)p->pos.y][(int)p->pos.x] = p;
	p->vel = (Vector){0,0};
	if (p->meta<0x1000) {
		if (!p->meta)
			p->meta = ((int)p->pos.y/4*(WIDTH/4)+(int)p->pos.x)%1000; //is this the right 1000?
		int c = p->meta>>10;
		int n = p->meta & 0x3FF;
		n = 73*n%955+44;
		int vx,vy;
		if (c==0) {
			int f = n%3;
			if (f==0) { vx=-1; vy=0; c=1; }
			else if (f==1) {vx=1; vy=0; c=3; }
			else { vx=0; vy=1; c=0; }
		} else if (c==1) {
			if (n%2<=0) { vx=-1; vy=0; c=1; }
			else { vx=0; vy=1; c=0; }
		} else {
			if (n%2<=0) { vx=1; vy=0; c=3; }
			else { vx=0; vy=1; c=0; }
		}
		Part* near = Part_at[(int)p->pos.y+vy][(int)p->pos.x+vx];
		int b = c<<10|n;
		if (near<=Part_BGFAN) {
			Part_at[(int)p->pos.y][(int)p->pos.x] = Part_EMPTY;
			p->pos.x += vx;
			p->pos.y += vy;
			Part_at[(int)p->pos.y][(int)p->pos.x] = p;
			p->meta = b;
		} else if (near>=Part_0) {
			if (near->type!=Elem_THUNDER || near->meta!=b) {
				if (near->type==Elem_THUNDER) {
					Part_remove(p--);
					break;
				}
				if (near->type==Elem_METAL || near->type==Elem_MERCURY) {
					if (near->type==Elem_METAL)
						near->meta = 6000+c;
					else
						near->meta = 6100+c;
					near->type = Elem_THUNDER;
					Part_remove(p--);
					break;
				}
				//powders, liquids, magma, wood, ice, vine, glass
				int type = near->type;
				if (ELEMENTS[type].state==State_POWDER||ELEMENTS[type].state==State_LIQUID||type==Elem_MAGMA||type==Elem_WOOD||type==Elem_ICE||type==Elem_VINE||type==Elem_GLASS) {
					p->meta = 5000;
				} else if (type==Elem_CLOUD) {
					Part_swap(p,near);
				} else {
					Part_remove(p--);
					break;
				}
			}
		} else if (near>Part_BGFAN) {
			Part_remove(p--);
			break;
		}
	} else {
		//Air.vel forget
		if (p->meta==5000) {
			int xy=6;
			int b = p->pos.x;
			int r = p->pos.y;
			int w = b-xy;
			if (w<4) w=4;
			int n = r-xy;
			if (n<4) n=4;
			int y = b+xy;
			if (y>WIDTH-4-1) y=WIDTH-4-1;
			int z = r+xy;
			if (z>HEIGHT-4-1) z=HEIGHT-4-1;
			int q,g;
			for (q=n;q<=z;q++) {
				for (g=w;g<=y;g++) {
					if ((g-b)*(g-b)+(q-r)*(q-r)>xy*xy)
						continue;
					Part* near = Part_at[q][g];
					if (near>=Part_0 && near->type!=Elem_THUNDER) {
						if (near->type==Elem_ICE)
							near->type = Elem_SNOW; //❤️💚💙
						else if (near->type==Elem_FIREWORKS && near->meta>0 && near->meta<5000)
							near->meta += 100;
						near->vel.x -= 3*(g-p->pos.x);
						near->vel.y -= 3*(q-p->pos.y);
					}
				}
			}
			Part_remove(p--);
			break;
		}
		//glass things
		if (p->meta>=7000) {
			if (p->meta==7000) {
				void checkGlass(int x, int y) {
					Part* near = Part_at[(int)p->pos.y+y][(int)p->pos.x+x];
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
			int c = p->meta&0b11;
			int r = (p->meta&0xFFFC)==6000 ? Elem_METAL : Elem_MERCURY;
			int b;
			Part* pdir(int dir) {
				switch (dir) {
				when(0):;
					return Part_at[(int)p->pos.y+1][(int)p->pos.x];
				when(1):;
					return Part_at[(int)p->pos.y][(int)p->pos.x-1];
				when(2):;
					return Part_at[(int)p->pos.y-1][(int)p->pos.x];
				when(3):;
					return Part_at[(int)p->pos.y][(int)p->pos.x+1];
				}
				//never
				return NULL;
			}
			for (b=0; b<4; b++) { //check locations in front/left/right
				if (b==2) continue; //2 = behind
				Part* near = pdir(c+b&3);
				if (near<Part_0) continue;
				if (near->type==Elem_METAL||near->type==Elem_MERCURY) {
					Part_swap(p, near);
					if (near->type==Elem_METAL)
						p->meta = 6000+(c+b&0b11);
					else
						p->meta = 6100+(c+b&0b11); //todo: thinking about it, we could probably use pumptype for this...
					near->type = r;
					near->meta = 0;
					break;
				} else if (near->type==Elem_THUNDER && near->meta>=6000 && near->meta<7000) {
					p->type = r;
					p->meta = 0;
					break;
				} else if (near->type==Elem_GLASS) {
					near->type = Elem_THUNDER;
					near->meta = 7000;
				}
			}
			// did not conduct
			if (b==4) {
				if (pdir(c)<=Part_BGFAN) {
					int g = p->pos.x;
					int q = p->pos.y;
					if (c==0)
						Part_create(g,q+1,Elem_THUNDER);
					else if (c==1)
						Part_create(g-1,q,Elem_THUNDER);
					else if (c==2)
						Part_create(g,q-1,Elem_THUNDER);
					else if (c==3)
						Part_create(g+1,q,Elem_THUNDER);
				}
				p->type = r;
				p->meta = 0;
			}
		}
	}
}
