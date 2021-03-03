typedef struct Wheel {
	int x, y;
	real angle;
	real vel;
} Wheel;

extern Wheel Wheel_wheels[100];
extern Wheel* const Wheel_end;
extern Wheel* Wheel_next;

void Wheel_remove(Wheel* w);
void Wheel_create(axis x, axis y);
