#include <string.h>
#include <math.h>
#include "../common.h"
#include "../menu.h"
#include "draw.h"
#include "../elements.h"
#include "../dot.h"
#include "../block.h"
#include "bg.h"

BgPixel Bg_pixels[HEIGHT][WIDTH];
BgPixel* const Bg_pixels0 = Bg_pixels[0];
BgPixel* const Bg_pixels_end = &Bg_pixels[HEIGHT-1][WIDTH-1]+1;

void Bg_reset(void) {
	for (BgPixel* px=Bg_pixels[0]; px<Bg_pixels_end; px++)
		*px = (BgPixel){0,0,0};
}

#define for_visibleBlocks(x,y) for (axis y=2; y<HEIGHT/4-2; y++) for (axis x=2; x<WIDTH/4-2; x++)

#define for_visibleRows(y) for (axis y=8; y<H+8; y++)
#define for_visibleColumns(x) for (axis x=8; x<W+8; x++)
#define for_visiblePixels(x,y) for_visibleRows(y) for_visibleColumns(x)

#define for_visiblePixels0rev(i) for (Offset i=(HEIGHT-8)*WIDTH;i>=8*WIDTH;i--)
#define for_visiblePixels0rev2(i) for (Offset i=(HEIGHT-8)*WIDTH;i>=0;i--)

void f(axis,axis,axis,axis);
static inline void do_blend(typeof(f) func) {
	for_visibleRows(y) {
		for (axis x=8; x<W+8-1; x++)
			func(x,y,1,0);
		for (axis x=W+8-1; x>=8+1; x--)
			func(x,y,-1,0);
	}
	for_visibleColumns(x) {
		for (axis y=8; y<H+8-1; y++)
			func(x,y,0,1);
		for (axis y=H+8-1; y>=8+1; y--)
			func(x,y,0,-1);
	}
}

