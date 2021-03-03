#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"

extern bool Menu_numberMenu;
extern bool Menu_copyMode;
extern int Menu_penMode;
extern bool Menu_paused;
extern int Menu_hover;
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
extern int Menu_fps;
extern int Menu_zoomLevel;
extern bool Menu_minimapEnabled;
extern int buttonflash;
extern axis Menu_zoomX;
extern axis Menu_zoomY;
extern Point Pen_dir;

extern int Part_LIMITS[3];
extern axis Pen_x, Pen_y;
extern axis Pen_oldx, Pen_oldy;

#define Menu_BUTTONWIDTH 56
#define Menu_BUTTONHEIGHT 14
#define Menu_BUTTONROWS 10

enum MenuButton {
	Menu_WIND=40, Menu_AIR, Menu_DRAG, Menu_BUBBLE, Menu_WHEEL, Menu_PLAYER, Menu_FIGHTER, Menu_BOX, Menu_BALL, Menu_CREATE, Menu_BLOCK,
	Menu_ERASE=51, Menu_CLEAR, Menu_COPYPASTE, Menu_TEXT, Menu_PEN, Menu_PENSIZE, Menu_SCALE, Menu_SPEED, Menu_START, Menu_UPLOAD, Menu_SAVE,
	Menu_LOAD=62, Menu_MINIMAP, Menu_MENU, Menu_SIDE, Menu_GRID, Menu_BG, Menu_DOT, Menu_RESET,
	Menu_FAN=6,
	Menu_LASER=26,
};
