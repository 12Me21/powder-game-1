#pragma once
#include "common.h"
#include <complex.h>

typedef union Point {
	struct {
		real x;
		real y;
	};
	Complex c;
} Point;

// v.Kd(x,y) -> v = (Point){x,y}
// 
void Vec_add(Point* a, Point b); // od.add()
void Vec_sub(Point* a, Point b); // od.sub()
Point Vec_sub2(Point a, Point b); // de()
void Vec_mul(Point* a, real x); // T()
Point Vec_mul2(Point a, real mul); // he()
real Vec_fastDist(Point a); // gg()
real Vec_dist(Point this); // hf()
real Vec_fastNormalize(Point* v); // fe()
void Vec_normalize(Point* v); // kf()
real Vec_angle(Point v); // zd()
Point Vec_unit(int angle); // Ce[][] (roughly) (why did I even make this a function?)

real Random_(real mag);
real Random_2(real min, real max);
int Random_int(real mag);
void Random_update(void);
bool Rnd_perchance(int chance);

real clamp(real value, real min, real max);

#define PI ((real)M_PI)
#define TAU (PI*2)
