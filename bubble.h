#pragma once
#include <stdbool.h>
#include "common.h"

void Bubble_nextId(void);
//extern int Qd; // Qd

typedef struct Bubble {
	Point pos; // Ke[], Le[]
	int group; // ke[]
	bool held; // Me[]
} Bubble;

// Pd
#define Bubble_MAX 2000

extern Bubble Bubble_bubbles[Bubble_MAX];
extern Bubble* const Bubble_END;
extern Bubble* Bubble_next; // Od (roughly)

#define Bubble_FOR(b) for (Bubble* b=Bubble_bubbles; b<Bubble_next; b++)

void Bubble_create(axis x, axis y); // le()
// for drawing bubble with mouse
void Bubble_draw(axis x, axis y, bool rising, bool old);
