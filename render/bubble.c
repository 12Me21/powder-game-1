#include "../common.h"
#include "draw.h"
#include "../menu.h"
#include "../bubble.h"

void Bubble_render(void) {
	const Color* colors = Menu_bgMode==Bg_SILUET ? (const Color[]){RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0)} : (const Color[]){RGB(0xFF,0xE0,0xE0),RGB(0xFF,0xF0,0xE0),RGB(0xFF,0xFF,0xE0),RGB(0xE0,0xFF,0xE0),RGB(0xE0,0xFF,0xFF),RGB(0xE0,0xF0,0xFF),RGB(0xE0,0xE0,0xFF),RGB(0xFF,0xE0,0xFF)};
	int ci = 0;
	Bubble* first = &Bubble_bubbles[0];
	Bubble_FOR (b) {
		Bubble* next = (b+1);

		/*int count=0;
		for (Bubble* d=first; d<Bubble_next && d->group==first->group; d++)
			count++;
		Point center = {0,0};
		for (Bubble* d=first; d<first+count; d++)
			center.xy += d->pos.xy;
		center.xy /= count;
		Draw_ball(center.x,center.y,0xFF0000);*/

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

