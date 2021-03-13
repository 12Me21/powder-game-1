#pragma once
#include <stdbool.h>
#include "common.h"
#include "vector.h"
#include "block.h"

#define Dot_MAX (WIDTH*HEIGHT+1000)

#define Dot_limit (Dot_LIMITS[Menu_dotLimit])
//extern int Dot_limit;

#define Dot_FOR(var) for (Dot* var=Dot_0; var<Dot_next; var++)
//#define Dot_EACH(var) Dot* var=Dot_0; var<Dot_next; var++

typedef struct Dot {
	Point pos;    // L[]
	Point vel;    // E[]

	union {
		// this field is used differently by different elements,
		// so I created a union that allows differently named/sized fields
		// to use the same memory
		// the total size is always 32 (with usually only 16 used) bits
		int charge;  // M[]
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
} Dot;

extern Dot* Dot_at[HEIGHT][WIDTH]; // C[]  this contains pointers to Dot structs rather than dot ids.
extern Dot** const Dot_grid0;

extern Dot* const Dot_0; // list of dots
extern Dot* Dot_next; // s (roughly)

extern Dot* const Dot_EMPTY; // D
extern Dot* const Dot_BGFAN; // F
extern Dot* const Dot_WHEEL; // -3
extern Dot* const Dot_BALL; // -2
extern Dot* const Dot_BLOCK; // -1

// these are messy
#define Dot_pos(x,y) (&Dot_at[(int)(y)][(int)(x)])
#define Dot_pos2(pos...) (&Dot_at[(int)(pos).y][(int)(pos).x])
#define Dot_ofs(x,y) ((int)(x)+(int)(y)*WIDTH)
#define Dot_pos3(pos,x,y) (Dot_pos2(pos)[Dot_ofs(x,y)])

Dot* Dot_create(real x, real y, Elem element); // id()
void Dot_blow(Dot* part, Point airvel); // ye()
void Dot_swap(Dot* part1, Dot* part2); // xe()
void Dot_remove(Dot* part); // U()
void Dot_paint(axis x, axis y, Elem replace, Elem type, int charge); // Zd()

int* Dot_updateCounts(void);
void Dot_shuffle(void);
void Dot_doRadius(axis x, axis y, axis radius, void (*func)(axis, axis, axis, axis));
bool Dot_checkPump(Dot* part, Dot* pump, int dir);
void Dot_liquidUpdate(Dot* part, Block* cell, real adv, real x1, real x2, real xr1, real yr1, real yr2, real frc);

void Dot_print(Dot* p); //for debug

bool Dot_limit1000(void); // returns true if there are >= 1000 unused parts

void Dot_toGrid(Dot* p);

Dot* Dot_rndNear5(Point pos);
Dot* Dot_rndNear(Point pos, axis rad);
Dot* Dot_dirNear(Point pos, char dir);
