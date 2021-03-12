#include <stdio.h>
#include "../common.h"
#include "../object.h"
#include "../elements.h"
#include "../menu.h"
#include "draw.h"
#include "bg.h"

static void line(Object* e, int a, int b, Color c) {
	Draw_vline(e->parts[a].pos, e->parts[b].pos, c);
}

static void rectangle(Object* e, int a, int w, int h, Color c) {
	Draw_rectangle(e->parts[a].pos.x, e->parts[a].pos.y, w, h, c);
}

void Object_render(void) {
	Color tan = 0xFFE0AE, white=0xFFFFFF;
	if (Menu_bgMode==Bg_SILUET)
		white=tan=0;
	Object_FOR (e) {
		switch (e->type) {
		when(Object_FIGHTER):
		case Object_FIGHTER+1:
		case Object_FIGHTER+2:
			line(e, 0, 1, tan);
			line(e, 1, 2, white);
			line(e, 1, 3, white);
			line(e, 2, 4, white);
			line(e, 3, 5, white);
			rectangle(e, 0, 3, 3, tan);
		when(Object_FIGHTER+3):
			line(e, 1, 2, white);
			if (e->age>145) break;
			line(e, 3, 5, white);
			if (e->age>140) break;
			line(e, 4, 7, white);
			if (e->age>135) break;
			line(e, 6, 9, white);
			if (e->age>130) break;
			line(e, 8, 10, white);
			if (e->age>125) break;
			rectangle(e, 0, 2, 2, tan);
		when(Object_BOX):
		case Object_BOX+1:
			line(e, 0, 1, tan);
			line(e, 1, 2, tan);
			line(e, 2, 3, tan);
			line(e, 3, 0, tan);
			//draw dead box
		when(Object_BOX+2):
		case Object_BOX+3:
			line(e, 0, 1, tan);
			if (e->age>145) break;
			line(e, 2, 3, tan);
			if (e->age>140) break;
			line(e, 4, 5, tan);
			if (e->age>135) break;
			line(e, 6, 7, tan);
			if (e->age>130) break; //???
		when(Object_PLAYER):
		case Object_PLAYER+2:
		case Object_PLAYER+3:; //dead
			int f,g,q,n;
			if (e->type != Object_PLAYER+3) {
				line(e, 1, 2, white);
				line(e, 1, 3, white);
				line(e, 2, 4, white);
				line(e, 3, 5, white);
				f=-2;
				g=2;
				q=-1;
				n=3;
			} else { //dead
				line(e, 3, 5, white);
				if (e->age>140) break;
				line(e, 4, 7, white);
				if (e->age>135) break;
				line(e, 6, 9, white);
				if (e->age>130) break;
				line(e, 8, 10, white);
				if (e->age>125) break;
				f=-1;
				g=1;
				q=-1;
				n=1;
			}
			Color headcolor = ELEMENTS[e->meta].color ?: tan;
			if (Menu_bgMode==Bg_SILUET)
				headcolor = 0x000000;
			Draw_head(e->parts[0].pos.x, e->parts[0].pos.y, f, q, g, n, e->isPlayer2, headcolor);
			// add light to region around player
			if (Menu_bgMode==Bg_DARK) {
				f = clamp(e->parts[0].pos.x,8,407);
				q = clamp(e->parts[0].pos.y,8,304);
				for (int y=q-4; y<=q+4; y+=4)
					for (int x=f-4; x<=f+4; x+=4)
						Bg_pixels[y][x].light = 0x1FFFFFFF;
			}
			break;
		}
		// lights in TG mode
		switch(e->type){
		case Object_FIGHTER:
		case Object_FIGHTER+1:
		case Object_FIGHTER+2:
		case Object_FIGHTER+3:
		case Object_PLAYER:
		case Object_PLAYER+2:
		case Object_PLAYER+3:
			if (Menu_bgMode == Bg_TG) {
				for (int d=0; d<6; d++)
					Bg_pixels
						[(int)clamp(e->parts[d].pos.y,8,304)]
						[(int)clamp(e->parts[d].pos.x,8,407)].light = 3000;
			}
		}
	}
}
