#include "common.h"
#include "draw.h"
#include "entity.h"
#include "bg.h"
#include "elements.h"
#include "menu.h"

static void line(Entity* e, int a, int b, Color c) {
	Draw_vline(e->parts[a].pos, e->parts[b].pos, c);
}

static void rectangle(Entity* e, int a, int w, int h, Color c) {
	Draw_rectangle(e->parts[a].pos.x, e->parts[a].pos.y, w, h, c);
}

void Entity_render(void) {
	Color tan = 0xFFE0AE, white=0xFFFFFF;
	if (Menu_bgMode==Bg_SILUET)
		white=tan=0;
	Entity* e;
	forRange (e, =entitys, <Entity_next, ++) {
		switch (e->type) {
		when(Entity_FIGHTER):
		case Entity_FIGHTER+1:
		case Entity_FIGHTER+2:
			line(e, 0, 1, tan);
			line(e, 1, 2, white);
			line(e, 1, 3, white);
			line(e, 2, 4, white);
			line(e, 3, 5, white);
			rectangle(e, 0, 3, 3, tan);
		when(Entity_FIGHTER+3):
			line(e, 1, 2, white);
			if (e->decay>145) break;
			line(e, 3, 5, white);
			if (e->decay>140) break;
			line(e, 4, 7, white);
			if (e->decay>135) break;
			line(e, 6, 9, white);
			if (e->decay>130) break;
			line(e, 8, 10, white);
			if (e->decay>125) break;
			rectangle(e, 0, 2, 2, tan);
		when(Entity_BOX):
		case Entity_BOX+1:
			line(e, 0, 1, tan);
			line(e, 1, 2, tan);
			line(e, 2, 3, tan);
			line(e, 3, 0, tan);
			//draw dead box
		when(Entity_BOX+2):
		case Entity_BOX+3:
			line(e, 0, 1, tan);
			if (e->decay>145) break;
			line(e, 2, 3, tan);
			if (e->decay>140) break;
			line(e, 4, 5, tan);
			if (e->decay>135) break;
			line(e, 6, 7, tan);
			if (e->decay>130) break; //???
		when(Entity_PLAYER):
		case Entity_PLAYER+2:
		case Entity_PLAYER+3:; //dead
			int f,g,q,n;
			if (e->type != Entity_PLAYER+3) {
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
				if (e->decay>140) break;
				line(e, 4, 7, white);
				if (e->decay>135) break;
				line(e, 6, 9, white);
				if (e->decay>130) break;
				line(e, 8, 10, white);
				if (e->decay>125) break;
				f=-1;
				g=1;
				q=-1;
				n=1;
			}
			Color headcolor = ELEMENTS[e->meta2].color ?: tan;
			if (Menu_bgMode==Bg_SILUET)
				headcolor = 0x000000;
			Draw_head(e->parts[0].pos.x, e->parts[0].pos.y, f, q, g, n, e->meta1==1, headcolor);
			// add light to region around player
			if (Menu_bgMode==Bg_DARK) {
				int y,x;
				f = clamp(e->parts[0].pos.x,8,407);
				q = clamp(e->parts[0].pos.y,8,304);
				forRange (y, =q-4, <=q+4, +=4)
					forRange (x, =f-4, <=f+4, +=4)
						Bg_pixels[y][x].light = 0x1FFFFFFF;
			}
			break;
		}
		// lights in TG mode
		switch(e->type){
		case Entity_FIGHTER:
		case Entity_FIGHTER+1:
		case Entity_FIGHTER+2:
		case Entity_FIGHTER+3:
		case Entity_PLAYER:
		case Entity_PLAYER+2:
		case Entity_PLAYER+3:
			if (Menu_bgMode == Bg_TG) {
				int d;
				forRange (d, =0, <6, ++)
					Bg_pixels
						[(int)clamp(e->parts[d].pos.y,8,304)]
						[(int)clamp(e->parts[d].pos.x,8,407)].light = 3000;
			}
		}
	}
}
