#pragma once
#include "common.h"
#include "vector.h"

enum EntityType {Entity_FIGHTER=10, Entity_BOX=20, Entity_PLAYER=30, Entity_CREATE=40};

#define Entity_PARTS 28

typedef struct EntityNode {
	Point pos;
	Point oldPos;
	int touching;
} EntityNode;

typedef struct Entity {
	int type;
	int meta;
	//used for:
	// box size
	// player element
	// (make this a union?)
	
	bool isPlayer2;
	bool held;
	Point vel;
	int decay;
	EntityNode parts[Entity_PARTS];
} Entity;

#define Entity_MAX 50

extern Entity entitys[Entity_MAX];
extern Entity* Entity_next;

void Entity_create(real x, real y, int type, int meta2);
