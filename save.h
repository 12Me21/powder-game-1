#pragma once
#include "common.h"
void Save_Load_test(void*);
void Save_save1(void);

typedef struct SavePixel {
	Elem type; // bb[]
	int meta; // cb[]
} SavePixel;

extern SavePixel Save_data[H][W];

bool Save_onscreen(axis x, axis y);
char* Save_string(SavePixel save[H][W]);
