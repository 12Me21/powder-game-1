//https://www.linuxquestions.org/questions/programming-9/how-to-draw-color-images-with-xlib-339366/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "common.h"
#include "input.h"
#include "draw.h"
#include "part.h"
#include "save.h"
#include "entity.h"
#include "platform.h"

#define DEFCALL(name) void name(void); name()

void render() {
	DEFCALL(Menu_render);
	DEFCALL(Bg_render);
	DEFCALL(Dot_render);
	Entity_render();
}

void Platform_frame(void) {
	Random_update();
	DEFCALL(Menu_input);
	DEFCALL(Menu_update);
	DEFCALL(Input_update);
	Cell_update();
	Part_update();
	Entity_update(); //check order
	render();
	Platform_redraw();
}

int main(int argc, char** argv) {
	Platform_init();
	mathInit();
	Load_test();
	Platform_loop();
}
