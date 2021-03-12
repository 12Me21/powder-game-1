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

void Block_clearPressure(Block* c);
void Block_addPressure(Block* c, real p);

#define Block_FOR(var) for (Block* var=Blocks[0]; var<Blocks_END; var++)

extern Block Blocks[HEIGHT/4][WIDTH/4];
extern Block* const Blocks_END;
