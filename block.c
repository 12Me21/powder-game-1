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
			if (c->block==Block_EMPTY)
				open++;
		}
		if (open>0) {
			pd /= open;
			Block_FOR (c) {
				if (c->block==Block_EMPTY)
					c->pres += pd;
			}
			pd = 0;
		}
	}
}

static void pcheck(Block* a, int b, int d, int x, int y, real m) {
	Block* o = &Blocks[b+y][d+x];
	if (o->block!=Block_BLOCK) {
		real diff = (a->pres - o->pres);
		a->vel2.x += diff*m*x;
		a->vel2.y += diff*m*y;
		a->pres2 -= diff*m;
	}
}

void Block_update(void) {
	Block_FOR (c) {
		c->vel2 = c->vel;
	}
	for (int b=2; b<(HEIGHT)/4-2; b++) {
		for (int d=2; d<(WIDTH)/4-2; d++) {
			Block* cell = &Blocks[b][d];
			if (cell->block!=Block_BLOCK) {
				Point vel = cell->vel;
				real magv = Vec_fastNormalize(&vel);
				if (magv!=0) {
					real magvx = fabs(vel.x);
					real magvy = fabs(vel.y);
					real rx = magvx/(magvx+magvy)*magv*0.5f;
					real ry = magvy/(magvx+magvy)*magv*0.5f;
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
						if (adjx->block!=Block_BLOCK)
							cell->pres -= rx;
						else
							cell->vel2.xy -= sx.xy;
						cell->vel2.xy -= sy.xy;
						if (adjy->block!=Block_BLOCK)
							cell->pres -= ry;
						else
							cell->vel2.xy -= sy.xy;
					} else {
						adjx = diag;
						adjy = &Blocks[b+signvy][d];
						cell->vel2.xy -= sy.xy;
						if (adjy->block!=Block_BLOCK)
							cell->pres -= ry;
						else
							cell->vel2.xy -= sy.xy;
						cell->vel2.xy -= sx.xy;
						if (adjx->block!=Block_BLOCK)
							cell->pres -= rx;
						else
							cell->vel2.xy -= sx.xy;
					}
					if (adjx->block!=Block_BLOCK) {
						adjx->vel2.xy += sx.xy;
						adjx->pres += rx;
					}
					if (adjy->block!=Block_BLOCK) {
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
			if (a->block==Block_BLOCK) continue;
			pcheck(a,b,d,-1, 0,0.0625);
			pcheck(a,b,d, 1, 0,0.0625);
			pcheck(a,b,d, 0,-1,0.0625);
			pcheck(a,b,d, 0, 1,0.0625);
			pcheck(a,b,d,-1,-1,0.044194173);
			pcheck(a,b,d, 1,-1,0.044194173);
			pcheck(a,b,d,-1, 1,0.044194173);
			pcheck(a,b,d, 1, 1,0.044194173);
		}
	}
	Block_FOR (c) {
		if (c->block!=Block_OFFSCREEN) {
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
			if (Block_at(x+8,y+8)->block==Block_BLOCK)
				save[y][x].type = Elem_BLOCK;
}

Block* Block_at(axis x, axis y) {
	return &Blocks[y/4][x/4];
}

void Block_reset(bool drawBorder) {
	for (axis y=0; y<HEIGHT/4; y++) {
		for (axis x=0; x<WIDTH/4; x++) {
			Block* cell = &Blocks[y][x];
			*cell = (Block){.vel={0,0}, .vel2={0,0}, .pres=0, .pres2=0, .block=0};
			if (x<2 || y<2 || x>=WIDTH/4-2 || y>=HEIGHT/4-2)
				cell->block = Block_OFFSCREEN;
			else if (x<3 || y<3 || x>=WIDTH/4-3 || y>=HEIGHT/4-3)
				cell->block = Block_BLOCK;
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
