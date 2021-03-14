#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "common.h"
#include "vector.h"
#include "random.h"
#include "elements.h"
#include "bubble.h"
#include "dot.h"
#include "menu.h"
#include "input.h"
#include "block.h"
#include "save.h"

const int Dot_LIMITS[] = {20000, 30000, 40000, Dot_MAX};
//int Part_limit = Part_LIMITS[0];

static Dot parts_2[Dot_MAX+5];
Dot* const Dot_0 = parts_2+5;
Dot* const Dot_EMPTY = Dot_0-5;
Dot* const Dot_BGFAN = Dot_0-4;
Dot* const Dot_WHEEL = Dot_0-3;
Dot* const Dot_BALL = Dot_0-2;
Dot* const Dot_BLOCK = Dot_0-1;
AUTORUN {
	for (int i=1; i<=5; i++)
		Dot_0[-i] = (Dot){.type = -i};
}

Dot* Dot_next = Dot_0;

Dot* Dot_at[HEIGHT][WIDTH];
Dot** const Dot_grid0 = &Dot_at[0][0];

static int Dot_counts[Elem_MAX];
int* Dot_updateCounts(void) {
	for (Elem i=0; i<Elem_MAX; i++)
		Dot_counts[i] = 0;
	Dot_FOR (p) {
		if (p->type > 0)
			Dot_counts[p->type]++;
	}
	return Dot_counts;
}

bool Dot_limit1000(void) {
	return Dot_next+1000 < Dot_0+Dot_limit;
}

// todo: make a create that takes a vector
Dot* Dot_create(real x, real y, Elem element) {
	if (Dot_next>=Dot_0+Dot_limit || x<7 || x>=W+8+1 || y<7 || y>=H+8+1)
		return NULL;
	*Dot_next = (Dot){
		{x,y},
		{0,0},
		.type=element,
		.charge=0,
		.pumpType=0,
		.held=false,
	};
	*Dot_pos2(Dot_next->pos) = Dot_next;
	return Dot_next++;
}

void Dot_remove(Dot* part) {
	*Dot_pos2(part->pos) = Dot_EMPTY;
	Dot_next--;
	if (Dot_next != part) {
		*part = *Dot_next;
		*Dot_pos2(part->pos) = part->type==Elem_FAN ? Dot_BGFAN : part;
	}
}

void Dot_swap(Dot* part1, Dot* part2) {
	Dot* temp3 = *Dot_pos2(part1->pos);
	*Dot_pos2(part1->pos) = *Dot_pos2(part2->pos);
	*Dot_pos2(part2->pos) = temp3;

	Point temp = part1->pos;
	part1->pos = part2->pos;
	part2->pos = temp;
}

void Dot_blow(Dot* part, Point airvel) {
	airvel.xy *= 3.8/(Vec_fastDist(airvel)+1);
	if (*Dot_pos(part->pos.x+airvel.x, part->pos.y)<=Dot_BGFAN)
		part->pos.x += airvel.x;
	if (*Dot_pos(part->pos.x, part->pos.y+airvel.y)<=Dot_BGFAN)
		part->pos.y += airvel.y;
	*Dot_pos2(part->pos) = part;
}

void Dot_shuffle(void) {
	Dot_FOR (p) {
		Dot* c = &Dot_0[rand() % (Dot_next-Dot_0)];
		Dot temp = *p;
		*p = *c;
		*c = temp;

		*Dot_pos2(p->pos) = p->type==Elem_FAN ? Dot_BGFAN : p;
		*Dot_pos2(c->pos) = c->type==Elem_FAN ? Dot_BGFAN : c;
	}
}

extern int wa;

void Dot_update(void) {
	// todo: wheels
	Dot_FOR (p) {
		if (!Menu_cursorInMenu && wa==0) {
			if (!p->held) {
				if (Menu_dragStart) {
					if (p->type == Elem_FAN)
						continue;
					Point d = (Point){.xy=Menu_pen.xy - p->pos.xy};
					if (Vec_fastDist(d) < 4*Menu_penSize)
						p->held = true;
				}
			} else if (Menu_dragging) {
				p->vel.xy += (Menu_pen.xy - p->pos.xy)*0.1;
			} else {
				p->held = false;
			}
		}
		Block* c = Block_at(p->pos.x, p->pos.y);
		if (p->type != Elem_FAN)
			*Dot_pos2(p->pos) = Dot_EMPTY;
		switch (p->type) {
			// todo: maybe put this in a real separately compiled file
#define Dot_KILL(...) { Dot_remove(p--); goto Dot_continue; }
#define UPDATE_PART 1
#include "elements/All.c"
#undef UPDATE_PART
#undef Dot_KILL
		}
	Dot_continue:;
	}
	// check parts that go off screen
	Dot_FOR (p) {
		if (Menu_edgeMode==0) { // void edge
			if (p->pos.x<8||p->pos.x>=W+8||p->pos.y<8||p->pos.y>=H+8) {
				Dot_remove(p--);
			}
		} else { //loop edge
			if (p->pos.x<8) {
				Dot** o = &Dot_pos2(p->pos)[Dot_ofs(W,0)];
				if (*o<=Dot_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Dot_pos2(p->pos) = Dot_EMPTY;
					p->pos.x += W;
					*o = p;
				} else
					Dot_remove(p--);
			} else if (p->pos.x>=W+8) {
				Dot** o = &Dot_pos2(p->pos)[Dot_ofs(-W,0)];
				if (*o<=Dot_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Dot_pos2(p->pos) = Dot_EMPTY;
					p->pos.x -= W;
					*o = p;
				} else
					Dot_remove(p--);
			} else if (p->pos.y<8) {
				Dot** o = &Dot_pos2(p->pos)[Dot_ofs(0,H)];
				if (*o<=Dot_BGFAN) {
					*Dot_pos2(p->pos) = Dot_EMPTY;
					p->pos.y += H;
					*o = p;
				} else
					Dot_remove(p--);
			} else if (p->pos.y>=H+8) {
				Dot** o = &Dot_pos2(p->pos)[Dot_ofs(0,-H)];
				if (*o<=Dot_BGFAN) {
					*Dot_pos2(p->pos) = Dot_EMPTY;
					p->pos.y -= H;
					*o = p;
				} else
					Dot_remove(p--);
			}
		}
	}
}