// render background (this is the first render function to run)
void Bg_render(void) {
	Offset i;
	switch (Menu_bgMode) {
	case Bg_NONE:
	default:;
		for (Offset i=0;i<WIDTH*HEIGHT;i++)
			grp0[i] = Dot_grid0[i]==Dot_BLOCK ? 0x606060 : 0;
		break;
	case Bg_AIR: case Bg_LINE:;
		for_visibleBlocks (x,y) {
			Block* block = &Blocks[y][x];
			Color color;
			if (block->block==Block_BLOCK) {
				color = 0x606060;
			} else {
				int q=0, g=0;
				if (block->pres>0)
					g = atMost(block->pres*48, 96);
				if (block->pres<0)
					q = atMost(-block->pres*48, 96);
				color = RGB(0,g,q);
			}
			Draw_rectangle(x*4, y*4, 4, 4, color);
		}
		if (Menu_bgMode==Bg_LINE) {
			for_visibleBlocks (x,y) {
				Block* c = &Blocks[y][x];
				if (c->block==Block_EMPTY) {
					Point e = c->vel;
					real vel = Vec_fastNormalize(&e);
					if (vel>=0.2) {
						vel = atMost(vel, 8);
						int f = atMost(48*vel, 96);
						Draw_line(x*4+e.x*vel*10, y*4+e.y*vel*10, x*4, y*4, f<<16); // should these be centered in the block?
					}					
				}
			}
		}
		break;
	case Bg_BLUR:
		for_visiblePixels0rev (i) {
			if (Dot_grid0[i]==Dot_BLOCK)
				grp0[i] = 0x606060;
			else {
				int r = RED(grp0[i])*230/256;
				int g = GREEN(grp0[i])*230/256;
				int b = BLUE(grp0[i])*230/256;
				grp0[i] = RGB(r,g,b);
			}
		}
		break;
	case Bg_SHADE:; {
			inline void func(int x,int y, int dx, int dy) {
				Color d = grp[y][x];
				Color a = grp[y+dy][x+dx];
				int r = (RED(d)+RED(a))/2;
				int g = (GREEN(d)+GREEN(a))/2;
				int b = (BLUE(d)+BLUE(a))/2;
				grp[y][x] = RGB(r,g,b);
			}
			do_blend(func);
			for_visiblePixels0rev2 (a) {
				if (Dot_grid0[a] == Dot_BLOCK)
					grp0[a] = 0x606060;
			}
			break;
		} case Bg_AURA:;
		memset(Bg_pixels, 0, sizeof(Bg_pixels));
		for_visibleBlocks (x,y) {
			Block* e = &Blocks[y][x];
			real vx = fabs(e->vel.x);
			real vy = fabs(e->vel.y);
			if (vx!=0 || vy!=0) {
				real q = 1.0/(vx+vy);
				int gg = vx*q*0xFFFF;
				int qq = vy*q*0xFFFF;
				axis sx = sign(e->vel.x);
				axis sy = sign(e->vel.y);
				Offset r = (y*4*WIDTH)+(x*4);
				// iterate over 4x4 square
				for (int a=0; a<16; a++) {
					int w = RED(grp0[r]);
					Bg_pixels0[r+sx].auraR += w*gg;
					Bg_pixels0[r+sy*WIDTH].auraR += w*qq;
					w = GREEN(grp0[r]);
					Bg_pixels0[r+sx].auraG += w*gg;
					Bg_pixels0[r+sy*WIDTH].auraG += w*qq;
					w = BLUE(grp0[r]);
					Bg_pixels0[r+sx].auraB += w*gg;
					Bg_pixels0[r+sy*WIDTH].auraB += w*qq;
					r += (Offset[]){1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3,1,1,1,WIDTH-3}[a];
				}
			}
		}
		/*inline int ff(int x) {
		  if (x>255) return 255;
		  return x;
		  }*/
		for_visiblePixels(x,y) {
			BgPixel* p = &Bg_pixels[y][x];
			grp[y][x] = Dot_at[y][x]==Dot_BLOCK ? 0x606060 : RGB(
				atMost(p->auraR>>16, 255),
				atMost(p->auraG>>16, 255),
				atMost(p->auraB>>16, 255)
			);
		}
		
		break;
	case Bg_LIGHT:;
		for_visiblePixels0rev (i) {
			if (Dot_grid0[i]==Dot_BLOCK)
				grp0[i] = 0x606060;
			else {
				int r = RED(grp0[i])*220/256;
				int g = GREEN(grp0[i])*220/256;
				int b = BLUE(grp0[i])*220/256;
				grp0[i] = RGB(r,g,b);
			}
		}
		break;
	case Bg_TOON:
		for (i=(H+8)*WIDTH; i>=WIDTH*7; i--) { // 7 is probably a typo in original
			Dot* p = Dot_grid0[i];
			if (p==Dot_BLOCK)
				grp0[i] = 0x606060;
			else if (p==Dot_BALL)
				grp0[i] = 0;
			else if (p==Dot_BGFAN)
				grp0[i] = 0x8080FF;
			else if (p==Dot_EMPTY) {
				grp0[i] = Dot_grid0[i+1]>=Dot_0 ?
					ELEMENTS[Dot_grid0[i+1]->type].color :
					Dot_grid0[i-1]>=Dot_0 ?
					ELEMENTS[Dot_grid0[i-1]->type].color :
					Dot_at[1][i]>=Dot_0 ?
					ELEMENTS[Dot_at[1][i]->type].color :
					Dot_at[-1][i]>=Dot_0 ?
					ELEMENTS[Dot_at[-1][i]->type].color :
					Dot_at[1][i+1]>=Dot_0 ?
					ELEMENTS[Dot_at[1][i+1]->type].color :
					Dot_at[1][i-1]>=Dot_0 ?
					ELEMENTS[Dot_at[1][i-1]->type].color :
					Dot_at[-1][i+1]>=Dot_0 ?
					ELEMENTS[Dot_at[-1][i+1]->type].color :
					Dot_at[-1][i-1]>=Dot_0 ?
					ELEMENTS[Dot_at[-1][i-1]->type].color :
					0x000000;
			} else if (p>=Dot_0) {
				grp0[i] = ELEMENTS[p->type].color;
			}
		}
		for_visiblePixels0rev (a) {
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
		break;
	case Bg_MESH:;
		for_visiblePixels0rev2 (i) {
			grp0[i] = Dot_grid0[i]==Dot_BLOCK ? 0x606060 : 0;
		}
		for_visibleBlocks (x,y) {
			Block* cell = &Blocks[y][x];
			if (cell->block!=Block_EMPTY) continue;
			real vel = Vec_fastDist(cell->vel);
			if (vel<0.2) continue;
			vel = atMost(vel, 2);
			int g = atMost(vel*48, 96);
			int r = 0;
			if (cell->pres>0)
				r = atMost(cell->pres*48*r, 96);
			int b = 0;
			if (cell->pres<0)
				b = atMost(-cell->pres*48*r, 96);
			int d = x*4 + 5*cell->vel.x;
			int n = y*4 + 5*cell->vel.y;
			cell = &Blocks[y][x+1];
			int w = (x+1)*4 + 5*cell->vel.x;
			int h = (y)*4 + 5*cell->vel.y;
			Draw_line(d,n,w,h,RGB(r,g,b));
			cell = &Blocks[y+1][x];
			w = (x)*4 + 5*cell->vel.x;
			h = (y+1)*4 + 5*cell->vel.y;
			Draw_line(d,n,w,h,RGB(r,g,b));
		}
		break;
	case Bg_GRAY:
		for_visibleBlocks (x,y) {
			Block* cell = &Blocks[y][x];
			Color color;
			if (cell->block==Block_BLOCK)
				color = 0x606060;
			else {
				int f = 0;
				if (cell->pres>0)
					f = atMost(cell->pres*48, 72);
				if (cell->pres<0)
					f = atMost(-cell->pres*48, 72);
				color = RGB(f,f,f);
			}
			Draw_rectangle(x*4,y*4,4,4,color);
		}
		break;
	case Bg_TRACK:;
		const Offset blockOffsets[] = {0,1,2,3,WIDTH+0,WIDTH+1,WIDTH+2,WIDTH+3,2*WIDTH+0,2*WIDTH+1,2*WIDTH+2,2*WIDTH+3,3*WIDTH+0,3*WIDTH+1,3*WIDTH+2,3*WIDTH+3};
		for_visibleBlocks (x,y) {
			Block* cell = &Blocks[y][x];
			if (cell->block==Block_BLOCK)
				Draw_rectangle(x*4,y*4,4,4,0x606060);
			else {
				int n = 256 - (int)atMost(fabs(12*cell->pres),32); //should the conversion to int be before or after abs?
				if (n!=256) {
					for (int i=0;i<16;i++) {
						Offset e = x*4+y*4*WIDTH+blockOffsets[i];
						int r = RED(grp0[e])*n / 256;
						int g = GREEN(grp0[e])*n / 256;
						int b = BLUE(grp0[e])*n / 256;
						grp0[e] = RGB(r,g,b);
					}
				}
			}
		}
		break;
	case Bg_DARK:
		for_visiblePixels0rev2 (a) {
			BgPixel* px = &Bg_pixels0[a];
			Dot* p = Dot_grid0[a];
			if (p<Dot_0)
				px->light = 8*px->light/9;
			else if (p->type==Elem_FIRE||p->type==Elem_MAGMA||p->type==Elem_LASER||p->type==Elem_SPARK)
				px->light = 25500;
			else if (p->type==Elem_TORCH||p->type==Elem_THUNDER)
				px->light = 255000;
			else
				px->light = 8*px->light/9;
		}
		for_visiblePixels0rev2 (a) {
			grp0[a] = Dot_grid0[a]==Dot_BLOCK ? 0x606060 : 0;
		}
		break;
	case Bg_TG:;
		Dot_FOR (p) {
			Bg_pixels[(int)p->pos.y][(int)p->pos.x].light = p->type[ELEMENTS].temperature;
		}
		{
			inline void func(int x,int y, int dx, int dy) {
				Bg_pixels[y][x].light = Bg_pixels[y+dy][x+dx].light = (Bg_pixels[y][x].light+Bg_pixels[y+dy][x+dx].light)/2;
			}
			do_blend(func);
		}
		for_visiblePixels0rev2 (i) {
			int l = Bg_pixels0[i].light;
			int r,g,b;
			if (l<0) { // purple -> black
				r = atMost(-l*128/0x400, 255);
				g = 0;
				b = atMost(-l*255/0x400, 255);
			} else if (l<0x400) { // black -> blue
				r = g = 0;
				b = l*255/1024;
			} else if (l<0x800) { // blue -> bluegreen
				r = 0;
				g = (l-0x400)*255/1024;
				b = 255;
			} else if (l<0xC00) { // bluegreen -> green
				r = 0;
				g = 255;
				b = 255 - (l-0x800)*255/1024;
			} else if (l<0x1000) { // green -> yellow
				r = (l-0xC00)*255/1024;
				g = 255;
				b = 0;
			} else if (l<0x1800) { // yellow -> red
				r = 255;
				g = 255 - (l-0x1000)*255/2048;
				b = 0;
			} else { // red -> white
				r = 255;
				g = b = atMost((l-0x1800)*255/2048, 255);
			}
			grp0[i] = RGB(r,g,b);
		}
		for_visiblePixels0rev2 (i) {
			if (Dot_grid0[i]==Dot_BLOCK)
				grp0[i] = 0x606060;;
		}
		break;
	case Bg_SILUET:
		for_visiblePixels0rev (a) {
			if (Dot_grid0[a]==Dot_BLOCK)
				grp0[a] = 0;
			else if (Dot_grid0[a]==Dot_EMPTY) {
				int r = 0xFF- (0xFF-RED(grp0[a]))/2;
				int g = 0xFF- (0xFF-GREEN(grp0[a]))/2;
				int b = 0xFF- (0xFF-BLUE(grp0[a]))/2;
				grp0[a] = RGB(r,g,b);
			}
		}
	}
}

// this runs after everything is drawn
void Bg_render2(void) {
	if (Menu_bgMode!=Bg_DARK) return;
	inline void func(axis x, axis y, axis dx, axis dy) {
		Bg_pixels[y][x].light = (Bg_pixels[y][x].light+Bg_pixels[y+dy][x+dx].light)/2;
	}
	do_blend(func);
	for_visiblePixels0rev2 (a) {
		int l = Bg_pixels0[a].light;
		if (l<=0)
			grp0[a] = 0;
		else {
			l = atMost(l, 255);
			int r = ((RED(grp0[a]))*l)/256;
			int g = ((GREEN(grp0[a]))*l)/256;
			int b = ((BLUE(grp0[a]))*l)/256;
			grp0[a] = RGB(r,g,b);
		}
	}
}
