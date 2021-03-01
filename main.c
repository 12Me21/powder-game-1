#include "common.h"

#define DEFCALL(name) void name(void); name()

void render() {
	DEFCALL(Bg_render);
	
	DEFCALL(Dot_render);
	DEFCALL(Wheel_render);
	//bubble
	DEFCALL(Entity_render);
	DEFCALL(Ball_render);
	// todo: more bg stuff
	
	DEFCALL(Menu_render);
	//DEFCALL(Scale_render);
}

void Platform_frame(void) {
	DEFCALL(Input_update);
	DEFCALL(Random_update);
	
	DEFCALL(Menu_input);
	DEFCALL(Menu_update);
	
	DEFCALL(Cell_update);
	DEFCALL(Part_update);
	DEFCALL(Wheel_update);
	//bubble
	DEFCALL(Entity_update);
	DEFCALL(Ball_update);
	
	render();
}
