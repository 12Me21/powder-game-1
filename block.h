#pragma once
#include "vector.h"
#include "common.h"

typedef struct Block {
	Point vel; // I[]
	real pres; // J[]
	Point vel2; // md[] (these names might be reversed)
	real pres2; // nd[]

	char block; // K[]
	// -2: (temporary) when erasing block
	// -1: offscreen
	// 0: empty
	// 1: normal block
} Block;

enum BlockType {Block_OFFSCREEN=-1, Block_EMPTY=0, Block_BLOCK=1, Block_ERASED=-2};

void Block_clearPressure(Block* c);
void Block_addPressure(Block* c, real p);

Block* Block_at(axis x, axis y);

#define Block_FOR(var) for (Block* var=Blocks[0]; var<Blocks_END; var++)

extern Block Blocks[HEIGHT/4][WIDTH/4];
extern Block* const Blocks_END;
