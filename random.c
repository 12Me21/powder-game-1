#include "common.h"
#include "vector.h"

// this random number system is very strange but again, I can't change it
static real randomFloats[1024];
static int randomIndex = 0, randomStep = 0;
static real randomFloat(void) {
	randomIndex += randomStep;
	randomIndex %= 1024;
	return randomFloats[randomIndex];
}

real Random_(real mag) {
	return mag*randomFloat();
}

real Random_2(real min, real max) {
	return Random_(max-min)+min;
}

int Random_int(real mag) {
	return (int)Random_(mag);
}

bool Rnd_perchance(int chance) {
	return Random_(100)<chance;
}

Point Rnd_point(real x1, real x2, real y1, real y2) {
	real x = Random_2(x1,x2); //this is done separately to preserve the order
	return (Point){x, Random_2(y1,y2)};
}

int rand(void) {
	return 4;
}

void Random_update(void) {
	randomIndex += rand() % 1024;
	randomStep = rand() % 512 | 1;
}

AUTORUN {
	// init random numbers
	for (int i=0;i<1024;i++)
		randomFloats[i] = (real)i/1024;
	for (int i=0;i<1024;i++) {
		int s = rand() % 1024;
		real temp = randomFloats[i];
		randomFloats[i] = randomFloats[s];
		randomFloats[s] = temp;
	}
	Random_update();
}
