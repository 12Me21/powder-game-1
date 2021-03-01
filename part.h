#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
#include "cell.h"

typedef struct Part {
	Vector pos;
	Vector vel;
	unsigned char type; //what if we stored type as a pointer to the element table?
	int meta;
	unsigned char pumpType;
	unsigned char held;
} Part;

int* Part_updateCounts(void);
void Part_shuffle(void);
void Part_render(void);
void Part_render(void);
Part* Part_create(double x, double y, unsigned char element);
Part* Part_blow(Part* part, Vec airvel);
void Part_swap(Part* part1, Part* part2);
void Part_update(void);
void Part_remove(Part* part);
void Part_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis));
bool Part_checkPump(Part* part, Part* pump, int dir);
void Part_liquidUpdate(Part* part, Block* cell, double adv, double x1, double x2, double xr1, double yr1, double yr2, double frc);
extern Part* Part_at[HEIGHT][WIDTH];
extern Part* const Part_EMPTY;
extern Part* const Part_BGFAN;
extern Part* const Part_WHEEL;
extern Part* const Part_BALL;
extern Part* const Part_BLOCK;
extern Part* const Part_0;
extern Part* Part_next;
void Part_reset(int a);
void Part_save(int saveData[W*H], int saveMeta[W*H]);

#define Part_pos(x,y) (&Part_at[(int)(y)][(int)(x)])
#define Part_pos2(pos...) (&Part_at[(int)(pos)->y][(int)(pos)->x])
#define Part_ofs(x,y) ((int)(x)+(int)(y)*WIDTH)
#define Part_pos3(pos,x,y) (Part_pos2(pos)[Part_ofs(x,y)])

