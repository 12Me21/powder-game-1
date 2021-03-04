#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <complex.h>

typedef float real;
typedef _Complex float Complex;

#define LEN(a) (sizeof(a)/sizeof((a)[0]))

typedef uint32_t Color;
#define RED(x) ((x)>>16&0xFF)
#define GREEN(x) ((x)>>8&0xFF)
#define BLUE(x) ((x)&0xFF)
#define RGB(r,g,b) ((r)<<16|(g)<<8|(b))

typedef int axis;
typedef int Offset;
typedef char Elem;

#define when(x) break;case x
#define orwhen : case
#define otherwise break;default
#define forRange(var, start, cond, step) for(var start; var cond; var step)

// size of visible area
#define W 400
#define H 300

// size of physics area and framebuffer
// h
#define WIDTH (8+W+8)
#define HEIGHT (8+H+8)

#define MENU_HEIGHT 156
#define MENU_WIDTH W

// height of window (smaller for some reason)
// (framebuffer is offset by -8, -8)
#define WINDOW_WIDTH (W)
#define WINDOW_HEIGHT (H+MENU_HEIGHT)

#define AUTORUN __attribute__((constructor)) static void init_##__LINE__(void)
