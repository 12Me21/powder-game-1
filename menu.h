#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"

extern bool Menu_dragStart, Menu_dragging;
extern bool Menu_numberMenu; // Fa
extern bool Menu_copyMode; // oa
extern int Menu_penMode; // Ba
extern bool Menu_paused; // ya
extern int Menu_hover; //
extern int Menu_bgMode; // ka
extern int Menu_dotLimit; // ha
extern int Menu_gridSize; // xa
extern int Menu_gameSpeed; // za
extern int Menu_edgeMode; // Aa
extern int Menu_carefully; // mb
extern int Menu_leftSelection; // da
extern int Menu_rightSelection; // ea
extern bool Menu_cursorInMenu; // fa
extern int Menu_penSize; // ga
extern int Menu_fps; // Qc
extern int Menu_zoomLevel; // la
extern bool Menu_minimapEnabled; // Ga
extern int buttonflash; // ja
extern axis Menu_zoomX; // ma
extern axis Menu_zoomY; // na
extern Point Pen_dir; // jd

extern const int Part_LIMITS[3]; // ia
extern Point Menu_pen;
extern Point Menu_penOld;
extern axis Pen_x, Pen_y; // Oc, Pc
extern axis Pen_oldx, Pen_oldy; // sd, td

#define Menu_BUTTONWIDTH 56
#define Menu_BUTTONHEIGHT 14
#define Menu_BUTTONROWS 10

enum MenuButton {
	Menu_FAN=6, // angle indicator is drawn on cursor
	Menu_LASER=26, // if these buttons are selected

	Menu_WIND=40, Menu_AIR, Menu_DRAG, Menu_BUBBLE, Menu_WHEEL, Menu_PLAYER, Menu_FIGHTER, Menu_BOX, Menu_BALL, Menu_CREATE, Menu_BLOCK,
	Menu_ERASE=51, Menu_CLEAR, Menu_COPYPASTE, Menu_TEXT, Menu_PEN, Menu_PENSIZE, Menu_SCALE, Menu_SPEED, Menu_START, Menu_UPLOAD, Menu_SAVE,
	Menu_LOAD=62, Menu_MINIMAP, Menu_MENU, Menu_SIDE, Menu_GRID, Menu_BG, Menu_DOT, Menu_RESET,
};
