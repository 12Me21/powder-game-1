#include "../ball.h"
#include "../elements.h"
#include "bg.h"
#include "../menu.h"
#include "draw.h"

void Ball_render(void) {
	Ball_FOR (ball) {
		if (!ball->used)
			continue;
		int type = ball->type;
		Color color = ELEMENTS[type].color;
		if (Menu_bgMode == Bg_SILUET)
			color = 0;
		int x = ball->pos.x;
		int y = ball->pos.y;
		Draw_ball(x, y, color);
		if (y<H+8) {
			if (Menu_bgMode==Bg_DARK) {
				if (ELEMENTS[type].ballLight)
					Bg_pixels[y][x].light = 255000;
			} else if (Menu_bgMode==Bg_TG) {
				Bg_pixels[y][x].light = 2*ELEMENTS[type].temperature;
			}
		}
	}
}
