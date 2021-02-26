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

#define DEFCALL(name) void name(void); name()

void render() {
	DEFCALL(Menu_render);
	DEFCALL(Bg_render);
	DEFCALL(Dot_render);
	DEFCALL(Entity_render);
	DEFCALL(Ball_render);
	//DEFCALL(Scale_render);
}

void Platform_frame(void) {
	DEFCALL(Menu_input);
	Random_update();
	DEFCALL(Menu_update);
	DEFCALL(Input_update);
	Cell_update();
	Part_update();
	Entity_update(); //check order
	DEFCALL(Ball_update);
	render();
}
