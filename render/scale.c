#include "../common.h"
#include "draw.h"
#include "../menu.h"

void Scale_render(void) {
	if (!Menu_zoomLevel)
		return;
	int zoom = 1<<Menu_zoomLevel;
	axis w = (W+zoom-1)/zoom;
	axis h = (H+zoom-1)/zoom;
	Color temp[h][w];
	for (axis y=0; y<h; y++)
		for (axis x=0; x<w; x++)
			temp[y][x] = grp[Menu_zoomY+y+8][Menu_zoomX+x+8];
	for (axis y=0;y<H;y++) {
		for (axis x=0; x<W; x++) {
			grp[y+8][x+8] = temp[y/zoom][x/zoom];
		}
	}
}
