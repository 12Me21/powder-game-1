#pragma once
#include "common.h"
#include "vector.h"

real Random_(real mag); // S()
real Random_2(real min, real max); // W()
int Random_int(real mag); // X()
bool Rnd_perchance(int chance); //short for Random_(100)<chance
Point Rnd_point(real x1, real x2, real y1, real y2);
	
void Random_update(void); //called each frame
