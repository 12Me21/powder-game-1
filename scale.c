#include <stdio.h>
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
	int x,y;
	for (y=y1;y<y2;y++) {
		for (x=x1;x<x2;x++) {
			data[y][x] = col;
		}
	}
}

static void rescale(int width, int height, Color data[height][width], int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh) {
	
	int top = sy-dy;
	int bottom = dy+dh-sy-sh;
	int left = sx-dx;
	int right = dx+dw-sx-sw;
	
	int xstart, xend, ystart, yend, xdir, ydir;
	int dxstart, dystart;
	
	ystart = yend = sy;
	if (top>=bottom) {
		ydir = -1;
		ystart += sh;
		dystart = dy;
	} else {
		ydir = 1;
		yend += sh;
		dystart = dy+dh;
	}

	xstart = xend = sx;
	if (left>=right) {
		xdir = 1;
		xend += sw;
		dxstart = dx;
	} else {
		xdir = -1;
		xstart += sw;
		dxstart = dx+dw;
	}
	printf("render %d %d, %d %d\n",top,bottom,left,right);
	int x,y;
	int destx,desty;
	int odesty, odestx;
	desty = dystart*sh;
	for (y=ystart; y!=yend; y+=ydir) {
		odesty = desty/sh;
		desty += dh*ydir;
		
		destx = dxstart*sw;
		for (x=xstart; x!=xend; x+=xdir) {
			odestx = destx/sw;
			destx += dw*xdir;
			//			printf("@ %d %d -> %d %d\n", x,y, odestx, odesty);
			rect(width, height, data, odestx, odesty, destx/sw, desty/sh, data[y][x]);
		}
	}
}

extern Color grp[HEIGHT][WIDTH];

void Scale_render(void) {
	if (Menu_zoomLevel)
		rescale(WIDTH, HEIGHT-MENU_HEIGHT, grp, Menu_zoomX, Menu_zoomY, W>>Menu_zoomLevel, (H)>>Menu_zoomLevel, 8,8,W,H);
}
