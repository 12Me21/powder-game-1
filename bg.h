#pragma once
#include "common.h"

enum Bg {Bg_NONE=0,Bg_AIR=1,Bg_LINE=2,Bg_BLUR=3,Bg_SHADE=4,Bg_AURA=5,Bg_LIGHT=6,Bg_TOON=7,Bg_MESH=8,Bg_GRAY=9,Bg_TRACK=10,Bg_DARK=11,Bg_TG=12,Bg_SILUET=13};

typedef struct BgPixel {
	union {
		int light;
		int auraR;
	};
	int aura1;
	int aura2;
} BgPixel;

void Bg_reset(void);

extern BgPixel Bg_pixels[WIDTH][H+8+1];
extern BgPixel* const Bg_pixels_end;
