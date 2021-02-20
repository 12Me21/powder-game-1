#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"

typedef struct Part {
	Vector pos;
	Vector vel;
	unsigned char type; //what if we stored type as a pointer to the element table?
	int meta;
	unsigned char pumpType;
	unsigned char held;
} Part;

typedef struct Block {
	Vector vel;
	float pres;
	Vector vel2;
	float pres2;
	bool block;
} Block;

extern double pd;

int* Part_updateCounts(void);
void Part_shuffle(void);
void Part_render(void);
void Part_render(void);
Part* Part_create(double x, double y, unsigned char element);
Part* Part_blow(Part* part, Vec airvel);
void Part_swap(Part* part1, Part* part2);
void Part_update(void);
void Part_remove(Part* part);
void Cell_update(void);

extern Part* Part_at[HEIGHT][WIDTH];
extern Part Part_EMPTY[1];
extern Part Part_BGFAN[1];
extern Part Part_WHEEL[1];
extern Part Part_BALL[1] ;
extern Part Part_BLOCK[1];
extern Part* Part_0;
extern Block Part_blocks[HEIGHT/4][WIDTH/4];
void Part_reset(int a);
