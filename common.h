#pragma once
#include <stdint.h>

typedef uint32_t Color;

#define when(x) break;case x
#define orwhen : case
#define otherwise break;default
#define forRange(var, start, cond, step) for(var start; var cond; var step)

// height of framebuffer
#define WIDTH 416
#define HEIGHT 464

// height of window (smaller for some reason)
// (framebuffer is offset by -8, -8)
#define WINDOW_WIDTH (WIDTH-16)
#define WINDOW_HEIGHT (HEIGHT-8)

#define AUTORUN __attribute__((constructor)) static void init_##__LINE__(void)
