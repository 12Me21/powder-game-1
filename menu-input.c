#include "input.h"
#include "menu.h"
#include "reset.h"
#include "save.h"
#include "platform.h"
#include "render/bg.h"

int wa; //this is the state when navigating the upload menu

int Menu_hover = -1;
bool Menu_numberMenu = false;
bool Menu_dragStart = false, Menu_dragging = false;
bool Menu_copyMode = false;
bool Menu_paused = false;
bool Menu_cursorInMenu = false;
int Menu_penMode = 0;
int Menu_leftSelection = 0;
int Menu_rightSelection = Menu_WIND;
int Menu_penSize = 0;
int Menu_zoomLevel = 0;
float Menu_zoomX = 0, Menu_zoomY = 0;
int Menu_dotLimit = 0;
int Menu_gridSize = 0;
int Menu_carefully = 0;
int Menu_bgMode = Bg_NONE;
int Menu_edgeMode = 0;
int Menu_gameSpeed = 0;
bool Menu_minimapEnabled = false;
int buttonflash = 0;
int Menu_fps = 0;

static int wrap(int a, int b) {
	if (a<0)
		return b;
	if (a>b)
		return 0;
	return a;
}

static bool mouseinside(axis x, axis y, axis width, axis height) {
	return !(mouse.pos.x<x||mouse.pos.x>=x+width||mouse.pos.y<y||mouse.pos.y>=y+height);
}

static void clampZoom(void) {
	Menu_zoomX = clamp(Menu_zoomX, 0, W-ceil((real)W/(1<<Menu_zoomLevel)));
	Menu_zoomY = clamp(Menu_zoomY, 0, H-ceil((real)H/(1<<Menu_zoomLevel)));
}

void Menu_input(void) {
	Menu_dragStart = (Menu_leftSelection == Menu_DRAG && mouse.left.gotPress) || (Menu_rightSelection == Menu_DRAG && mouse.right.gotPress); //todo: function for this
	Menu_dragging = (Menu_leftSelection == Menu_DRAG && mouse.left.wasHeld) || (Menu_rightSelection == Menu_DRAG && mouse.right.wasHeld);
	
	if (mouse.pos.y>=H && Mouse_risingClick)
		Menu_cursorInMenu=true;
	else if (mouse.pos.y<H)
		Menu_cursorInMenu=false;
	if (!Menu_cursorInMenu) {
		Menu_hover = -1;
		return;
	}
	// clicked a menu button
	axis bsx=4;
	axis bsy=H+3;
	if (mouseinside(bsx,bsy,391,139)/*&& wa==0*/) {
		axis bx = (mouse.pos.x-bsx)/Menu_BUTTONWIDTH;
		axis by = (mouse.pos.y-bsy)/Menu_BUTTONHEIGHT;
		int selection = clamp(bx*Menu_BUTTONROWS+by,0,69);
		Menu_hover = selection;
		switch (selection) {
		when(Menu_COPYPASTE):;
			if (mouse.left.gotPress) {
				if (Menu_leftSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_leftSelection = selection;
			}
			if (mouse.right.gotPress) {
				if (Menu_rightSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_rightSelection = selection;
			}
		when(Menu_PEN):;
			Menu_penMode = wrap(Menu_penMode+Mouse_fallingDirection, 3);
		when(Menu_PENSIZE):;
			Menu_penSize = wrap(Menu_penSize+Mouse_fallingDirection, 9);
		when(Menu_SCALE):;
			if (mouse.left.gotPress) {
				if (selection==Menu_SCALE) {
					if (Menu_zoomLevel<4) {
						Menu_zoomLevel++;
						Menu_zoomX += W>>Menu_zoomLevel>>1;
						Menu_zoomY += H>>Menu_zoomLevel>>1;
					} else
						Menu_zoomLevel = 0;
				}
				Menu_leftSelection = selection;
			} else if (mouse.right.gotPress) {
				if (selection==Menu_SCALE) {
					if (Menu_zoomLevel>0) {
						Menu_zoomX -= W>>Menu_zoomLevel>>1;
						Menu_zoomY -= H>>Menu_zoomLevel>>1;
						Menu_zoomLevel--;
					} else {
						Menu_zoomLevel = 4;
						Menu_zoomX += W/2-(W>>Menu_zoomLevel>>1);
						Menu_zoomY += H/2-(H>>Menu_zoomLevel>>1);
					}
				}
				Menu_rightSelection = selection;
			}
			clampZoom();
		when(Menu_SPEED):;
			Menu_gameSpeed = wrap(Menu_gameSpeed+Mouse_fallingDirection, 3);
		when(Menu_START):;
			Menu_paused=wrap((Menu_paused?1:0)+Mouse_fallingDirection,1)==1;
		when(Menu_UPLOAD):;
			if (Mouse_fallingDirection) {
				Save_save1();
				//char* s = Save_string(Save_data);
				/*void* name = Platform_selectFile(1);
				FILE* f = Platform_openWrite(name);
				if (f) {
					fputs(s, f);
					}*/
				//free(s);
			}
				//wa=1;
		when(Menu_SAVE):;
			if (mouse.right.gotPress || mouse.left.gotPress) {
				Save_save1();
				/*char* s = Save_string(Save_data);
				if (s) {
					free(s);
					}*/
				//save1();
				//makesavestring();
				buttonflash=10;
			}
		when(Menu_LOAD):;
			if (Mouse_fallingDirection!=0) {
				//loadsavestring();
				//load1();
				buttonflash=-10;
			}
		when(Menu_MINIMAP):;
			Menu_minimapEnabled = wrap(Menu_minimapEnabled+Mouse_fallingDirection,1);
		when(Menu_MENU):;
			Menu_numberMenu = wrap(Menu_numberMenu+Mouse_fallingDirection, 1);
		when(Menu_SIDE):;
			Menu_edgeMode = wrap(Menu_edgeMode+Mouse_fallingDirection, 1);
		when(Menu_GRID):;
			Menu_gridSize=wrap(Menu_gridSize+Mouse_fallingDirection, 7);
		when(Menu_BG):;
			Menu_bgMode = wrap(Menu_bgMode+Mouse_fallingDirection, 13);
			if (Mouse_fallingDirection)
				Bg_reset();
		when(Menu_DOT):;
			Menu_dotLimit = wrap(Menu_dotLimit+Mouse_fallingDirection, 3);
		when(Menu_RESET):;
			if (Mouse_fallingDirection)
				Sim_reset(false);
		otherwise:
			if (selection < Menu_ELEMENTS || selection >= 40) {
				if (mouse.left.gotPress)
					Menu_leftSelection = selection;
				else if (mouse.right.gotPress)
					Menu_rightSelection = selection;
			}
		}
	}
}
