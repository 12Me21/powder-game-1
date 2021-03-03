#pragma once
#include <stdbool.h>
#include "common.h"
#include "part.h"

enum State {State_NONE=0, State_POWDER, State_LIQUID, State_HOT, State_SOLID, State_GAS};

//typedef bool (*ElemFunc)(Part* p, Block* b);

typedef struct ElementDef {
	char* name; //for debug
	Color color;
	Color grayColor;
	enum State state;
	bool playerValid; // can be held by player
	int temperature; // light generated in "TG" bg mode
	int dissolveRate; // for ACID
	real friction; // affects entity movement i think
	bool ballLight; // if ball generates light in "DARK" bg mode
	real ze, Ae; //these affect superball movement
	bool ballValid;
	real ballWeight;
	real ballAdvection;
	int wheelWeight;
} ElementDef;

// some of these are pseudo-elements which are only used in savedata
enum Element {
	Elem_EMPTY=-5, Elem_BGFAN=-4, //Elem_WHEEL=-3, Elem_BALL=-2, Elem_BLOCK=-1,
	Elem_BLOCK=1,
	Elem_POWDER=2, Elem_WATER, Elem_FIRE, Elem_SEED, Elem_WOOD, Elem_GUNPOWDER, Elem_FAN,
	Elem_WHEEL = 9,
	Elem_ICE, Elem_SNOW, Elem_STEAM, Elem_SUPERBALL, Elem_CLONE, Elem_FIREWORKS, Elem_OIL, Elem_C4,
	Elem_WHEEL2, //apparently this is meant to be fighter!!
	Elem_STONE, Elem_MAGMA, Elem_VIRUS,
	Elem_BOX=22,
	Elem_NITRO, Elem_ANT, Elem_TORCH, Elem_GAS, Elem_SOAPY, Elem_THUNDER, Elem_METAL,
	Elem_PLAYER=30,
	Elem_BOMB,
	Elem_PLAYER2=32,
	Elem_LASER, Elem_ACID, Elem_VINE, Elem_SALT, Elem_SALTWATER, Elem_GLASS, Elem_BIRD,
	Elem_SAVE_BALL,
	Elem_MERCURY, Elem_SPARK, Elem_FUSE, Elem_CLOUD, Elem_PUMP=45,
	Elem_MAX,
};

extern const ElementDef ELEMENTS[46];

typedef struct MenuButtonDef {
	enum Element element;
	enum Element firework;
	enum Element player;
	enum Element ball;
} MenuButtonDef;

extern MenuButtonDef Menu_BUTTONS[100]; //don't feel like counting
