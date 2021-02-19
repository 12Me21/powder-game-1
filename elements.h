#include <stdbool.h>
#include "common.h"

enum State {State_NONE=0, State_POWDER, State_LIQUID, State_HOT, State_SOLID, State_GAS};

typedef bool (*elemFunc)(void);

typedef struct ElementDef {
	char* name;
	Color color;
	enum State state;
	bool playerValid; // can be held by player
	int dissolveRate;
	int temperature;
	double friction;
	Color grayColor;
	elemFunc update;
} ElementDef;

enum Element {
	Elem_EMPTY=-5, Elem_BGFAN=-4, Elem_WHEEL=-3, Elem_BALL=-2, Elem_BLOCK=-1,
	Elem_POWDER=2, Elem_WATER, Elem_FIRE, Elem_SEED, Elem_WOOD, Elem_GUNPOWDER, Elem_FAN, Elem_9, Elem_ICE, Elem_SNOW, Elem_STEAM, Elem_SUPERBALL, Elem_CLONE, Elem_FIREWORKS, Elem_OIL, Elem_C4, Elem_18, Elem_STONE, Elem_MAGMA, Elem_VIRUS, Elem_BOX=22, Elem_NITRO, Elem_ANT, Elem_TORCH, Elem_GAS, Elem_SOAPY, Elem_THUNDER, Elem_METAL, Elem_PLAYER=30, Elem_BOMB, Elem_PLAYER2=32, Elem_LASER, Elem_ACID, Elem_VINE, Elem_SALT, Elem_SALTWATER, Elem_GLASS, Elem_BIRD, Elem_SAVE_BALL, Elem_MERCURY, Elem_SPARK, Elem_FUSE, Elem_CLOUD, Elem_PUMP=45,
	Elem_MAX,
};

extern ElementDef ELEMENTS[46];

enum MenuButton {
	Menu_WIND=40, Menu_AIR, Menu_DRAG, Menu_BUBBLE, Menu_WHEEL, Menu_PLAYER, Menu_FIGHTER, Menu_BOX, Menu_BALL, Menu_CREATE, Menu_BLOCK,
	Menu_ERASE=51, Menu_CLEAR, Menu_COPYPASTE, Menu_TEXT, Menu_PEN, Menu_PENSIZE, Menu_SCALE, Menu_SPEED, Menu_START, Menu_UPLOAD, Menu_SAVE,
	Menu_LOAD=62, Menu_MINIMAP, Menu_MENU, Menu_SIDE, Menu_GRID, Menu_BG, Menu_DOT, Menu_RESET,
	Menu_FAN=6,
	Menu_LASER=26,
};

typedef struct MenuButtonDef {
	enum Element element;
	enum Element firework;
	enum Element player;
	enum Element ball;
} MenuButtonDef;

extern MenuButtonDef Menu_BUTTONS[100]; //don't feel like counting
