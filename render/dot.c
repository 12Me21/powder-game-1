#include "../common.h"
#include "../elements.h"
#include "draw.h"
#include "../part.h"
#include "bg.h"
#include "../menu.h"

void Dot_render(void) {
	if (Menu_bgMode==Bg_TOON)
		return;
	Part_FOR (i) {
		Elem type = i->type;
		if (type==Elem_PUMP && i->pumpType!=0)
			type = i->pumpType;
		Color color;
		if (Menu_bgMode==Bg_GRAY)
			color = ELEMENTS[type].grayColor;
		else
			color = ELEMENTS[type].color;
		Color* dest = Draw_pxRef(i->pos.x, i->pos.y);
		int red, green, blue;
		if (Menu_bgMode == Bg_LIGHT) {
			red = atMost(RED(color)/4+RED(*dest), 255);
			green = atMost(GREEN(color)/4+GREEN(*dest), 255);
			blue = atMost(BLUE(color)/4+BLUE(*dest), 255);
			*dest = RGB(red,green,blue);
		} else if (Menu_bgMode == Bg_SILUET) {
			red = atLeast(RED(*dest)+RED(color)-(0xFF+10), 0);
			green = atLeast(GREEN(*dest)+GREEN(color)-(0xFF+10), 0);
			blue = atLeast(BLUE(*dest)+BLUE(color)-(0xFF+10), 0);
			*dest = RGB(red,green,blue);
		} else
			*dest = color;
	}
}
