#include "common.h"
#include "menu.h"
#include "draw.h"
#include "part.h"
#include "bg.h"

BgPixel Bg_pixels[WIDTH][309];

int G=104,kd=79;
void Bg_render(void) {
	int x,y;
	switch (Menu_bgMode) {
	case Bg_NONE:
	default:
		for (y=0;y<308;y++) {
			for (x=0;x<WIDTH;x++) {
				*Draw_pxRef(x, y) = Part_at[y][x] == Part_BLOCK ? 0x606060 : 0;
			}
		}
		break;
	case Bg_AIR: case Bg_LINE:;
		int a = 2*G+2;
		for (y=2; y<77; y++) {
			for (x=2; x<102; x++) {
				Block* block = &Part_blocks[y][x];
				if (block->block == 1) {
					Draw_rectangle(x*4, y*4, 4, 4, 0x606060);
				} else {
					int q=0, g=0;
					if (block->pres>0) {
						g = block->pres*48;
						if (g>96) g=96;
					}
					if (block->pres<0) {
						q = -block->pres*48;
						if (q>96) q=96;
					}
					Draw_rectangle(x*4, y*4, 4, 4, g<<8|q);
				}
			}
		}
	}
}
