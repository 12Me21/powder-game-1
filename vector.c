#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

// Note!
// many of the algorithms here are not the most efficient or accurate,
// but cannot be changed without breaking old saves

#define X ->x
#define Y ->y

static Vector sinCos[513]; //yes, 513

void Vec_copy(Vec dest, Vec src) {
	dest X = src X;
	dest Y = src Y;
}

// Vec_set(vec,x,y) (unneeded)

void Vec_add(Vec a, Vec b) {
	a X += b X;
	a Y += b Y;
}

void Vec_sub(Vec a, Vec b) {
	a X -= b X;
	a Y -= b Y;
}

void Vec_sub2(Vec out, Vec a, Vec b) {
	out->x = a->x - b->x;
	out->y = a->y - b->y;
}

void Vec_mul(Vec a, double x) {
	a X *= x;
	a Y *= x;
}

void Vec_mul2(Vec out, Vec a, double mul) {
	out->x = a->x*mul;
	out->y = a->y*mul;
}

static double fastDist(double x, double y) {
	x = fabs(x);
	y = fabs(y);
	if (x>=y)
		return 0.9604*x+0.3978*y;
	else
		return 0.3978*x+0.9604*y;
}

double Vec_fastDist(Vec a) {
	return fastDist(a X, a Y);
}

double Vec_dist(Vec this) {
	return sqrt(this->x*this->x + this->y*this->y);
}

double Vec_fastNormalize(Vec v) {
	double magnitude = Vec_fastDist(v);
	if (magnitude!=0) {
		v->x /= magnitude;
		v->y /= magnitude;
	}
	return magnitude;
}

void Vec_normalize(Vec v) {
	double magnitude = Vec_dist(v);
	if (magnitude!=0) {
		v->x /= magnitude;
		v->y /= magnitude;
	}
}

// this should've used atan2
double Vec_angle(Vec v) {
	double angle = acos(v->x/Vec_dist(v));
	if (v->y>0)
		return TAU-angle;
	return angle;
}

void Vec_swap(Vec a, Vec b) {
	double temp;
	temp = a->x;
	a->x = b->x;
	b->x = temp;
	temp = a->y;
	a->y = b->y;
	b->y = temp;
}

Vec Vec_unit(int angle) {
	return &sinCos[angle];
}

// this random number system is very strange but again, I can't change it

// this can probably be double (more memory but less time spent converting
static float randomFloats[1024];
static int randomIndex = 0, randomStep = 0;
static float randomFloat(void) {
	randomIndex += randomStep;
	randomIndex &= 0x3FF;
	//printf("rnd: %d\n", randomIndex);
	return randomFloats[randomIndex];
}

double Random_(double mag) {
	return mag*randomFloat();
}

double Random_2(double min, double max) {
	return Random_(max-min)+min;
}

int Random_int(double mag) {
	return (int)Random_(mag);
}

void Random_update(void) {
	randomIndex += rand() % 1024 & 0x3FF;
	randomStep = rand() % 512 | 1;
}

void mathInit(void) {
	// init random numbers
	int i;
	for (i=0;i<1024;i++)
		randomFloats[i] = (float)i/1024;
	for (i=0;i<1024;i++) {
		int s = rand() % 1024;
		float temp = randomFloats[i];
		randomFloats[i] = randomFloats[s];
		randomFloats[s] = temp;
	}
	// init sine table
	for (i=0;i<512;i++) {
		double d = 350*i/512*PI/180;
		sinCos[i] = (Vector){sin(d),cos(d)};
	}
	sinCos[i] = sinCos[0];
	Random_update();
}

double clamp(double value, double min, double max){
	if (value<min)
		return min;
	if(value>max)
		return max;
	return value;
}
