#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
extern char FONT[12][768];
void Draw_text(int x, int y, char* text, Color color, Color bg);
void Draw_spacedText(int x, int y, char* text, Color color, Color bg, int spacing);
void Draw_rectangle(int x, int y, int width, int height, Color color);
void Draw_line(double x1, double y1, double x2, double y2, Color color);
void Draw_vline(Vec v1, Vec v2, Color color);
void Draw_init(void);
void Draw_printf(int x, int y, Color color, Color bg, int spacing, char* format, ...);
void Draw_ball(int x, int y, Color color);
Color* Draw_pxRef(int x, int y);
void Draw_head(int bx, int by, int x1, int y1, int x2, int y2, bool player2, Color color);
