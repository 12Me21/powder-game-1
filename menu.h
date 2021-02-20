#pragma once
#include <stdbool.h>

void Menu_render(void);

extern int Menu_bgMode;
extern int Menu_dotLimit;
extern int Menu_gridSize;
extern int Menu_gameSpeed;
extern int Menu_edgeMode;
extern int Menu_carefully;
extern int Menu_leftSelection;
extern int Menu_rightSelection;
extern bool Menu_cursorInMenu;
extern int Menu_penSize;

extern int Part_LIMITS[3];
extern int Pen_x, Pen_y;

void Menu_update(void);

enum MenuButton {
	Menu_WIND=40, Menu_AIR, Menu_DRAG, Menu_BUBBLE, Menu_WHEEL, Menu_PLAYER, Menu_FIGHTER, Menu_BOX, Menu_BALL, Menu_CREATE, Menu_BLOCK,
	Menu_ERASE=51, Menu_CLEAR, Menu_COPYPASTE, Menu_TEXT, Menu_PEN, Menu_PENSIZE, Menu_SCALE, Menu_SPEED, Menu_START, Menu_UPLOAD, Menu_SAVE,
	Menu_LOAD=62, Menu_MINIMAP, Menu_MENU, Menu_SIDE, Menu_GRID, Menu_BG, Menu_DOT, Menu_RESET,
	Menu_FAN=6,
	Menu_LASER=26,
};
