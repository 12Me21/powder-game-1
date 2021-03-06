#pragma once
#include "common.h"
#include "vector.h"
#include "dot.h"

typedef struct Ball {
	Point pos; // O[]
	Point vel; // $[]
	bool used; // Hc[]
	int charge;  // R[]
	bool held; // Yd[]
	Elem type; // P[]
} Ball;

// Gc
#define Ball_MAX 50

extern Ball balls[Ball_MAX];
extern Ball* const Ball_END;

#define Ball_FOR(ball) for (Ball* ball=balls; ball<Ball_END; ball++)

void Ball_create(int x, int y, Elem type); // Hd()
void Ball_break(Ball* ball, int mode, int createType, int charge, real vx, real vy, real speed); // lf()
bool Ball_react(Ball* ball, Dot* part, Elem* newType); // jf()
