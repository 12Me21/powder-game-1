#include "common.h"
#include "menu.h"

void rect(int width, int height, Color data[height][width], int x1, int y1, int x2, int y2, Color col) {
	int temp;
	if (x2<x1) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y2<y1) {
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	for (;x1<x2;x1++)
		for (;y1<y2;y1++) {
			data[y1][x1] = col;
		}
}

static void rescale(int width, int height, Color data[height][width], int sx, int sy, int sw, int sh) {
	int top = sy;
	int bottom = height-sy-sh;
	int left = sx;
	int right = width-sx-sw;
	
	int xstart, xend, ystart, yend, xdir, ydir;
	int dxstart, dystart;
	
	ystart = yend = sy;
	if (top>bottom) {
		ydir = 1;
		yend += sh;
		dystart = 0;
	} else {
		ydir = -1;
		ystart += sh;
		dystart = height;
	}

	xstart = xend = sy;
	if (left>right) {
		xdir = 1;
		xend += sh;
		dxstart = 0;
	} else {
		xdir = -1;
		xstart += sh;
		dxstart = width;
	}

	int x,y;
	int destx,desty;
	int odesty, odestx;
	desty = dystart;
	for (y=ystart; y!=yend; y+=ydir) {
		destx = dxstart;
		odesty = desty/sh;
		desty += height*ydir;
		for (x=xstart; x!=xend; x+=xdir) {
			odestx = destx/sw;
			destx += width*xdir;
			rect(width, height, data, odestx, odesty, destx/sw, desty/sh, data[y][x]);
		}
	}
}

extern Color grp[HEIGHT][WIDTH];

void Scale_render(void) {
	rescale(WIDTH, HEIGHT, grp, Menu_zoomX, Menu_zoomY, WIDTH>>Menu_zoomLevel, HEIGHT>>Menu_zoomLevel);
}
