#include <stdarg.h>

#include "../common.h"
#include "draw.h"
#include "../elements.h"

// we are assuming that colors are represented in a normal format etc.
Color grp[HEIGHT][WIDTH];
Color* const grp0 = &grp[0][0];
Color Menu_grp[MENU_HEIGHT][MENU_WIDTH];

extern const char Draw_FONT[96][12][8];

int blendmode = 0;

Color composite(Color base, Color new, int alpha) {
	int red=0, green=0, blue=0, c;
	switch (blendmode) {
	case 1:
		c = base.r;
		red = ((new.r-c)*alpha>>8)+c;
		c = base.g;
		green = ((new.g-c)*alpha>>8)+c;
		c = base.b;
		blue = ((new.b-c)*alpha>>8)+c;
		break;
	case 2:
		red = (new.r*alpha>>8)+base.r;
		if (red>0xFF) red = 0xFF;
		green = (new.g*alpha>>8)+base.g;
		if (green>0xFF) green = 0xFF;
		blue = (new.b*alpha>>8)+base.b;
		if (blue>0xFF) blue=0xFF;
		break;
	case 3:
		red = base.r-(new.r*alpha>>8);
		if (red<0) red=0;
		green=base.g-(new.g*alpha>>8);
		if (green<0) green=0;
		blue=base.b-(new.b*alpha>>8);
		if (blue<0) blue=0;
		break;
	case 4:
		red=new.r*base.r>>8;
		green=new.g*base.g>>8;
		blue=new.b*base.b>>8;
		break;
	case 5:
		c=base.r;
		red=c+(new.r*c*alpha>>16);
		if (red>0xFF) red=0xFF;
		c=base.g;
		green=c+(new.g*c*alpha>>16);
		if (green>0xFF) green=0xFF;
		c=base.b;
		blue=c+(new.b*c*alpha>>16);
		if (blue>0xFF) blue=0xFF;
		break;
	case 6:
		c=base.r;
		red=c+(alpha-(2*c*alpha>>8));
		c=base.g;
		green=c+(alpha-(2*c*alpha>>8));
		c=base.b;
		blue=c+(alpha-(2*c*alpha>>8));
	}
	return RGB(red,green,blue);
}

void Draw_line(int x1, int y1, int x2, int y2, Color color) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int n = abs(dx);
	if (abs(dy)>n) n = abs(dy);
	if (n<1) n = 1;
	
	dx = (dx<<8)/n;
	dy = (dy<<8)/n;
	x1 = (x1<<8)+127;
	y1 = (y1<<8)+127;
	for (int i=0; i<=n; i++) {
		x2 = x1>>8;
		y2 = y1>>8;
		if (x2>=0 && x2<WIDTH && y2>=0 && y2<HEIGHT)
			grp[y2][x2] = color;
		x1 += dx;
		y1 += dy;
	}
}

void Draw_vline(Point v1, Point v2, Color color) {
	Draw_line(v1.x, v1.y, v2.x, v2.y, color);
}

void Draw_box(int x, int y, int width, int height, Color color) {
	// optimize this
	Draw_line(x,y,x+width-1,y,color);
	Draw_line(x,y+height-1,x+width-1,y+height-1,color);
	Draw_line(x,y,x,y+height-1,color);
	Draw_line(x+width-1,y,x+width-1,y+height-1,color);
}

void Draw_mrectangle(int x, int y, int width, int height, Color color) {
	width = between(width+x, 0, WIDTH);
	height = between(height+y, 0, HEIGHT);
	//if (blendmode==0) {
	for (; y<height; y++) {
		for (int i=x; i<width; i++)
			Menu_grp[y][i] = color;
	}
	//}
}

void Draw_rectangle(int x, int y, int width, int height, Color color) {
	width = between(width+x, 0, WIDTH);
	height = between(height+y, 0, HEIGHT);
	//if (blendmode==0) {
	for (; y<height; y++) {
		for (int i=x; i<width; i++)
			grp[y][i] = color;
	}
	//}
}
static int j = 0;

static int prespacing[2][96] = {
	{0,2,0,0,1,0,0,2,2,1,1,1,2,1,2,0,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,1,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,3,1,0},
	{0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}
};
static int postspacing[2][96]={
	{0,1,1,0,0,0,0,2,1,2,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,2,2,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,1,0,2,0,0,0,0,0,0,0,0,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0},
	{0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}
};

void Draw_printf(int x, int y, Color color, Color bg, int spacing, char* format, ...) {
	va_list argptr;
	va_start(argptr, format);
	static char buffer[100];
	//vsnprintf(buffer, sizeof(buffer), format, argptr); @@@
	va_end(argptr);
	Draw_spacedText(x,y,buffer,color,bg,spacing);
}

void Draw_spacedText(int x, int y, char* text, Color color, Color bg, int spacing) {
	char last = 0;
	for (; *text; text++, x+= 8+spacing) {
		unsigned char character = *text-32;
		if (character!=0) {
			if (character >= 96) character = '?';
			if (j!=0) // does this ever do anything?
				x -= prespacing[j-1][character];
			int ix, iy;
			for (iy=0; iy<12; iy++) {
				for (ix=0; ix<8; ix++) {
					char n = Draw_FONT[character][iy][ix];
					// draw text pixel
					if (n=='.' && color.c!=0)
						Menu_grp[y+iy][x+ix] = color;
					// draw outline pixel
					if (n=='#' && bg.c!=0)
						if (spacing<=-2 && ix<=-spacing-1 && last && Draw_FONT[last][iy][8+spacing+ix] == '.') {
							// (don't draw)
						} else
							Menu_grp[y+iy][x+ix] = bg;
				}
			}
			if (j!=0)
				x -= postspacing[j-1][character];
		}
		last = character;
	}
	j = 0;
}

void Draw_text(int x, int y, char* text, Color color, Color bg) {
	Draw_spacedText(x, y, text, color, bg, 0);
}

void Draw_centeredText(int x, int y, char* text, Color color){
	x -= strlen(text)*8>>1;
	y -= 12>>1;
	Draw_text(x, y, text, color, RGB(0,0,0));
}

void Draw_head(int bx, int by, int x1, int y1, int x2, int y2, bool player2, Color color) {
	for (int j=y1; j<=y2; j++) {
		for (int i=x1; i<=x2; i++) {
			if (x1+1>i || i>x2-1 || y1+1>j || j>y2-1) {
				int x = bx+i;
				int y = by+j;
				if (
				    !(
				      x<8||x>=W+8||y<8||y>=H+8||
				      (player2&&i==x1&&j==y1)||
				      (player2&&i==x2&&j==y1)||
				      (player2&&i==x1&&j==y2)||
				      (player2&&i==x2&&j==y2)
				      )) {
					Color* dest = &grp[y][x];
					if (dest->c==color.c)
						*dest = RGB(0,0,0);
					else
						*dest = color;
				}
			}
		}
	}
}

void Draw_ball(int x, int y, Color color) {
	for (int j=-1; j<=1; j++) {
		grp[y-2][x+j] = color;
		grp[y+2][x+j] = color;
		grp[y+j][x-2] = color;
		grp[y+j][x+2] = color;
	}
}

Color* Draw_pxRef(int x, int y) {
	return &grp[y][x];
}
