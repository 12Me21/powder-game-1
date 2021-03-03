#pragma once
#include "common.h"
#include <complex.h>

typedef union Point {
	struct {
		real x;
		real y;
	};
	_Complex float z;
} Point;

void Vec_add(Point* a, Point b);
void Vec_sub(Point* a, Point b);
Point Vec_sub2(Point a, Point b);
void Vec_mul(Point* a, real x);
Point Vec_mul2(Point a, real mul);
real Vec_fastDist(Point a);
real Vec_dist(Point this);
real Vec_fastNormalize(Point* v);
void Vec_normalize(Point* v);
real Vec_angle(Point v);
Point Vec_unit(int angle);

real Random_(real mag);
real Random_2(real min, real max);
int Random_int(real mag);
void Random_update(void);
bool Rnd_perchance(int chance);

real clamp(real value, real min, real max);

#define PI ((real)M_PI)
#define TAU (PI*2)
