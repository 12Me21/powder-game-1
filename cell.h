#pragma once
#include "vector.h"
#include "common.h"

typedef struct Block {
	Vector vel;
	real pres;
	Vector vel2;
	real pres2;
	int block; //uh this is an int
} Block;

extern real pd;
extern Block Part_blocks[HEIGHT/4][WIDTH/4];
extern Block* const Part_blocks_end;
