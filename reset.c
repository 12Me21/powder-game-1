#include <stdbool.h>
#include "common.h"

void Sim_reset(bool a) {
#define DEFCALL(type) void type##_reset(void); type##_reset();
	DEFCALL(Cell);
	DEFCALL(Menu);
	DEFCALL(Part);
	DEFCALL(Wheel);
	DEFCALL(Bubble);
	DEFCALL(Entity);
	DEFCALL(Ball);
	DEFCALL(Bg);
}
