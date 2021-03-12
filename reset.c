#include <stdbool.h>
#include "common.h"

void Sim_reset(bool drawBorder) {
	void Block_reset(bool drawBorder);
	Block_reset(drawBorder);
#define DEFCALL(type) void type##_reset(void); type##_reset();
	DEFCALL(Menu);
	DEFCALL(Dot);
	DEFCALL(Wheel);
	DEFCALL(Bubble);
	DEFCALL(Entity);
	DEFCALL(Ball);
	DEFCALL(Bg);
}
