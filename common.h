#pragma once
#include <stdint.h>

typedef uint32_t Color;

// height of framebuffer
#define WIDTH 416
#define HEIGHT 464

// height of window (smaller for some reason)
// (framebuffer is offset by -8, -8)
#define WINDOW_WIDTH (WIDTH-16)
#define WINDOW_HEIGHT (HEIGHT-8)

#define AUTORUN __attribute__((constructor)) static void init_##__LINE__(void)

extern Color grp[HEIGHT][WIDTH];
