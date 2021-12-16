#include "../common.h"
#include "../wheel.h"
#include "draw.h"
#include "../menu.h"

extern const char Wheel_frames[16][32][32];

void Wheel_render(void) {
	Color color = Menu_bgMode==Bg_SILUET ? RGB(0,0,0) : RGB(0xB0,0xA0, 0x90);
	Wheel_FOR (w) {
		const char (*frame)[32] = Wheel_frames[(int)w->angle];
		for (axis y=0;y<32;y++) {
			for (axis x=0;x<32;x++)
				if (frame[y][x]=='.')
					grp[w->y+y-16][w->x+x-16] = color;
		}
	}
}
