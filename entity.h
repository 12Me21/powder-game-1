#pragma once
#include "common.h"
#include "vector.h"

enum EntityType {Entity_FIGHTER=10, Entity_BOX=20, Entity_PLAYER=30, Entity_CREATE=40};

// Dd
#define Entity_PARTS 28

// "Objects"

typedef struct EntityNode {
	Point pos; // N[]
	Point oldPos; // Z[]
	Elem touching; // Ud[]
} EntityNode;

typedef struct Entity {
	int type; // A[]
	int meta; // Ed[]
	//used for:
	// box size
	// player element
	// (make this a union?)
	
	bool isPlayer2; // Xd[]
	int held; // Qd[]
	// when an entity is being DRAG'd, one of its parts is considered "held".
	// if e.held is nonzero, e.parts[e.held-1] is being held
	
	Point vel; // Pe[]
	int age; // Vd[]
	EntityNode parts[Entity_PARTS];
} Entity;

// Td
#define Entity_MAX 50

extern Entity entitys[Entity_MAX];
extern Entity* Entity_next;

void Entity_create(real x, real y, int type, int meta2); // Gd()
void Entity_remove(Entity* entity); // oe()
