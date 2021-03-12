#include <stdio.h>
#include "menu.h"
#include "save.h"
#include "platform.h"
#include "reset.h"

#define DEFCALL(name) void name(void); name()

void Platform_main(int argc, void** argv) {
	if (argc>=2)
		Save_Load_test(argv[1]);
	else
		Sim_reset(false);
}

void render() {
	DEFCALL(Bg_render);
	
	DEFCALL(Dot_render);
	DEFCALL(Wheel_render);
	DEFCALL(Bubble_render);
	DEFCALL(Entity_render);
	DEFCALL(Ball_render);

	DEFCALL(Bg_render2);
	
	DEFCALL(Menu_render);
	DEFCALL(Scale_render);
}

void Platform_frame(void) {
	DEFCALL(Menu_render);
	DEFCALL(Input_update);
	DEFCALL(Random_update);
	
	DEFCALL(Menu_input);
	DEFCALL(Menu_update);
	
	for (int i=0; i<1<<Menu_gameSpeed; i++) {
		DEFCALL(Block_update1);
		if (Menu_paused)
			continue;
		DEFCALL(Block_update);
		DEFCALL(Wheel_update1);
		DEFCALL(Dot_update);
		DEFCALL(Wheel_update);
		DEFCALL(Bubble_update);
		DEFCALL(Entity_update);
		DEFCALL(Ball_update);
	}
	render();
	DEFCALL(Input_update2);
}
