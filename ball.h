#pragma once
#include "common.h"
#include "vector.h"

typedef struct Ball {
	Vector pos;
	Vector vel;
	bool used;
	int meta;
	bool held;
	Elem type;
} Ball;

#define Ball_MAX 50

extern Ball balls[Ball_MAX];
extern Ball* const Ball_END;

void Ball_create(real x, real y, Elem type);
