#pragma once
#include "vector.h"
#include "common.h"

typedef struct Block {
	Point vel; // I[]
	real pres; // J[]
	Point vel2; // md[] (these names might be reversed)
	real pres2; // nd[]

	char block; // K[]
	// -1: offscreen
	// 0: empty
	// 1: normal block
	// -2: (temporary) when erasing block
} Block;

typedef struct Block Cell;

void Cell_clearPressure(Cell* c);
void Cell_addPressure(Cell* c, real p);

#define Cell_FOR(var) for (Cell* var=Dot_blocks[0]; var<Dot_blocks_end; var++)

extern Block Dot_blocks[HEIGHT/4][WIDTH/4];
extern Block* const Dot_blocks_end;
