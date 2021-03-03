#pragma once
#include "common.h"

typedef struct Vector {
	real x;
	real y;
} Vector;

typedef Vector* Vec;

void Vec_add(Vec a, const Vector* b);
void Vec_sub(Vec a, const Vector* b);
void Vec_sub2(Vec out, const Vector* a, const Vector* b);
void Vec_mul(Vec a, real x);
void Vec_mul2(Vec out, const Vector* a, real mul);
real Vec_fastDist(const Vector* a);
real Vec_dist(const Vector* this);
real Vec_fastNormalize(Vec v);
void Vec_normalize(Vec v);
real Vec_angle(const Vector* v);
void Vec_swap(Vec a, Vec b);
Vec Vec_unit(int angle);

real Random_(real mag);
real Random_2(real min, real max);
int Random_int(real mag);
void Random_update(void);
bool Rnd_perchance(int chance);

real clamp(real value, real min, real max);

#define PI ((real)M_PI)
#define TAU (PI*2)
