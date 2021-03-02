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

static int Part_counts[Elem_MAX];
int* Part_updateCounts(void) {
	int i;
	for (i=0; i<Elem_MAX; i++)
		Part_counts[i] = 0;
	Part* p;
	for (p=parts; p<Part_next; p++)
		if (p->type > 0)
			Part_counts[p->type]++;
	return Part_counts;
}

Part* Part_create(double x, double y, unsigned char element) {
	if (Part_next>=parts+PARTS_MAX || x<7 || x>=W+8+1 || y<7 || y>=H+8+1)
		return NULL;
	*Part_next = (Part){
		{x,y},
		{0,0},
		element,
		0,
		0,
		false,
	};
	*Part_pos2(&Part_next->pos) = Part_next;
	return Part_next++;
}

void Part_remove(Part* part) {
	*Part_pos2(&part->pos) = Part_EMPTY;
	Part_next--;
	if (Part_next != part) {
		*part = *Part_next;
		*Part_pos2(&part->pos) = part->type==Elem_FAN ? Part_BGFAN : part;
	}
}

void Part_swap(Part* part1, Part* part2) {
	Part* temp3 = *Part_pos2(&part1->pos);
	*Part_pos2(&part1->pos) = *Part_pos2(&part2->pos);
	*Part_pos2(&part2->pos) = temp3;

	Vector temp = part1->pos;
	part1->pos = part2->pos;
	part2->pos = temp;

}

Part* Part_blow(Part* part, Vector* airvel) {
	Vec_mul(airvel, 3.8/(Vec_fastDist(airvel)+1));
	if (*Part_pos2(&(Vector){part->pos.x+airvel->x, part->pos.y})<=Part_BGFAN)
		part->pos.x += airvel->x;
	if (*Part_pos2(&(Vector){part->pos.x, part->pos.y+airvel->y})<=Part_BGFAN)
		part->pos.y += airvel->y;
	*Part_pos2(&part->pos) = part;
	return part;
}

void Part_shuffle(void) {
	Part* p;
	for (p=parts; p<Part_next; p++) {
		Part* c = &parts[rand() % (Part_next-parts)];
		Part temp = *p;
		*p = *c;
		*c = temp;

		*Part_pos2(&p->pos) = p->type==Elem_FAN ? Part_BGFAN : p;
		*Part_pos2(&c->pos) = c->type==Elem_FAN ? Part_BGFAN : c;
	}
}

// todo: full reset function
void Part_reset(int a) {
	int x,y;
	for (y=0;y<(H+8)/4;y++) {
		for (x=0;x<(W+8+8)/4;x++) {
			Part_blocks[y][x] = (Block){
				.vel={0,0},
				.vel2={0,0},
				.pres=0,
				.pres2=0,
				.block=0,
			};
		}
	}
	if (a==0) {
		// todo: make sure all the right blocks are filled here
		for (x=1;x<(W+8)/4;x++) {
			Part_blocks[2][x].block = 1;
			Part_blocks[(H+8)/4-1][x].block = 1;
		}
		for (y=1;y<(H+8)/4;y++) {
			Part_blocks[y][2].block = 1;
			Part_blocks[y][(W+8)/4-1].block = 1;
		}
	}
	Part_next = parts;
	for (y=0;y<(H+8);y++)
		for (x=0;x<(W+8+8);x++)
			Part_at[y][x] = Part_EMPTY;
	if (a==0) {
		for (y=0;y<(H+8);y++)
			for (x=0;x<(W+8+8);x++)
				if (Part_blocks[y/4][x/4].block==1)
					Part_at[y][x] = Part_BLOCK;
	}
}

extern int wa;

