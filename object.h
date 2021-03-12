#pragma once
#include "common.h"
#include "vector.h"

enum ObjectType {Object_FIGHTER=10, Object_BOX=20, Object_PLAYER=30, Object_CREATE=40};

// Dd
#define Object_PARTS 28

// "Objects"

typedef struct ObjectNode {
	Point pos; // N[]
	Point oldPos; // Z[]
	Elem touching; // Ud[]
} ObjectNode;

typedef struct Object {
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
	ObjectNode parts[Object_PARTS];
} Object;

// Td
#define Object_MAX 50

extern Object entitys[Object_MAX];
extern Object* Object_next;

#define Object_FOR(en) for (Object* en=entitys; en<Object_next; en++)

void Object_create(real x, real y, int type, int meta2); // Gd()
void Object_remove(Object* entity); // oe()
