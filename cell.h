#pragma once
#include "vector.h"
#include "common.h"

typedef struct Block {
	Point vel; // I[]
	real pres; // J[]
	Point vel2; // md[] (these names might be reversed)
	real pres2; // nd[]
	char block; // K[]
} Block;

typedef struct Block Cell;

void Cell_clearPressure(Cell* c);
void Cell_addPressure(Cell* c, real p);

extern Block Part_blocks[HEIGHT/4][WIDTH/4];
extern Block* const Part_blocks_end;
