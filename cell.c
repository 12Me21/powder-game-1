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
		for (Block* c=Part_blocks[0]; c<Part_blocks_end; c++)
			if (!c->block)
				open++;
		if (open>0) {
			pd /= open;
			for (Block* c=Part_blocks[0]; c<Part_blocks_end; c++)
				if (!c->block)
					c->pres += pd;
			pd = 0;
		}
	}
}

void Cell_update(void) {
	for (Block* c=Part_blocks[0]; c<Part_blocks_end; c++)
		c->vel2 = c->vel;
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* cell = &Part_blocks[b][d];
			if (cell->block!=1) {
				Point vel = cell->vel;
				real magv = Vec_fastNormalize(&vel);
				if (magv!=0) {
					real magvx = fabs(vel.x);
					real magvy = fabs(vel.y);
					real rx = magvx/(magvx+magvy)*magv*0.5;
					real ry = magvy/(magvx+magvy)*magv*0.5;
					Point sx,sy;
					sx.xy = vel.xy * rx;
					sy.xy = vel.xy * ry;
					int signvx = vel.x<0 ? -1 : 1;
					int signvy = vel.y<0 ? -1 : 1;
					
					Block* diag = &Part_blocks[b+signvy][d+signvx];
					Block* adjx;
					Block* adjy;
					if (magvx>magvy) {
						adjx = &Part_blocks[b][d+signvx];
						adjy = diag;
						cell->vel2.xy -= sx.xy;
						if (adjx->block <= 0)
							cell->pres -= rx;
						else
							cell->vel2.xy -= sx.xy;
						cell->vel2.xy -= sy.xy;
						if (adjy->block <= 0)
							cell->pres -= ry;
						else
							cell->vel2.xy -= sy.xy;
					} else {
						adjx = diag;
						adjy = &Part_blocks[b+signvy][d];
						cell->vel2.xy -= sy.xy;
						if (adjy->block <= 0)
							cell->pres -= ry;
						else
							cell->vel2.xy -= sy.xy;
						cell->vel2.xy -= sx.xy;
						if (adjx->block <= 0)
							cell->pres -= rx;
						else
							cell->vel2.xy -= sx.xy;
					}
					if (adjx->block <= 0) {
						adjx->vel2.xy += sx.xy;
						adjx->pres += rx;
					}
					if (adjy->block <= 0) {
						adjy->vel2.xy += sy.xy;
						adjy->pres += ry;
					}
				}
			}
		}
	} //
	for (Block* cell=Part_blocks[0]; cell<Part_blocks_end; cell++)
		cell->pres2 = cell->pres;
	
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* a = &Part_blocks[b][d];
			if (a->block == 1) continue;
			inline void pcheck(int x, int y, real m) {
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
	for (Block* c=Part_blocks[0]; c<Part_blocks_end; c++) {
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
