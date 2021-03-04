#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"

typedef struct ButtonState {
	bool gotPress;
	bool gotRelease;
	bool held;
	bool heldNow;
	bool wasHeld;
} ButtonState;

typedef struct MouseState {
	Point pos, oldPos, olderPos;
	union {
		ButtonState buttons[3];
		struct {
			ButtonState left;
			ButtonState middle;
			ButtonState right;
		};
	};
} MouseState;

extern MouseState mouse;

extern int Mouse_fallingDirection;
extern bool Mouse_risingClick;

extern ButtonState Keys[256];
