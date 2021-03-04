#pragma once
#include "common.h"
void Save_Load_test(void*);
void Save_save1(void);

typedef struct SavePixel {
	Elem type;
	int meta;
} SavePixel;

extern SavePixel Save_data[H][W];
