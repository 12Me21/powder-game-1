#include <math.h>
#include <stdlib.h>
#include "common.h"
#include "vector.h"

// Note!
// many of the algorithms here are not the most efficient or accurate,
// but cannot be changed without breaking old saves

Point Vec_unit[513]; //yes, 513

void Vec_add(Point* a, Point b) {
	a->xy += b.xy;
}

void Vec_sub(Point* a, Point b) {
	a->xy -= b.xy;
}

Point Vec_sub2(Point a, Point b) {
	return (Point){a.x-b.x, a.y-b.y};
}

void Vec_mul(Point* a, real mul) {
	a->xy *= mul;
}

Point Vec_mul2(Point a, real mul) {
	return (Point){.xy = a.xy*mul};
}

static real fastDist(real x, real y) {
	x = fabs(x);
	y = fabs(y);
	if (x>=y)
		return 0.9604*x+0.3978*y;
	else
		return 0.3978*x+0.9604*y;
}

real Vec_fastDist(Point a) {
	return fastDist(a.x, a.y);
}

// can't use cabs() here because of compatibility
// I have tested, sqrtf() produces the same results as sqrt() here
real Vec_dist(Point this) {
	return sqrtf(this.x*this.x + this.y*this.y);
}

real Vec_fastNormalize(Point* v) {
	real magnitude = Vec_fastDist(*v);
	if (magnitude!=0) {
		v->x /= magnitude;
		v->y /= magnitude;
	}
	return magnitude;
}

void Vec_normalize(Point* v) {
	real magnitude = Vec_dist(*v);
	if (magnitude!=0) {
		v->x /= magnitude;
		v->y /= magnitude;
	}
}

// this should've used atan2
real Vec_angle(Point v) {
	real angle = acos(v.x/Vec_dist(v));
	if (v.y>0)
		return TAU-angle;
	return angle;
}

// this random number system is very strange but again, I can't change it
static real randomFloats[1024];
static int randomIndex = 0, randomStep = 0;
static real randomFloat(void) {
	randomIndex += randomStep;
	randomIndex &= 0x3FF;
	return randomFloats[randomIndex];
}

real Random_(real mag) {
	return mag*randomFloat();
}

real Random_2(real min, real max) {
	return Random_(max-min)+min;
}

int Random_int(real mag) {
	return (int)Random_(mag);
}

bool Rnd_perchance(int chance) {
	return Random_(100)<chance;
}

void Random_update(void) {
	randomIndex += rand() % 1024 & 0x3FF;
	randomStep = rand() % 512 | 1;
}

AUTORUN {
	// init random numbers
	int i;
	for (i=0;i<1024;i++)
		randomFloats[i] = (real)i/1024;
	for (i=0;i<1024;i++) {
		int s = rand() % 1024;
		real temp = randomFloats[i];
		randomFloats[i] = randomFloats[s];
		randomFloats[s] = temp;
	}
	Random_update();
	// init sine table
	for (i=0;i<512;i++) {
		real d = 350*i/512*PI/180;
		Vec_unit[i] = (Point){(real)sin(d),(real)cos(d)};
	}
	Vec_unit[i] = Vec_unit[0];
}

real clamp(real value, real min, real max){
	if (value<min)
		return min;
	if(value>max)
		return max;
	return value;
}
