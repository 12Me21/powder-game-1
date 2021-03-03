#include "common.h"
#include "menu.h"
#include "draw.h"
#include "elements.h"
#include "part.h"
#include "cell.h"
#include "bg.h"

extern Color grp[HEIGHT][WIDTH];

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
		if (Menu_bgMode==Bg_LINE) {
			Block* c;
			forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
				if (c->block==0) {
					Point e = c->vel;
					real r = Vec_fastNormalize(&e);
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
		break;
	case Bg_SHADE:
		for (y=8;y<H+8;y++) {
			Color* row = grp[y];
			for (x=8;x<W+8-1;x++) {
				int r = (RED(row[x])+RED(row[x+1]))>>1;
				int g = (GREEN(row[x])+GREEN(row[x+1]))>>1;
				int b = (BLUE(row[x])+BLUE(row[x+1]))>>1;
				row[x] = RGB(r,g,b);
			}
			for (x=W+8-1;x>=8-1;x--) {
				int r = (RED(row[x])+RED(row[x-1]))>>1;
				int g = (GREEN(row[x])+GREEN(row[x-1]))>>1;
				int b = (BLUE(row[x])+BLUE(row[x-1]))>>1;
				row[x] = RGB(r,g,b);
			}
		}
		for (x=8;x<W+8;x++) {
			for (y=8;y<H+8-1;y++) {
				int r = (RED(grp[y][x])+RED(grp[y+1][x]))>>1;
				int g = (GREEN(grp[y][x])+GREEN(grp[y+1][x]))>>1;
				int b = (BLUE(grp[y][x])+BLUE(grp[y+1][x]))>>1;
				grp[y][x] = RGB(r,g,b);
			}
			for (y=H+8-1;y>=8-1;y--) {
				int r = (RED(grp[y][x])+RED(grp[y-1][x]))>>1;
				int g = (GREEN(grp[y][x])+GREEN(grp[y-1][x]))>>1;
				int b = (BLUE(grp[y][x])+BLUE(grp[y-1][x]))>>1;
				grp[y][x] = RGB(r,g,b);
			}
		}
		for (y=0;y<H+8;y++) {
			for (x=0;x<WIDTH;x++)
				if (Part_at[y][x] == Part_BLOCK)
					grp[y][x] = 0x606060;
		}
		break;
	case Bg_LIGHT:;
		Color* grpb = &grp[0][0];
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*8;a--) {
			if ((&Part_at[0][0])[a]==Part_BLOCK)
				grpb[a] = 0x606060;
			else {
				int r = (220*RED(grpb[a]))>>8;
				int g = (220*GREEN(grpb[a]))>>8;
				int b = (220*BLUE(grpb[a]))>>8;
				grpb[a] = RGB(r,g,b);
			}
		}
		break;
	case Bg_TOON:
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*7;a--) {
			Part* p = Part_at[0][a];
			if (p==Part_BLOCK)
				grp[0][a] = 0x606060;
			else if (p==Part_BALL)
				grp[0][a] = 0;
			else if (p==Part_BGFAN)
				grp[0][a] = 0x8080FF;
			else if (p==Part_EMPTY) {
				grp[0][a] = Part_at[0][a+1]>=Part_0 ?
					ELEMENTS[Part_at[0][a+1]->type].color :
					Part_at[0][a-1]>=Part_0 ?
					ELEMENTS[Part_at[0][a-1]->type].color :
					Part_at[1][a]>=Part_0 ?
					ELEMENTS[Part_at[1][a]->type].color :
					Part_at[-1][a]>=Part_0 ?
					ELEMENTS[Part_at[-1][a]->type].color :
					Part_at[1][a+1]>=Part_0 ?
					ELEMENTS[Part_at[1][a+1]->type].color :
					Part_at[1][a-1]>=Part_0 ?
					ELEMENTS[Part_at[1][a-1]->type].color :
					Part_at[-1][a+1]>=Part_0 ?
					ELEMENTS[Part_at[-1][a+1]->type].color :
					Part_at[-1][a-1]>=Part_0 ?
					ELEMENTS[Part_at[-1][a-1]->type].color :
					0;
			} else if (p>=Part_0) {
				grp[0][a] = ELEMENTS[p->type].color;
			}
		}
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*8;a--) {
			if (grp[0][a] == 0) {
				if (grp[0][a+1] && grp[0][a+1]!=0xEEEEEE)
					grp[0][a] = 0xEEEEEE;
				else if (grp[0][a-1] && grp[0][a-1]!=0xEEEEEE)
					grp[0][a] = 0xEEEEEE;
				if (grp[1][a] && grp[1][a]!=0xEEEEEE)
					grp[0][a] = 0xEEEEEE;
				if (grp[-1][a] && grp[-1][a]!=0xEEEEEE)
					grp[0][a] = 0xEEEEEE;
			}
		}
	}
}
