#include "../common.h"
#include "draw.h"
#include "../menu.h"
#include "bg.h"
#include "../bubble.h"

void Bubble_render(void) {
	const Color* colors = Menu_bgMode==Bg_SILUET ? (const Color[]){0,0,0,0,0,0,0,0} : (const Color[]){0xFFE0E0,0xFFF0E0,0xFFFFE0,0xE0FFE0,0xE0FFFF,0xE0F0FF,0xE0E0FF,0xFFE0FF};
	int ci = 0;
	for (Bubble* b=Bubble_bubbles; b<Bubble_next-1; b++) {
		int e = b->ke;
		Bubble* first = b;
		for (; b<Bubble_next-1 && e==(b+1)->ke; b++) {
			Draw_line(b->x, b->y, (b+1)->x, (b+1)->y, colors[ci]);
			ci++;
			ci %= 8;
		}
		Draw_line(b->x, b->y, first->x, first->y, colors[ci]);
		ci++;
		ci %= 8;
	}
}

