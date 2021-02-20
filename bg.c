#include "common.h"
#include "menu.h"
#include "draw.h"
#include "part.h"
#include "bg.h"

BgPixel Bg_pixels[WIDTH][H+8+1]; //idk why this goes to 309
BgPixel* const Bg_pixels_end = &Bg_pixels[WIDTH-1][H+8+1-1]+1;

void Bg_reset(void) {
	BgPixel* px;
	for (px=Bg_pixels[0]; px<Bg_pixels_end; px++)
		*px = (BgPixel){0};
}

void Bg_render(void) {
	int x,y;
	switch (Menu_bgMode) {
	case Bg_NONE:
	default:
		for (y=0;y<H+8;y++) {
			for (x=0;x<WIDTH;x++) {
				*Draw_pxRef(x, y) = Part_at[y][x] == Part_BLOCK ? 0x606060 : 0;
			}
		}
		break;
	case Bg_AIR: case Bg_LINE:;
		for (y=2; y<(H+8)/4; y++) {
			for (x=2; x<(W+8)/4; x++) {
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
		if(Menu_bgMode==Bg_LINE){
			Block* c;
			forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
				if (c->block==0) {
					Vector e = c->vel;
					double r = Vec_fastNormalize(&e);
					if (r>=0.2) {
						if (r>8) r=8;
						int f = 48*r;
						if (f>96) f=96;
						int d = c-Part_blocks[0];
						int n = d/(WIDTH/4);
						d = d%(WIDTH/4);
						n*=4;
						d*=4;
						Draw_line(d+e.x*r*10, n+e.y*r*10, d, n, f<<16);
					}
				}
			}
		}
	}
}
