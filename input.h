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

extern MouseState Mouse_now;
extern MouseState Mouse_old;
extern MouseState Mouse_older;
extern MouseState Mouse_rising;
extern MouseState Mouse_falling;
