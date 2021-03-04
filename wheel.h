typedef struct Wheel {
	int x, y;  // Bd[], Cd[]
	real angle;// me[]
	real vel;  // ne[]
} Wheel;

// Nd
#define Wheel_MAX 100

extern Wheel Wheel_wheels[Wheel_MAX];
extern Wheel* const Wheel_end;
extern Wheel* Wheel_next; // Ac (roughly)

void Wheel_create(axis x, axis y); // Fd()
void Wheel_remove(Wheel* w);

