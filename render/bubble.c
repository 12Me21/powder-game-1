#include "../common.h"
#include "draw.h"
#include "../menu.h"
#include "../bubble.h"

void Bubble_render(void) {
	const Color* colors = Menu_bgMode==Bg_SILUET ? (const Color[]){0,0,0,0,0,0,0,0} : (const Color[]){0xFFE0E0,0xFFF0E0,0xFFFFE0,0xE0FFE0,0xE0FFFF,0xE0F0FF,0xE0E0FF,0xFFE0FF};
	int ci = 0;
	Bubble* first = &Bubble_bubbles[0];
	Bubble_FOR (b) {
		Bubble* next = (b+1);
		// if next part is in current group:
		if (next<Bubble_next && next->group == first->group) {
			Draw_vline(b->pos, next->pos, colors[ci]);
		} else { // reached end of group
			// draw line back to first item in group
			Draw_vline(b->pos, first->pos, colors[ci]);
			// start new group
			first = next;
		}
		ci++;
		ci %= 8;
	}
}

