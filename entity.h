#pragma once
#include "vector.h"

typedef struct Ball {
	Vector pos;
	Vector vel;
	bool used;
	int meta;
	int held;
	int type;
} Ball;

#define Ball_MAX 50

enum EntityType {Entity_FIGHTER=10, Entity_BOX=20, Entity_PLAYER=30, Entity_CREATE=40};

#define Entity_MAX 50
#define Entity_PARTS 28

typedef struct EntityNode {
	Vector pos;
	Vector oldPos;
	int touching;
} EntityNode;

typedef struct Entity {
	int type;
	int meta2;
	int meta1;
	bool held;
	Vector Pe;
	int decay;
	EntityNode parts[Entity_PARTS];
} Entity;

extern Entity entitys[Entity_MAX];
extern Ball balls[Ball_MAX];
extern Entity* Entity_next;

void Ball_create(double x, double y, int type);
void Entity_create(double x, double y, int type, int meta2);
void Entity_update(void);

