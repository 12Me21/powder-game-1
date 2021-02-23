#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t Color;
#define RED(x) ((x)>>16&0xFF)
#define GREEN(x) ((x)>>8&0xFF)
#define BLUE(x) ((x)&0xFF)
#define RGB(r,g,b) ((r)<<16|(g)<<8|(b))

typedef int axis;

#define when(x) break;case x
#define orwhen : case
#define otherwise break;default
#define forRange(var, start, cond, step) for(var start; var cond; var step)

#define W 400
#define H 300

#define MENU_HEIGHT 156

// height of framebuffer
#define WIDTH (8+W+8)
#define HEIGHT (8+H+MENU_HEIGHT)

// height of window (smaller for some reason)
// (framebuffer is offset by -8, -8)
#define WINDOW_WIDTH (WIDTH-16)
#define WINDOW_HEIGHT (HEIGHT-8)

#define AUTORUN __attribute__((constructor)) static void init_##__LINE__(void)
