#pragma once
#include <stdbool.h>
#include "common.h"

typedef struct Bubble {
	double x;
	double y;
	int ke;
	bool held;
} Bubble;

extern Bubble Bubble_bubbles[2000];
extern Bubble* const Bubble_end;
extern Bubble* Bubble_next;

void Bubble_draw(axis x, axis y, bool rising, bool old);
void Bubble_create(axis x, axis y);
