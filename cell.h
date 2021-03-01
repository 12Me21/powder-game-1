#pragma once
#include "vector.h"
#include "common.h"

typedef struct Block {
	Vector vel;
	float pres;
	Vector vel2;
	float pres2;
	int block; //uh this is an int
} Block;

extern double pd;
extern Block Part_blocks[HEIGHT/4][WIDTH/4];
extern Block* const Part_blocks_end;
