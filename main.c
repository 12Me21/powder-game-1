#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "save.h"
#include "platform.h"
#include "reset.h"
#include "render/draw.h"

#define DEFCALL(name) void name(void); name()

Platform_Bitmap simBitmap;
Platform_Bitmap menuBitmap;

void Platform_main(int argc, void** argv) {
	Platform_createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Powder Game");
	simBitmap = Platform_createBitmap(&grp[0][0], WIDTH, HEIGHT);
	menuBitmap = Platform_createBitmap(&Menu_grp[0][0], MENU_WIDTH, MENU_HEIGHT);
	srand(time(NULL));
	if (argc>=2)
		Save_Load_test(argv[1]);
	else
		Sim_reset(false);
}

void Platform_redraw(void) {
	Platform_drawBitmap(simBitmap, 0,0, 8,8, W,H);
	Platform_drawBitmap(menuBitmap, 0,H, 0,0, MENU_WIDTH,MENU_HEIGHT);
}

void render(void) {
	DEFCALL(Bg_render);
	
	DEFCALL(Dot_render);
	DEFCALL(Wheel_render);
	DEFCALL(Bubble_render);
	DEFCALL(Object_render);
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
		DEFCALL(Object_update);
		DEFCALL(Ball_update);
	}
	render();
	DEFCALL(Input_update2);
}
