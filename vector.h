#pragma once

#include "common.h"

typedef union Point {
	struct {
		real x, y;
	};
	//Complex c;
	Complex xy;
	// the `xy` member is experimental
	// this allows treating the struct as a single complex number which
	// you can do SOME operations on. For example:
	//   `point.xy *= 2` is the same as `point.x *= 2; point.y *= 2;`
} Point;

//sorry do not use this!
#define Point(c) ((Point){.xy=c})

#define Cxy(x,y) ((Point){(x),(y)}.xy)

// some functions were removed because they were redundant in C :
// point1.set(point2) -> point1 = point2
// Kd(point1,x,y)     -> point1 = (Point){x,y}
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
extern Point Vec_unit[513]; // Ce[][] (roughly)

real clamp(real value, real min, real max); // Lc()

#define PI (3.1415927f)
#define TAU (PI*2)
