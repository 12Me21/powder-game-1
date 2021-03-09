#include "../common.h"
#include "../wheel.h"
#include "draw.h"
#include "../menu.h"

extern const char Wheel_frames[16][32][32];

void Wheel_render(void) {
	Color color = Menu_bgMode==Bg_SILUET ? 0 : 0xB0A090;
	for (Wheel* w=Wheel_wheels; w<Wheel_next; w++) {
		const char (*frame)[32] = Wheel_frames[(int)w->angle];
		for (axis y=0;y<32;y++) {
			for (axis x=0;x<32;x++)
				if (frame[y][x]=='.')
					grp[w->y+y-16][w->x+x-16] = color;
		}
	}
}
