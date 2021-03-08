#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "common.h"
#include "vector.h"
#include "elements.h"
#include "part.h"
#include "bg.h"
#include "menu.h"
#include "input.h"
#include "cell.h"


#define PARTS_MAX 400000

static Part parts_2[PARTS_MAX+6];
static Part* const parts = parts_2+5;
Part* const Part_EMPTY = parts-5;
Part* const Part_BGFAN = parts-4;
Part* const Part_WHEEL = parts-3;
Part* const Part_BALL = parts-2;
Part* const Part_BLOCK = parts-1;
Part* const Part_0 = parts;
Part* Part_next = parts;

Part* Part_at[HEIGHT][WIDTH];
Part** const Part_grid0 = &Part_at[0][0];

static int Part_counts[Elem_MAX];
int* Part_updateCounts(void) {
	for (Elem i=0; i<Elem_MAX; i++)
		Part_counts[i] = 0;
	for (Part* p=parts; p<Part_next; p++)
		if (p->type > 0)
			Part_counts[p->type]++;
	return Part_counts;
}

bool Part_limit1000(void) {
	return Part_next+1000 < parts+PARTS_MAX;
}

// todo: make a create that takes a vector
Part* Part_create(real x, real y, Elem element) {
	if (Part_next>=parts+PARTS_MAX || x<7 || x>=W+8+1 || y<7 || y>=H+8+1)
		return NULL;
	*Part_next = (Part){
		{x,y},
		{0,0},
		.type=element,
		.meta=0,
		.pumpType=0,
		.held=false,
	};
	*Part_pos2(Part_next->pos) = Part_next;
	return Part_next++;
}

void Part_remove(Part* part) {
	*Part_pos2(part->pos) = Part_EMPTY;
	Part_next--;
	if (Part_next != part) {
		*part = *Part_next;
		*Part_pos2(part->pos) = part->type==Elem_FAN ? Part_BGFAN : part;
	}
}

void Part_swap(Part* part1, Part* part2) {
	Part* temp3 = *Part_pos2(part1->pos);
	*Part_pos2(part1->pos) = *Part_pos2(part2->pos);
	*Part_pos2(part2->pos) = temp3;

	Point temp = part1->pos;
	part1->pos = part2->pos;
	part2->pos = temp;
}

void Part_blow(Part* part, Point airvel) {
	airvel.c *= 3.8/(Vec_fastDist(airvel)+1);
	if (*Part_pos(part->pos.x+airvel.x, part->pos.y)<=Part_BGFAN)
		part->pos.x += airvel.x;
	if (*Part_pos(part->pos.x, part->pos.y+airvel.y)<=Part_BGFAN)
		part->pos.y += airvel.y;
	*Part_pos2(part->pos) = part;
}

void Part_shuffle(void) {
	for (Part* p=parts; p<Part_next; p++) {
		Part* c = &parts[rand() % (Part_next-parts)];
		Part temp = *p;
		*p = *c;
		*c = temp;

		*Part_pos2(p->pos) = p->type==Elem_FAN ? Part_BGFAN : p;
		*Part_pos2(c->pos) = c->type==Elem_FAN ? Part_BGFAN : c;
	}
}

extern int wa;

void Part_update(void) {
	// todo: wheels
	for (Part* p=parts; p<Part_next; p++) {
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
				/*				Point d = {.z=(Point){Pen_x, Pen_y}.z - p->pos.z};
				Point d = Vec_sub2((Point){Pen_x, Pen_y}, p->pos);
				Vec_mul(&d, 0.1);
				Vec_add(&p->vel, d);*/
				p->vel.c += ((Point){Pen_x, Pen_y}.c - p->pos.c)*0.1;
			} else {
				p->held = false;
			}
		}
		Block* c = &Part_blocks[(axis)p->pos.y/4][(axis)p->pos.x/4];
		if (p->type != Elem_FAN)
			*Part_pos2(p->pos) = Part_EMPTY;
		switch (p->type) {
			// todo: maybe put this in a real separately compiled file
#define Part_KILL(...) { Part_remove(p--); goto Part_continue; }
#define UPDATE_PART 1
#include "elements/All.c"
#undef UPDATE_PART
#undef Part_KILL
		}
	Part_continue:;
	}
	// check parts that go off screen
	for (Part* p=parts; p<Part_next; p++) {
		if (Menu_edgeMode==0) { // void edge
			if (p->pos.x<8||p->pos.x>=W+8||p->pos.y<8||p->pos.y>=H+8) {
				Part_remove(p--);
			}
		} else { //loop edge
			if (p->pos.x<8) {
				Part** o = &Part_pos2(p->pos)[Part_ofs(W,0)];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Part_pos2(p->pos) = Part_EMPTY;
					p->pos.x += W;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.x>=W+8) {
				Part** o = &Part_pos2(p->pos)[Part_ofs(-W,0)];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Part_pos2(p->pos) = Part_EMPTY;
					p->pos.x -= W;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.y<8) {
				Part** o = &Part_pos2(p->pos)[Part_ofs(0,H)];
				if (*o<=Part_BGFAN) {
					*Part_pos2(p->pos) = Part_EMPTY;
					p->pos.y += H;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.y>=H+8) {
				Part** o = &Part_pos2(p->pos)[Part_ofs(0,-H)];
				if (*o<=Part_BGFAN) {
					*Part_pos2(p->pos) = Part_EMPTY;
					p->pos.y -= H;
					*o = p;
				} else
					Part_remove(p--);
			}
		}
	}
}

