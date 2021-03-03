#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
void Draw_text(int x, int y, char* text, Color color, Color bg);
void Draw_spacedText(int x, int y, char* text, Color color, Color bg, int spacing);
void Draw_rectangle(int x, int y, int width, int height, Color color);
void Draw_mrectangle(int x, int y, int width, int height, Color color);
void Draw_line(real x1, real y1, real x2, real y2, Color color);
void Draw_vline(Vec v1, Vec v2, Color color);
void Draw_init(void);
void Draw_printf(int x, int y, Color color, Color bg, int spacing, char* format, ...);
void Draw_ball(int x, int y, Color color);
Color* Draw_pxRef(int x, int y);
void Draw_head(int bx, int by, int x1, int y1, int x2, int y2, bool player2, Color color);
extern Color grp[HEIGHT][WIDTH];
extern Color Menu_grp[MENU_HEIGHT][MENU_WIDTH];
