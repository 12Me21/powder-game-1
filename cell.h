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

#define Cell_FOR(var) for (Cell* var=Part_blocks[0]; var<Part_blocks_end; var++)

extern Block Part_blocks[HEIGHT/4][WIDTH/4];
extern Block* const Part_blocks_end;
