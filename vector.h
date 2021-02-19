#pragma once

typedef struct Vector {
	double x;
	double y;
} Vector;

typedef Vector* Vec;

void mathInit();

void Vec_copy(Vec dest, Vec src);
void Vec_add(Vec a, Vec b);
void Vec_sub(Vec a, Vec b);
void Vec_sub2(Vec out, Vec a, Vec b);
void Vec_mul(Vec a, double x);
void Vec_mul2(Vec out, Vec a, double mul);
double Vec_fastDist(Vec a);
double Vec_dist(Vec this);
double Vec_fastNormalize(Vec v);
void Vec_normalize(Vec v);
double Vec_angle(Vec v);
void Vec_swap(Vec a, Vec b);
Vec Vec_unit(int angle);

double Random_(double mag);
double Random_2(double min, double max);
int Random_int(double mag);

double clamp(double value, double min, double max);

#define PI 3.1415927 //yes 
#define TAU 6.2831855 //yes 
