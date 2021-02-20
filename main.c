//https://www.linuxquestions.org/questions/programming-9/how-to-draw-color-images-with-xlib-339366/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "common.h"
#include "input.h"
#include "draw.h"
#include "menu.h"
#include "part.h"
#include "save.h"
#include "bg.h"
#include "entity.h"
#include "platform.h"

void render() {
	Menu_render();
	Bg_render();
	Part_render();
	Entity_render();
	//Draw_rectangle(Pen_x,Pen_y,1,1,grp[Pen_y][Pen_x]^0xFFFFFF);
}

void Platform_frame(void) {
	Random_update();
	Input_update();
	Cell_update();
	Part_update();
	render();
	Platform_redraw();
}

int main(int argc, char** argv) {
	Platform_init();
	mathInit();
	Draw_init();
	Load_test();
	Platform_loop();
}
