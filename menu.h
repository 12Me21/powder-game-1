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
