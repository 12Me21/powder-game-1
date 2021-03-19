#pragma once
#include <stdbool.h>
#include "../common.h"
#include "../vector.h"

// main framebuffer

extern Color grp[HEIGHT][WIDTH];
extern Color* const grp0;

void Draw_rectangle(int x, int y, int width, int height, Color color);
void Draw_line(int x1, int y1, int x2, int y2, Color color); // B()
void Draw_vline(Point v1, Point v2, Color color);
void Draw_box(int x, int y, int width, int height, Color color);
void Draw_ball(int x, int y, Color color);
Color* Draw_pxRef(int x, int y);
void Draw_head(int bx, int by, int x1, int y1, int x2, int y2, bool player2, Color color);

// menu framebuffer

extern Color Menu_grp[MENU_HEIGHT][MENU_WIDTH];

void Draw_text(int x, int y, char* text, Color color, Color bg); // k.a()
void Draw_spacedText(int x, int y, char* text, Color color, Color bg, int spacing); // m()
void Draw_printf(int x, int y, Color color, Color bg, int spacing, char* format, ...);
void Draw_mrectangle(int x, int y, int width, int height, Color color);
