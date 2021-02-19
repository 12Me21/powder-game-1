#include <stdbool.h>

typedef struct Key {
	char lower;
	char upper;
	bool pressed;
	bool rising1;
	bool rising;
} Key;

Key Keys[256] = {
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //0-12
	{13,13},{0},{0},{0}, // 13-15
	{16,16},{17,17},{18,18}, //16-18
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}, //19-31
	// todo: finish
};



typedef struct MouseState {
	int x, y;
	bool left, right;
} MouseState;

MouseState Mouse_now;
MouseState Mouse_old;
MouseState Mouse_older;
// ignore the x/y on these
MouseState Mouse_rising;
MouseState Mouse_falling;

bool Mouse_risingClick;
int Mouse_fallingDirection;



void Input_update(void) {
	Mouse_rising.left = !Mouse_old.left && Mouse_now.left;
	Mouse_falling.left = Mouse_old.left && !Mouse_now.left;
	Mouse_rising.right = !Mouse_old.right && Mouse_now.right;
	Mouse_falling.right = Mouse_old.right && !Mouse_now.right;
	Mouse_older = Mouse_old;
	Mouse_old = Mouse_now;

	Mouse_risingClick = !(Mouse_falling.left||Mouse_old.left||Mouse_falling.right||Mouse_old.right);
	Mouse_fallingDirection = Mouse_falling.left ? 1 : Mouse_falling.right ? -1 : 0;
	int i;
	for (i=0;i<256;i++) {
		Keys[i].rising = Keys[i].rising1;
		Keys[i].rising1 = false;
	}
}
