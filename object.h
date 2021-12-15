#pragma once
#include "common.h"
#include "vector.h"

enum ObjectType {
	// (not sure about jumping)
	Object_FIGHTER=10, Object_FIGHTER_JUMPING, Object_FIGHTER_DYING, Object_FIGHTER_DEAD,
	Object_BOX=20, Object_BOX_DYING, Object_BOX_BURNING, Object_BOX_DEAD,
	Object_PLAYER=30, Object_PLAYER_1, Object_PLAYER_DYING, Object_PLAYER_DEAD,
	Object_CREATE=40,
	Object_BALL=-2, // used by create
};

// Dd
enum {Object_PARTS=28};

// "Objects"

// rename to "joint?"
typedef struct ObjectNode {
	Point pos; // N[]
	Point oldPos; // Z[]
	union {
		Elem touching; // Ud[]
		char createType;
		// idk why create type is stored HERE rather than in .held or something
	};
} ObjectNode;

typedef struct Object {
	char type; // A[]
	//char sub; 
	Elem meta; // Ed[]
	//used for:
	// box size
	// player element
	// (make this a union?)
	
	bool isPlayer2; // Xd[]
	char held; // Qd[]
	// when an entity is being DRAG'd, one of its parts is considered "held".
	// if e.held is nonzero, e.parts[e.held-1] is being held
	
	Point vel; // Pe[]
	short age; // Vd[]
	ObjectNode parts[Object_PARTS];
} Object;

// Td
#define Object_MAX 50

extern Object entitys[Object_MAX];
extern Object* Object_next;

#define Object_FOR(en) for (Object* en=entitys; en<Object_next; en++)

void Object_create(real x, real y, Elem type, int meta2); // Gd()
void Object_remove(Object* entity); // oe()