// this is a very common pattern used by elements for explosions
void Part_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis)) {
	axis n=x-radius;
	if (n<4) n=4;
	axis z=y-radius;
	if (z<4) z=4;
	axis v=x+radius;
	if (v>WIDTH-4-1) v=WIDTH-4-1;
	axis r=y+radius;
	if (r>H+12-1)
		r = H+12-1;
	for (axis b=z;b<=r;b++)
		for (axis e=n;e<=v;e++)
			if ((e-x)*(e-x)+(b-y)*(b-y)<=radius*radius)
				func(e, b, x, y);
}

bool Part_checkPump(Part* part, Part* pump, int dir) {
	if (pump->type == Elem_PUMP && !pump->pumpType) {
		pump->Cpump.dir = ~dir;
		pump->Cpump.amount = 1;
		pump->pumpType = part->type;
		return true;
	}
	return false;
}

void Part_liquidUpdate(Part* p, Block* c, real adv, real x1, real x2, real xr1, real yr1, real yr2, real frc) {
	p->vel.x += adv*c->vel.x;
	p->vel.y += adv*c->vel.y;
	if (Part_pos3(p->pos,0,1) != Part_EMPTY) {
		if (Part_pos3(p->pos,-1,0) == Part_EMPTY)
			p->vel.x -= Random_2(x1, x2);
		if (Part_pos3(p->pos,1,0) == Part_EMPTY)
			p->vel.x += Random_2(x1, x2);
	}
	p->vel.x += Random_2(-xr1, xr1);
	p->vel.y += Random_2(yr1, yr2);
	p->vel.x *= frc;
	p->vel.y *= frc;
	Point airvel = c->vel;
	airvel.xy += p->vel.xy;
	Part_blow(p, airvel);
}

// flood fill
void Part_paint(axis x, axis y, Elem replace, Elem type, int meta) {
	axis x1 = x;
	while (1) {
		Part* f = *Part_pos(x1,y);
		if (f>=Part_0 && f->type==replace) {
			f->type = type;
			f->meta = meta;
			f->pumpType = 0;
			x1--;
		} else
			break;
	}
	x1++;
	axis x2 = x+1;
	while (1) {
		Part* f = *Part_pos(x2,y);
		if (f>=Part_0 && f->type==replace) {
			f->type = type;
			f->meta = meta;
			f->pumpType = 0;
			x2++;
		} else
			break;
	}
	x2--;
	for (x=x1; x<=x2; x++) {
		Part* p = *Part_pos(x,y-1);
		if (p>=Part_0 && p->type==replace)
			Part_paint(x,y-1,replace,type,meta);
		p = *Part_pos(x,y+1);
		if (p>=Part_0 && p->type==replace)
			Part_paint(x,y+1,replace,type,meta);
	}
}

// get the particle at a random location
// within a 5x5 region centered on `pos`
Part* Part_rndNear5(Point pos) {
	int x = Random_int(5)-2;
	int y = Random_int(5)-2;
	return Part_pos3(pos, x, y);
}

Part* Part_rndNear(Point pos, axis diam) {
	int x = Random_int(diam)-diam/2;
	int y = Random_int(diam)-diam/2;
	return Part_pos3(pos, x, y);
}

void Part_print(Part* p) {
	printf("%s\npos: %f,%f\nvel: %f,%f\nmeta: %d\npumpType: %d\n", ELEMENTS[p->type].name, (double)p->pos.x, (double)p->pos.y, (double)p->vel.x, (double)p->vel.y, p->meta, p->pumpType);
}

void Part_toGrid(Part* p) {
	*Part_pos2(p->pos) = p;
}

Part* Part_dirNear(Point pos, char dir) {
	return Part_pos2(pos)[(Offset[]){-WIDTH,-1,1,WIDTH}[dir]];
}
