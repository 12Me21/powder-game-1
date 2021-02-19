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

void Input_update(void);
