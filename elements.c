#include "common.h"
#include "elements.h"

ElementDef ELEMENTS[Elem_MAX] = {
	{"Element_0"},
	{"Element_1" , 0x606060, 0           , 0, 0    , 0  ,0.5},
	// Name          color      state   player temp.acid fric
	{"POWDER"    , 0xF2BD6B, State_POWDER, 1, 0    , 5  ,0.5},
	{"WATER"     , 0x4040FF, State_LIQUID, 1, 0    , 40 ,0.8},
	{"FIRE"      , 0xFF4040, State_HOT   , 1, 5000 , 10 ,1  },
	{"SEED"      , 0x90C040, State_POWDER, 1, 500  , 5  ,0.5},
	{"WOOD"      , 0x805020, State_SOLID , 0, 500  , 10 ,0.5},
	{"GUNPOWDER" , 0xB08050, State_POWDER, 1, 0    , 10 ,0.5},
	{"FAN"       , 0x8080FF, State_NONE  , 1, 0    , 0  ,1  },
	{"Element_9" , 0xB0A090, 0           , 0, 0    , 0  ,0.5},
	{"ICE"       , 0xD0D0FF, State_SOLID , 0, -1000, 40 ,1  },
	{"SNOW"      , 0xFFFFFF, State_POWDER, 1, -500 , 10 ,0.5},
	{"STEAM"     , 0xE0E0E0, State_NONE  , 1, 0    , 30 ,1  },
	{"SUPERBALL" , 0xFF40A0, State_POWDER, 1, 0    , 10 ,0.5},
	{"CLONE"     , 0x907010, State_SOLID , 0, 0    , 0  ,0.5},
	{"FIREWORKS" , 0xFF9966, State_POWDER, 1, 0    , 10 ,0.5},
	{"OIL"       , 0x803020, State_LIQUID, 1, 0    , 30 ,0.8},
	{"C4"        , 0xFFFFCC, State_SOLID , 0, 0    , 100,0.5},
	{"Element_18", 0xFFE0AE},
	{"STONE"     , 0x808080, State_POWDER, 1, 0    , 20 ,0.5},
	{"MAGMA"     , 0xFF6633, State_HOT   , 1, 10000, 50 ,0.5},
	{"VIRUS"     , 0x800080, State_POWDER, 1, 0    , 10 ,0.5},
	{"Element_22", 0xFFE0AE},
	{"NITRO"     , 0x447700, State_LIQUID, 1, 0    , 100,0.8},
	{"ANT"       , 0xC080C0, State_POWDER, 1, 1500 , 5  ,0.5},
	{"TORCH"     , 0xFFA020, State_HOT   , 0, 4000 , 10 ,0  },
	{"GAS"       , 0xCC9999, State_GAS   , 1, 500  , 5  ,1  },
	{"SOAPY"     , 0xE0E0E0, State_LIQUID, 1, 0    , 30 ,1  },
	{"THUNDER"   , 0xFFFF20, State_HOT   , 0, 2000 , 0  ,0  },
	{"METAL"     , 0x404040, State_SOLID , 0, 0    , 10 ,0.5},
	{"Element_30", 0xFFE0AE},
	{"BOMB"      , 0x666600, State_POWDER, 1, 0    , 10 ,0.5},
	{"Element_32", 0xFFE0AE},
	{"LASER"     , 0xCC0000, State_HOT   , 1, 5500 , 5  ,0  },
	{"ACID"      , 0xCCFF00, State_LIQUID, 1, 0    , 0  ,0.8},
	{"VINE"      , 0x00BB00, State_SOLID , 0, 500  , 10 ,0.5},
	{"SALT"      , 0xFFFFFF, State_POWDER, 1, 0    , 5  ,0.5},
	{"SALTWATER" , 0x3399FF, State_LIQUID, 1, 0    , 40 ,0.8},
	{"GLASS"     , 0x011111, State_SOLID , 0, 0    , 0  ,0.9},
	{"BIRD"      , 0x807050, State_GAS   , 1, 2000 , 10 ,0.1},
	{"Save_BALL" , 0xFFE0AE},
	{"MERCURY"   , 0xAAAAAA, State_LIQUID, 1, 0    , 20 ,1  },
	{"SPARK"     , 0xFFCC33, State_HOT   , 1, 3000 , 5  ,0.5},
	{"FUSE"      , 0x443322, State_SOLID , 0, 0    , 50 ,0.5},
	{"CLOUD"     , 0xCCCCCC, State_GAS   , 1, 0    , 5  ,1  },
	{"PUMP"      , 0x003333, State_SOLID , 0, 0    , 0  ,0.5},
};

MenuButtonDef Menu_BUTTONS[] = {
	{Elem_POWDER,Elem_POWDER,Elem_POWDER,Elem_POWDER},
	{Elem_WATER,Elem_WATER,Elem_WATER,Elem_WATER},
	{Elem_FIRE,Elem_FIRE,Elem_FIRE,Elem_FIRE},
	{Elem_SEED,Elem_SEED,Elem_SEED,Elem_SEED},
	{Elem_WOOD,0,0,Elem_WOOD},
	{Elem_GUNPOWDER,Elem_GUNPOWDER,Elem_GUNPOWDER,Elem_GUNPOWDER},
	{Elem_FAN,0,Elem_FAN,Elem_FAN},
	{Elem_ICE,0,0,Elem_ICE},
	{Elem_SNOW,Elem_SNOW,Elem_SNOW,0}, //0?
	{Elem_STEAM,Elem_STEAM,Elem_STEAM,Elem_STEAM},
	{Elem_SUPERBALL,Elem_SUPERBALL,Elem_SUPERBALL,0},
	{Elem_CLONE,0,0,Elem_CLONE},
	{Elem_FIREWORKS,0,Elem_FIREWORKS,0},
	{Elem_OIL,Elem_OIL,Elem_OIL,Elem_OIL},
	{Elem_C4,0,0,Elem_C4},
	{Elem_STONE}, //todo
	{Elem_MAGMA}, 
	{Elem_VIRUS},
	{Elem_NITRO},
	{Elem_ANT},
	{Elem_TORCH},
	{Elem_GAS},
	{Elem_SOAPY},
	{Elem_THUNDER},
	{Elem_METAL},
	{Elem_BOMB},
	{Elem_LASER},
	{Elem_ACID},
	{Elem_VINE},
	{Elem_SALT},
	{Elem_SALTWATER},
	{Elem_GLASS},
	{Elem_BIRD},
	{Elem_MERCURY},
	{Elem_SPARK},
	{Elem_FUSE},
	{Elem_CLOUD},
	{Elem_PUMP},
	// rest is 0
};

AUTORUN {
	ElementDef* i;
	for (i=ELEMENTS; i<ELEMENTS+Elem_MAX; i++) {
		Color color = i->color;
		int brightness=(double)(color>>16&0xFF)*0.2989+(double)(color>>8&0xFF)*0.5866+(double)(color&0xFF)*0.1145;
		i->grayColor = brightness<<16|brightness<<8|brightness;
	}
}
