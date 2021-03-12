#include <stdbool.h>
#include "common.h"

void Sim_reset(bool drawBorder) {
	void Cell_reset(bool drawBorder);
	Cell_reset(drawBorder);
#define DEFCALL(type) void type##_reset(void); type##_reset();
	DEFCALL(Menu);
	DEFCALL(Part);
	DEFCALL(Wheel);
	DEFCALL(Bubble);
	DEFCALL(Entity);
	DEFCALL(Ball);
	DEFCALL(Bg);
}