void Part_update(void) {
	// todo: wheels
	bool dragStart = (Menu_leftSelection == Menu_DRAG && Mouse_rising.left) || (Menu_rightSelection == Menu_DRAG && Mouse_rising.right); //todo: function for this
	bool dragging = (Menu_leftSelection == Menu_DRAG && Mouse_old.left) || (Menu_rightSelection == Menu_DRAG && Mouse_old.right);
	Part* p;
	forRange (p, =parts, <Part_next, ++) {
		if (!Menu_cursorInMenu && wa==0) {
			if (!p->held) {
				if (dragStart) {
					if (p->type == Elem_FAN)
						continue;
					Vector d = {Pen_x, Pen_y};
					Vec_sub(&d, &p->pos);
					if (Vec_fastDist(&d) < 4*Menu_penSize)
						p->held = true;
				}
			} else if (dragging) {
				Vector d = {Pen_x, Pen_y};
				Vec_sub(&d, &p->pos);
				Vec_mul(&d, 0.1);
				Vec_add(&p->vel, &d);
			} else {
				p->held = false;
			}
		}
		Block* c = &Part_blocks[(int)p->pos.y/4][(int)p->pos.x/4];
		if (p->type != Elem_FAN)
			*Part_pos2(&p->pos) = Part_EMPTY;
		switch (p->type) {
			// todo: maybe put this in a real separately compiled file
#define UPDATE_PART 1
#include "elements/All.c"
#undef UPDATE_PART
		}
		//ElemFunc f = ELEMENTS[p->type].update;
		//if (f) {
		//	if (f(p, &Part_blocks[(int)p->pos.y/4][(int)p->pos.x/4]))
		//		p--; //part died
		//}
	}
	// check parts that go off screen
	forRange (p, =parts, <Part_next, ++) {
		if (Menu_edgeMode==0) { // void edge
			if (p->pos.x<8||p->pos.x>=W+8||p->pos.y<8||p->pos.y>=H+8) {
				Part_remove(p--);
			}
		} else { //loop edge
			if (p->pos.x<8) {
				Part** o = &Part_pos2(&p->pos)[Part_ofs(W,0)];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.x += W;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.x>=W+8) {
				Part** o = &Part_pos2(&p->pos)[Part_ofs(-W,0)];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<H+8) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.x -= W;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.y<8) {
				Part** o = &Part_pos2(&p->pos)[Part_ofs(0,H)];
				if (*o<=Part_BGFAN) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.y += H;
					*o = p;
				} else
					Part_remove(p--);
			} else if (p->pos.y>=H+8) {
				Part** o = &Part_pos2(&p->pos)[Part_ofs(0,-H)];
				if (*o<=Part_BGFAN) {
					*Part_pos2(&p->pos) = Part_EMPTY;
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
	int n=x-radius;
	if (n<4) n=4;
	int z=y-radius;
	if (z<4) z=4;
	int v=x+radius;
	if (v>WIDTH-4-1) v=WIDTH-4-1;
	int r=y+radius;
	if (r>H+12-1) r = H+12-1;
	for (int b=z;b<=r;b++)
		for (int e=n;e<=v;e++)
			if ((e-x)*(e-x)+(b-y)*(b-y)<=radius*radius)
				func(e, b, x, y);
}

bool Part_checkPump(Part* part, Part* pump, int dir) {
	if (pump->type == Elem_PUMP && !pump->pumpType) {
		pump->meta = 4|dir;
		pump->pumpType = part->type;
		Part_remove(part);
		return true;
	}
	return false;
}

void Part_liquidUpdate(Part* p, Block* c, double adv, double x1, double x2, double xr1, double yr1, double yr2, double frc) {
	p->vel.x += adv*c->vel.x;
	p->vel.y += adv*c->vel.y;
	if (Part_pos3(&p->pos,0,1) != Part_EMPTY) {
		if (Part_pos3(&p->pos,-1,0) == Part_EMPTY)
			p->vel.x -= Random_2(x1, x2);
		if (Part_pos3(&p->pos,1,0) == Part_EMPTY)
			p->vel.x += Random_2(x1, x2);
	}
	p->vel.x += Random_2(-xr1, xr1);
	p->vel.y += Random_2(yr1, yr2);
	Vec_mul(&p->vel, frc);
	Vector airvel = c->vel;
	Vec_add(&airvel, &p->vel);
	Part_blow(p, &airvel);
}
