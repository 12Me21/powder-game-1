#include "common.h"
#include "elements.h"

#define BRIGHTNESS(color) (int)((real)(color>>16&0xFF)*0.2989f+(real)(color>>8&0xFF)*0.5866f+(real)(color&0xFF)*0.1145f)
#define GRAY(col) (BRIGHTNESS(col)<<16|BRIGHTNESS(col)<<8|BRIGHTNESS(col))
#define COL(col) col,GRAY(col),col

extern ElementDef Def_POWDER;

ElementDef ELEMENTS[Elem_MAX] = {
	// (see element.h for more info)
	// Name          color      state   player temp.acid fric ball
	//                                                       light ? ? ball
	[Elem_OIL] = {"OIL"     ,COL(0x803020),State_LIQUID,1,0    ,30 ,0.8,0,0  ,0  ,1,0.1  ,0 ,3  },
	{"C4"      ,COL(0xFFFFCC),State_SOLID ,0,0    ,100,0.5,0,0.5,0.5,1,0.1  ,0.2,4 },
	{"Elem_18" ,COL(0xFFE0AE)},
	{"STONE"   ,COL(0x808080),State_POWDER,1,0    ,20 ,0.5,0,0.9,0.9,1,0.1  ,0.1,9 },
	{"MAGMA"   ,COL(0xFF6633),State_HOT   ,1,10000,50 ,0.5,1,0.2,0.2,1,0.1  ,0  ,9 },
	{"VIRUS"   ,COL(0x800080),State_POWDER,1,0    ,10 ,0.5,0,0  ,0  ,1,0.1  ,0.5,1 },
	{"Elem_22" ,COL(0xFFE0AE)},
	{"NITRO"   ,COL(0x447700),State_LIQUID,1,0    ,100,0.8,0,0  ,0  ,1,0.1  ,0.3,5 },
	{"ANT"     ,COL(0xC080C0),State_POWDER,1,1500 ,5  ,0.5,0,0.3,0.3,0,0.1  ,0.5,1 },
	{"TORCH"   ,COL(0xFFA020),State_HOT   ,0,4000 ,10 ,0  ,1,0  ,0  ,1,0.1  ,0.3,0 },
	{"GAS"     ,COL(0xCC9999),State_GAS   ,1,500  ,5  ,1  ,0,0  ,0  ,1,-0.01,0.5,-1},
	{"SOAPY"   ,COL(0xE0E0E0),State_LIQUID,1,0    ,30 ,1  ,0,0  ,1  ,1,0.1  ,0.4,4 },
	{"THUNDER" ,COL(0xFFFF20),State_HOT   ,0,2000 ,0  ,0  ,1,0  ,0  ,1,0.1  ,0 ,100},
	{"METAL"   ,COL(0x404040),State_SOLID ,0,0    ,10 ,0.5,0,0.9,0.9,1,0.2  ,0 ,9  },
	{"Elem_30" ,COL(0xFFE0AE)},
	{"BOMB"    ,COL(0x666600),State_POWDER,1,0    ,10 ,0.5,0,0.9,0.9,1,0.1  ,0.1,10},
	{"Elem_32" ,COL(0xFFE0AE)},
	{"LASER"   ,COL(0xCC0000),State_HOT   ,1,5500 ,5  ,0  ,1,0  ,0  ,0,0.1  ,0 ,0  },
	{"ACID"    ,COL(0xCCFF00),State_LIQUID,1,0    ,0  ,0.8,0,0  ,0  ,1,0.1  ,0.4,6 },
	{"VINE"    ,COL(0x00BB00),State_SOLID ,0,500  ,10 ,0.5,0,0.8,0.2,0,0.1  ,0.4,1 },
	{"SALT"    ,COL(0xFFFFFF),State_POWDER,1,0    ,5  ,0.5,0,0.2,0.2,1,0.1  ,0.5,1 },
	{"S-WATER" ,COL(0x3399FF),State_LIQUID,1,0    ,40 ,0.8,0,0  ,0  ,1,0.1  ,0.4,5 },
	{"GLASS"   ,0x011111,GRAY(0x011111),0x404040,State_SOLID ,0,0    ,0  ,0.9,0,0.9,0.5,1,0.1  ,0.2,8 },
	{"BIRD"    ,COL(0x807050),State_GAS   ,1,2000 ,10 ,0.1,0,0.1,0.1,1,0.05 ,0.5,0 },
	{"Elem_41" ,COL(0xFFE0AE)},
	{"MERCURY" ,COL(0xAAAAAA),State_LIQUID,1,0    ,20 ,1  ,0,0.9,0.9,0,0.2  ,0  ,20},
	{"SPARK"   ,COL(0xFFCC33),State_HOT   ,1,3000 ,5  ,0.5,1,0.9,0.9,0,0.1  ,0.5,1 },
	{"FUSE"    ,COL(0x443322),State_SOLID ,0,0    ,50 ,0.5,0,0.5,0.5,1,0.1  ,0.2,4 },
	{"CLOUD"   ,COL(0xCCCCCC),State_GAS   ,1,0    ,5  ,1  ,0,0  ,0  ,1,-0.02,0.5,-2},
	{"PUMP"    ,COL(0x003333),State_SOLID ,0,0    ,0  ,0.5,0,0.9,0.9,1,0.1  ,0  ,9 },
	{"CONCRETE",COL(0x808060),State_SOLID,1,0    ,20 ,0.5,0,0.9,0.9,1,0.1  ,0.1,9 },
};
