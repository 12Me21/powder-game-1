#include <math.h>
#include "common.h"
#include "dot.h"
#include "block.h"
#include "menu.h"
#include "save.h"

real pd = 0;

Block Blocks[HEIGHT/4][WIDTH/4];
Block* const Blocks_END = &Blocks[HEIGHT/4-1][WIDTH/4-1]+1;

void Block_update1(void) {
	if (pd!=0) {
		int open = 0;
		Block_FOR (c) {
			if (!c->block)
				open++;
		}
		if (open>0) {
			pd /= open;
			Block_FOR (c) {
				if (!c->block)
					c->pres += pd;
			}
			pd = 0;
		}
	}
}

void Block_update(void) {
	Block_FOR (c) {
		c->vel2 = c->vel;
	}
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* cell = &Blocks[b][d];
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
					
					Block* diag = &Blocks[b+signvy][d+signvx];
					Block* adjx;
					Block* adjy;
					if (magvx>magvy) {
						adjx = &Blocks[b][d+signvx];
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
						adjy = &Blocks[b+signvy][d];
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
	Block_FOR (cell) {
		cell->pres2 = cell->pres;
	}
	
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* a = &Blocks[b][d];
			if (a->block == 1) continue;
			inline void pcheck(int x, int y, real m) {
				Block* o = &Blocks[b+y][d+x];
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
	Block_FOR (c) {
		if (c->block != -1) { //woah -1??
			c->vel = c->vel2;
			c->pres = c->pres2;
		} else {
			c->pres = 0;
			c->vel = (Point){0,0};
		}
	}
}

void Block_addPressure(Block* c, real p) {
	c->pres += p;
	pd -= p;
}

void Block_clearPressure(Block* c) {
	pd += c->pres;
	c->pres = 0;
}

void Block_save(SavePixel save[H][W]) {
	for (axis y=0; y<H; y++)
		for (axis x=0; x<W; x++)
			if (Blocks[y/4+2][x/4+2].block==1)
				save[y][x].type = Elem_BLOCK;
}

void Block_reset(bool drawBorder) {
	for (axis y=0; y<HEIGHT/4; y++) {
		for (axis x=0; x<WIDTH/4; x++) {
			Block* cell = &Blocks[y][x];
			*cell = (Block){.vel={0,0}, .vel2={0,0}, .pres=0, .pres2=0, .block=0};
			if (x<2 || y<2 || x>=WIDTH/4-2 || y>=HEIGHT/4-2)
				cell->block = -1;
			else if (x<3 || y<3 || x>=WIDTH/4-3 || y>=HEIGHT/4-3)
				cell->block = 1;
		}
	}
	// [] - offscreen blocks
	// ## - screen border blocks
	//    - empty space
	
	//[][][][][]:::[][][][][]
	//[][][][][]:::[][][][][]
	//[][]######:::######[][]
	//[][]##           ##[][]
	//[][]##           ##[][]
	//::::::           ::::::
	//[][]##           ##[][]
	//[][]##           ##[][]
	//[][]######:::######[][]
	//[][][][][]:::[][][][][]
	//[][][][][]:::[][][][][]
}
