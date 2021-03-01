#pragma once

typedef struct Vector {
	double x;
	double y;
} Vector;

typedef Vector* Vec;

void Vec_add(Vec a, const Vector* b);
void Vec_sub(Vec a, const Vector* b);
void Vec_sub2(Vec out, const Vector* a, const Vector* b);
void Vec_mul(Vec a, double x);
void Vec_mul2(Vec out, const Vector* a, double mul);
double Vec_fastDist(const Vector* a);
double Vec_dist(const Vector* this);
double Vec_fastNormalize(Vec v);
void Vec_normalize(Vec v);
double Vec_angle(const Vector* v);
void Vec_swap(Vec a, Vec b);
Vec Vec_unit(int angle);

double Random_(double mag);
double Random_2(double min, double max);
int Random_int(double mag);
void Random_update(void);
bool Rnd_perchance(int chance);

double clamp(double value, double min, double max);

#define PI 3.1415927 //yes 
#define TAU 6.2831855 //yes 
