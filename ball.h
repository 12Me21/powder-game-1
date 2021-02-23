#pragma once
#include "common.h"
#include "vector.h"

typedef struct Ball {
	Vector pos;
	Vector vel;
	bool used;
	int meta;
	int held;
	int type;
} Ball;

#define Ball_MAX 50

extern Ball balls[Ball_MAX+1];

void Ball_create(double x, double y, int type);
