#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
#include "cell.h"

#define Part_MAX (WIDTH*HEIGHT+1000)

extern int Part_limit;

typedef struct Part {
	Point pos;    // L[]
	Point vel;    // E[]

	union {
		// this field is used differently by different elements,
		// so I created a union that allows differently named/sized fields
		// to use the same memory
		// the total size is always 32 (with usually only 16 used) bits
		int meta;  // M[]
		struct {
			uint8_t dir: 2;
			uint32_t amount: 32-2;
		} Cpump;
		struct {
			uint8_t dir: 4;
			uint8_t age: 4;
			uint32_t inside: 32-4-4;
		} Claser;
		
		struct {
			uint16_t prng: 10;
			uint32_t dir: 32-10;
			// dir is only 2 bits, but I like to make the last item extend to the top because
			// originally this would have been written as:
			// charge = prng | dir<<10, so nothing limited dir to 2 bits.
		} Cthunder1;
		struct {
			uint8_t dir: 2;
			uint32_t type: 32-2;
		} Cthunder2;

		struct {
			uint8_t type: 8;
			uint32_t burning: 32-8;
		} Cfuse;

		/*struct {
			uint32_t growing: 32;
			} Cseed;*/
		struct {
			uint8_t dir: 2;
			uint32_t holding: 32-2;
		} Cant;

		struct {
			uint8_t type: 8;
			uint32_t age: 32-8;
		} Cvirus;
	};
	
	Elem type;    // t[]
	Elem pumpType;// Jd[]
	bool held;    // Md[]
	// Q[] was redundant but I might add it back later for optimization
} Part;

extern Part* Part_at[HEIGHT][WIDTH]; // C[]  this contains pointers to Part structs rather than dot ids.
extern Part** const Part_grid0;

extern Part* const Part_0; // list of dots
extern Part* Part_next; // s (roughly)

extern Part* const Part_EMPTY; // D
extern Part* const Part_BGFAN; // F
extern Part* const Part_WHEEL; // -3
extern Part* const Part_BALL; // -2
extern Part* const Part_BLOCK; // -1

// these are messy
#define Part_pos(x,y) (&Part_at[(int)(y)][(int)(x)])
#define Part_pos2(pos...) (&Part_at[(int)(pos).y][(int)(pos).x])
#define Part_ofs(x,y) ((int)(x)+(int)(y)*WIDTH)
#define Part_pos3(pos,x,y) (Part_pos2(pos)[Part_ofs(x,y)])

Part* Part_create(real x, real y, Elem element); // id()
void Part_blow(Part* part, Point airvel); // ye()
void Part_swap(Part* part1, Part* part2); // xe()
void Part_remove(Part* part); // U()
void Part_paint(axis x, axis y, Elem replace, Elem type, int meta); // Zd()

int* Part_updateCounts(void);
void Part_shuffle(void);
void Part_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis));
bool Part_checkPump(Part* part, Part* pump, int dir);
void Part_liquidUpdate(Part* part, Block* cell, real adv, real x1, real x2, real xr1, real yr1, real yr2, real frc);
void Part_reset(int a);

void Part_print(Part* p); //for debug

bool Part_limit1000(void); // returns true if there are >= 1000 unused parts

void Part_toGrid(Part* p);

Part* Part_rndNear5(Point pos);
Part* Part_rndNear(Point pos, axis rad);
Part* Part_dirNear(Point pos, char dir);