// this is a very common pattern used by elements for explosions
void Dot_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis)) {
	axis n = atLeast(x-radius, 4);
	axis z = atLeast(y-radius, 4);
	axis v = atMost(x+radius, WIDTH-4-1);
	axis r = atMost(y+radius, HEIGHT-4-1);
	for (axis b=z;b<=r;b++)
		for (axis e=n;e<=v;e++)
			if ((e-x)*(e-x)+(b-y)*(b-y)<=radius*radius)
				func(e, b, x, y);
}

bool Dot_checkPump(Dot* part, Dot* pump, int dir) {
	if (pump->type == Elem_PUMP && !pump->pumpType) {
		pump->Cpump.dir = ~dir;
		pump->Cpump.amount = 1;
		pump->pumpType = part->type;
		return true;
	}
	return false;
}

void Dot_liquidUpdate(Dot* p, Block* c, real adv, real x1, real x2, real xr1, real yr1, real yr2, real frc) {
	p->vel.x += adv*c->vel.x;
	p->vel.y += adv*c->vel.y;
	if (Dot_pos3(p->pos,0,1) != Dot_EMPTY) {
		if (Dot_pos3(p->pos,-1,0) == Dot_EMPTY)
			p->vel.x -= Random_2(x1, x2);
		if (Dot_pos3(p->pos,1,0) == Dot_EMPTY)
			p->vel.x += Random_2(x1, x2);
	}
	p->vel.x += Random_2(-xr1, xr1);
	p->vel.y += Random_2(yr1, yr2);
	p->vel.x *= frc;
	p->vel.y *= frc;
	Point airvel = c->vel;
	airvel.xy += p->vel.xy;
	Dot_blow(p, airvel);
}

// flood fill
void Dot_paint(axis x, axis y, Elem replace, Elem type, int charge) {
	axis x1 = x;
	while (1) {
		Dot* f = *Dot_pos(x1,y);
		if (f>=Dot_0 && f->type==replace) {
			f->type = type;
			f->charge = charge;
			f->pumpType = 0;
			x1--;
		} else
			break;
	}
	x1++;
	axis x2 = x+1;
	while (1) {
		Dot* f = *Dot_pos(x2,y);
		if (f>=Dot_0 && f->type==replace) {
			f->type = type;
			f->charge = charge;
			f->pumpType = 0;
			x2++;
		} else
			break;
	}
	x2--;
	for (x=x1; x<=x2; x++) {
		Dot* p = *Dot_pos(x,y-1);
		if (p>=Dot_0 && p->type==replace)
			Dot_paint(x,y-1,replace,type,charge);
		p = *Dot_pos(x,y+1);
		if (p>=Dot_0 && p->type==replace)
			Dot_paint(x,y+1,replace,type,charge);
	}
}

// get the particle at a random location
// within a 5x5 region centered on `pos`
Dot* Dot_rndNear5(Point pos) {
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	return Dot_pos3(pos, x, y);
}

Dot* Dot_rndNear(Point pos, axis diam) {
	int x = Random_int(diam)-diam/2;
	int y = Random_int(diam)-diam/2;
	return Dot_pos3(pos, x, y);
}

void Dot_print(Dot* p) {
	printf("%s\npos: %f,%f\nvel: %f,%f\ncharge: %d\npumpType: %d\n", ELEMENTS[p->type].name, (double)p->pos.x, (double)p->pos.y, (double)p->vel.x, (double)p->vel.y, p->charge, p->pumpType);
}

void Dot_toGrid(Dot* p) {
	*Dot_pos2(p->pos) = p;
}

Dot* Dot_dirNear(Point pos, char dir) {
	return Dot_pos2(pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
}

static bool onscreen(int x, int y){
	return x>=8 && x<W+8 && y>=8 && y<H+8;
}

void Dot_save(SavePixel save[H][W]) {
	Dot_FOR (p) {
		axis x = p->pos.x;
		axis y = p->pos.y;
		if (onscreen(x,y)) {
			x -= 8;
			y -= 8;
			Elem type = p->type;
			if (type==Elem_FAN)
				save[y][x].charge = (int)(64*Vec_angle(p->vel)/TAU);// does this need to be wrapped?
			else if (type==Elem_FIREWORKS)
				save[y][x].charge = p->charge%100;
			else if (type==Elem_THUNDER) {//my addition
				if (p->charge>=7000)
					type = Elem_GLASS;
				else if (p->charge>=6000) {
					if (p->Cthunder2.type==6000>>2)
						type = Elem_METAL;
					else
						type = Elem_MERCURY;
				}
			}
			save[y][x].type = type;
		}
	}
}

void Dot_reset(void) {
	for (axis y=0; y<HEIGHT; y++) {
		for (axis x=0; x<WIDTH; x++) {
			if (Block_at(x,y)->block==1)
				*Dot_pos(x,y) = Dot_BLOCK;
			else
				*Dot_pos(x,y) = Dot_EMPTY;
		}
	}
	Dot_FOR (p) { //probably unnecessary
		p->held = false;
	}
	Dot_next = Dot_0;
}
