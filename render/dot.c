#include "../common.h"
#include "../elements.h"
#include "draw.h"
#include "../part.h"
#include "bg.h"
#include "../menu.h"

void Dot_render(void) {
	if (Menu_bgMode==Bg_TOON)
		return;
	for (Part* i=Part_0; i<Part_next; i++) {
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
			red = RED(color)/4+RED(*dest);
			if (red>0xFF) red=0xFF;
			green=GREEN(color)/4+GREEN(*dest);
			if (green>0xFF) green=0xFF;
			blue = BLUE(color)/4+BLUE(*dest);
			if (blue>0xFF) blue=0xFF;
			*dest = RGB(red,green,blue);
		} else if (Menu_bgMode == Bg_SILUET) {
			red = RED(*dest)+RED(color)-(0xFF+10);
			if (red<0) red=0;
			green = GREEN(*dest)+GREEN(color)-(0xFF+10);
			if (green<0) green=0;
			blue = BLUE(*dest)+BLUE(color)-(0xFF+10);
			if (blue<0) blue=0;
			*dest = RGB(red,green,blue);
		} else
			*dest = color;
	}
}
