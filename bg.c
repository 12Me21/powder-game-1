#include <string.h>
#include <math.h> //todo: define macros for abs/fabs etc.
#include "common.h"
#include "menu.h"
#include "draw.h"
#include "elements.h"
#include "part.h"
#include "cell.h"
#include "bg.h"

extern Color grp[HEIGHT][WIDTH];
Color* grp0 = &grp[0][0];

BgPixel Bg_pixels[WIDTH][H+8+1]; //idk why this goes to 309
BgPixel* const Bg_pixels0 = Bg_pixels[0];
BgPixel* const Bg_pixels_end = &Bg_pixels[WIDTH-1][H+8+1-1]+1;

void Bg_reset(void) {
	for (BgPixel* px=Bg_pixels[0]; px<Bg_pixels_end; px++)
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
			for (Block* c=Part_blocks[0]; c<Part_blocks_end; c++) {
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
	case Bg_AURA:;
		memset(Bg_pixels, 0, sizeof(Bg_pixels));
		for (axis c=2;c<(HEIGHT/4)-2;c++) {
			for (axis b=2;b<(WIDTH/4)-2;b++) {
				Cell* e = &Part_blocks[c][b];
				real g = fabs(e->vel.x);
				real a = fabs(e->vel.y);
				if (g!=0 || a!=0) {
					real q = 1/(g+a);
					int gg = g*q*0xFFFF;
					int qq = a*q*0xFFFF;
					axis n=0, d=0;
					if (e->vel.x<0)
						d=-1;
					else if (e->vel.x>0)
						d=1;
					if (e->vel.y<0)
						n=-WIDTH;
					else if (e->vel.y>0)
						n=WIDTH;
					int r = c*4*WIDTH+b*4;
					for (int a=0; a<16; a++) {
						int w = RED(grp0[r]);
						Bg_pixels0[r+d].light += w*gg;
						Bg_pixels0[r+n].light += w*qq;
						w = GREEN(grp0[r]);
						Bg_pixels0[r+d].aura1 += w*gg;
						Bg_pixels0[r+n].aura1 += w*qq;
						w = BLUE(grp0[r]);
						Bg_pixels0[r+d].aura2 += w*gg;
						Bg_pixels0[r+n].aura2 += w*qq;
						r += (Offset[]){1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3}[a];
					}
				}
			}
		}
		inline int ff(int x) {
			if (x>255) return 255;
			return x;
		}
		for (axis y=8;y<H+8-1;y++) {
			for (axis x=8;x<W+8;x++) {
				BgPixel* p = &Bg_pixels[y][x];
				grp[y][x] = Part_at[y][x]==Part_BLOCK ? 0x606060 : RGB(
					ff(p->light>>16),
					ff(p->aura1>>16),
					ff(p->aura2>>16)
				);
			}
		}
		
		break;
	case Bg_LIGHT:;
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*8;a--) {
			if ((&Part_at[0][0])[a]==Part_BLOCK)
				grp0[a] = 0x606060;
			else {
				int r = (220*RED(grp0[a]))>>8;
				int g = (220*GREEN(grp0[a]))>>8;
				int b = (220*BLUE(grp0[a]))>>8;
				grp0[a] = RGB(r,g,b);
			}
		}
		break;
	case Bg_TOON:
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*7;a--) {
			Part* p = Part_at[0][a];
			if (p==Part_BLOCK)
				grp0[a] = 0x606060;
			else if (p==Part_BALL)
				grp0[a] = 0;
			else if (p==Part_BGFAN)
				grp0[a] = 0x8080FF;
			else if (p==Part_EMPTY) {
				grp0[a] = Part_at[0][a+1]>=Part_0 ?
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
					0x000000;
			} else if (p>=Part_0) {
				grp0[a] = ELEMENTS[p->type].color;
			}
		}
		for (Offset a=(H+8)*WIDTH;a>=WIDTH*8;a--) {
			if (grp0[a] == 0) {
				if (grp0[a+1] && grp0[a+1]!=0xEEEEEE)
					grp0[a] = 0xEEEEEE;
				else if (grp0[a-1] && grp0[a-1]!=0xEEEEEE)
					grp0[a] = 0xEEEEEE;
				if (grp[1][a] && grp[1][a]!=0xEEEEEE)
					grp0[a] = 0xEEEEEE;
				if (grp[-1][a] && grp[-1][a]!=0xEEEEEE)
					grp0[a] = 0xEEEEEE;
			}
		}
	}
}
