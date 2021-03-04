#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
#include "cell.h"

typedef struct Part {
	Point pos; // C[]
	Point vel; // E[]
	int meta; // M[]
	Elem type;  // t[]
	Elem pumpType; // Jd[]
	bool held;    // Md[]
	// Q[] was redundant but I might add it back later for optimization
} Part;

int* Part_updateCounts(void);
void Part_shuffle(void);
Part* Part_create(real x, real y, Elem element); // id()
void Part_blow(Part* part, Point airvel); // ye()
void Part_swap(Part* part1, Part* part2); // xe()
void Part_remove(Part* part); // U()

void Part_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis));
bool Part_checkPump(Part* part, Part* pump, int dir);
void Part_liquidUpdate(Part* part, Block* cell, real adv, real x1, real x2, real xr1, real yr1, real yr2, real frc);

extern Part* Part_at[HEIGHT][WIDTH];
extern Part* const Part_EMPTY; // D
extern Part* const Part_BGFAN; // F
extern Part* const Part_WHEEL; // -3
extern Part* const Part_BALL; // -2
extern Part* const Part_BLOCK; // -1
extern Part* const Part_0;
extern Part* Part_next; // s (roughly)
void Part_reset(int a);

#define Part_pos(x,y) (&Part_at[(int)(y)][(int)(x)])
#define Part_pos2(pos...) (&Part_at[(int)(pos).y][(int)(pos).x])
#define Part_ofs(x,y) ((int)(x)+(int)(y)*WIDTH)
#define Part_pos3(pos,x,y) (Part_pos2(pos)[Part_ofs(x,y)])

void Part_paint(axis x, axis y, Elem replace, Elem type, int meta); // Zd()
void Part_print(Part* p);
