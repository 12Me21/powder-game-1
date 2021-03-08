#pragma once
#include "common.h"
#include <complex.h>

typedef union Point {
	struct {
		real x, y;
	};
	Complex c;
	Complex xy;
	// the `xy` member is experimental
	// this allows treating the struct as a single complex number which
	// you can do SOME operations on. For example:
	//   `point.xy *= 2` is the same as `point.x *= 2; point.y *= 2;`
} Point;

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

real Random_(real mag); // S()
real Random_2(real min, real max); // W()
int Random_int(real mag); // X()
bool Rnd_perchance(int chance); //short for Random_(100)<chance
Point Rnd_point(real x1, real x2, real y1, real y2);
	
void Random_update(void); //called each frame

real clamp(real value, real min, real max); // Lc()

#define PI ((real)M_PI)
#define TAU (PI*2)

#define sign(x) ((x)<0 ? -1 : (x)>0)
#define atMost(x,lim) ((x)>(lim) ? (lim) : (x))
