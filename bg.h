#pragma once

enum Bg {Bg_NONE=0,Bg_AIR=1,Bg_LINE=2,Bg_BLUR=3,Bg_SHADE=4,Bg_AURA=5,Bg_LIGHT=6,Bg_TOON=7,Bg_MESH=8,Bg_GRAY=9,Bg_TRACK=10,Bg_DARK=11,Bg_TG=12,Bg_SILUET=13};

typedef struct BgPixel {
	int light;
} BgPixel;

void Bg_render(void);

extern BgPixel Bg_pixels[WIDTH][309];
