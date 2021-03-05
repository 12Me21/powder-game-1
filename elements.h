#pragma once
#include <stdbool.h>
#include "common.h"
#include "part.h"

enum State {State_NONE=0, State_POWDER, State_LIQUID, State_HOT, State_SOLID, State_GAS};

typedef struct ElementDef {
	char* name; //for debug
	Color color;       // Ib[]
	Color grayColor;   // Jb[]
	enum State state;  // V[]
	bool playerValid;  // Qe[]  can be held by player
	int temperature;   // xd[]  light generated in "TG" bg mode
	int dissolveRate;  // Be[]  for ACID
	real friction;     // Te[]  affects entity movement i think
	bool ballLight;
	real ze, Ae;       // ze[], Ae[]  these affect superball movement
	bool ballValid;    // gf[]
	real ballWeight;   // ef[]
	real ballAdvection;// ff[]
	int wheelWeight;   // q[] in yd.I()
} ElementDef;

// some of these are pseudo-elements which are only used in savedata
enum Element {
	Elem_EMPTY = -5, Elem_BGFAN = -4, //Elem_WHEEL=-3, Elem_BALL=-2, Elem_BLOCK=-1,
	Elem_BLOCK = 1,
	Elem_POWDER = 2, Elem_WATER, Elem_FIRE, Elem_SEED, Elem_WOOD, Elem_GUNPOWDER, Elem_FAN,
	Elem_WHEEL = 9,
	Elem_ICE, Elem_SNOW, Elem_STEAM, Elem_SUPERBALL, Elem_CLONE, Elem_FIREWORKS, Elem_OIL, Elem_C4,
	Elem_FIGHTER = 18,
	Elem_STONE, Elem_MAGMA, Elem_VIRUS,
	Elem_BOX = 22,
	Elem_NITRO, Elem_ANT, Elem_TORCH, Elem_GAS, Elem_SOAPY, Elem_THUNDER, Elem_METAL,
	Elem_PLAYER = 30,
	Elem_BOMB,
	Elem_PLAYER2 = 32, //  sort of
	Elem_LASER, Elem_ACID, Elem_VINE, Elem_SALT, Elem_SALTWATER, Elem_GLASS, Elem_BIRD,
	Elem_SAVE_BALL = 40,
	Elem_MERCURY, Elem_SPARK, Elem_FUSE, Elem_CLOUD, Elem_PUMP,
	Elem_MAX,
};

extern const ElementDef ELEMENTS[Elem_MAX];

typedef struct MenuButtonDef {
	enum Element element; // hd[]
	enum Element firework;// ud[]
	enum Element player;  // vd[]
	enum Element ball;    // wd[]
} MenuButtonDef;

extern MenuButtonDef Menu_BUTTONS[100]; //don't feel like counting
