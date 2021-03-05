#include <math.h>
#include "common.h"
#include "part.h"
#include "cell.h"
#include "menu.h"

real pd = 0;

Block Part_blocks[HEIGHT/4][WIDTH/4];
Block* const Part_blocks_end = &Part_blocks[HEIGHT/4-1][WIDTH/4-1]+1;

void Cell_update1(void) {
	if (pd!=0) {
		int open = 0;
		Block* c;
		forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
			if (!c->block)
				open++;
		if (open>0) {
			pd /= open;
			forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
				if (!c->block)
					c->pres += pd;
			pd = 0;
		}
	}
}

void Cell_update(void) {
	Block* c;
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
		c->vel2 = c->vel;
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* a = &Part_blocks[b][d];
			if (a->block!=1) {
				Point c = a->vel;
				real nn = Vec_fastNormalize(&c);
				if (nn!=0) {
					real r = fabs(c.x);
					real w = fabs(c.y);
					real y = r/(r+w)*nn*0.5;
					real n = w/(r+w)*nn*0.5;
					Point e = Vec_mul2(c, y);
					Point f = Vec_mul2(c, n);
					int z = c.x<0 ? -1 : 1;
					int v = c.y<0 ? -1 : 1;
					Block* horiz = &Part_blocks[b][d+z];
					Block* vert = &Part_blocks[b+v][d];
					Block* both = &Part_blocks[b+v][d+z];
					if (r>w) {
						if (horiz->block <= 0) {
							Vec_sub(&a->vel2, e);
							Vec_add(&horiz->vel2, e);
							horiz->pres += y;
							a->pres -= y;
						} else {
							Vec_sub(&a->vel2, e); //yes, twice.
							Vec_sub(&a->vel2, e);
						}
						if (both->block <= 0) {
							Vec_sub(&a->vel2, f);
							Vec_add(&both->vel2, f);
							a->pres -= n;
							both->pres += n;
						} else {
							Vec_sub(&a->vel2, f);
							Vec_sub(&a->vel2, f);
						}
					} else {
						if (vert->block <= 0) {
							Vec_sub(&a->vel2, f);
							Vec_add(&vert->vel2, f);
							a->pres -= n;
							vert->pres += n;
						} else {
							Vec_sub(&a->vel2, f);
							Vec_sub(&a->vel2, f);
						}
						if (both->block <= 0) {
							Vec_sub(&a->vel2, e);
							Vec_add(&both->vel2, e);
							a->pres -= y;
							both->pres += y;
						} else {
							Vec_sub(&a->vel2, e);
							Vec_sub(&a->vel2, e);
						}
					}
				}
			}
		}
	} //
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
		c->pres2 = c->pres;
	}
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* a = &Part_blocks[b][d];
			if (a->block == 1) continue;
			void pcheck(int x, int y, real m) {
				Block* o = &Part_blocks[b+y][d+x];
				if (o->block <= 0) {
					real diff = (a->pres - o->pres);
					a->vel2.x += diff*m*x;
					a->vel2.y += diff*m*y;
					a->pres2 -= diff*m;
				}
			}
			pcheck(-1, 0,0.0625);
			pcheck( 1, 0,0.0625);
			pcheck( 0,-1,0.0625);
			pcheck( 0, 1,0.0625);
			pcheck(-1,-1,0.044194173);
			pcheck( 1,-1,0.044194173);
			pcheck(-1, 1,0.044194173);
			pcheck( 1, 1,0.044194173);
		}
	}
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
		if (c->block != -1) { //woah -1??
			c->vel = c->vel2;
			c->pres = c->pres2;
		} else {
			c->pres = 0;
			c->vel = (Point){0,0};
		}
	}
}

void Cell_addPressure(Cell* c, real p) {
	c->pres += p;
	pd -= p;
}

void Cell_clearPressure(Cell* c) {
	pd += c->pres;
	c->pres = 0;
}
