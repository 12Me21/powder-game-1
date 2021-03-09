#pragma once
#include "../common.h"

typedef struct BgPixel {
	union {
		long int light;
		int auraR;
	};
	int auraG;
	int auraB;
} BgPixel;

void Bg_reset(void);

extern BgPixel Bg_pixels[HEIGHT][WIDTH];
extern BgPixel* const Bg_pixels_end;
