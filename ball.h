#pragma once
#include "common.h"
#include "vector.h"

typedef struct Ball {
	Point pos; // O[]
	Point vel; // $[]
	bool used; // Hc[]
	int meta;  // R[]
	bool held; // Yd[]
	Elem type; // P[]
} Ball;

// Gc
#define Ball_MAX 50

extern Ball balls[Ball_MAX];
extern Ball* const Ball_END;

void Ball_create(real x, real y, Elem type); // Hd()
void Ball_break(Ball* ball, int mode, int createType, int meta, real vx, real vy, real speed); // lf()
bool Ball_react(Ball* ball, Part* part, Elem* newType); // jf()
