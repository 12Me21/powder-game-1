#include "../common.h"
#include "../elements.h"
#include "draw.h"
#include "../dot.h"
#include "bg.h"
#include "../menu.h"

void Dot_render(void) {
	if (Menu_bgMode==Bg_TOON)
		return;
	Dot_FOR (i) {
		Elem type = i->type;
		if (type==Elem_PUMP && i->Cpump.type!=0)
			type = i->Cpump.type;
		Color color;
		if (Menu_bgMode==Bg_GRAY)
			color = ELEMENTS[type].grayColor;
		else
			color = ELEMENTS[type].color;
		Color* dest = Draw_pxRef(i->pos.x, i->pos.y);
		int red, green, blue;
		if (Menu_bgMode == Bg_LIGHT) {
			red = atMost(color.r/4+dest->r, 255);
			green = atMost(color.g/4+dest->g, 255);
			blue = atMost(color.b/4+dest->b, 255);
			*dest = RGB(red,green,blue);
		} else if (Menu_bgMode == Bg_SILUET) {
			red = atLeast(dest->r+color.r-(0xFF+10), 0);
			green = atLeast(dest->g+color.g-(0xFF+10), 0);
			blue = atLeast(dest->b+color.b-(0xFF+10), 0);
			*dest = RGB(red,green,blue);
		} else
			*dest = color;
	}
}
