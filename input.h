#pragma once
#include <stdbool.h>

typedef struct Key {
	char lower;
	char upper;
	bool pressed;
	bool rising1;
	bool rising;
} Key;

typedef struct MouseState {
	int x, y;
	bool left, right;
} MouseState;

extern MouseState Mouse_now;
extern MouseState Mouse_old;
extern MouseState Mouse_older;
extern MouseState Mouse_rising;
extern MouseState Mouse_falling;
extern int Mouse_fallingDirection;
extern bool Mouse_risingClick;

extern Key Keys[256];
