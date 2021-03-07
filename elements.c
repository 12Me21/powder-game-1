#include "common.h"
#include "elements.h"

#define BRIGHTNESS(color) (int)((real)(color>>16&0xFF)*0.2989+(real)(color>>8&0xFF)*0.5866+(real)(color&0xFF)*0.1145)
#define COL(col) col,BRIGHTNESS(col)<<16|BRIGHTNESS(col)<<8|BRIGHTNESS(col)

ElementDef const ELEMENTS[Elem_MAX] = {
	{"Element_0"},
	{"Element_1" ,COL(0x606060),0           ,0,0    ,0  ,0.5},
	// (see element.h for more info)
	// Name          color      state   player temp.acid fric ball
	//                                                       light ? ? ball
	{"POWDER"    ,COL(0xF2BD6B),State_POWDER,1,0    ,5  ,0.5,0,0.2,0.2,1,0.1  ,0.5,1	 },
	{"WATER"     ,COL(0x4040FF),State_LIQUID,1,0    ,40 ,0.8,0,0  ,0  ,1,0.1  ,0.4,4	 },
	{"FIRE"      ,COL(0xFF4040),State_HOT   ,1,5000 ,10 ,1  ,1,0  ,0  ,1,-0.03,0.5,-3 },
	{"SEED"      ,COL(0x90C040),State_POWDER,1,500  ,5  ,0.5,0,0.2,0.2,1,0.1  ,0.5,1	 },
	{"WOOD"      ,COL(0x805020),State_SOLID ,0,500  ,10 ,0.5,0,0.7,0.7,1,0.1  ,0.4,0	 },
	{"GUNPOWDER" ,COL(0xB08050),State_POWDER,1,0    ,10 ,0.5,0,0.2,0.2,1,0.1  ,0.4,2	 },
	{"FAN"       ,COL(0x8080FF),State_NONE  ,1,0    ,0  ,1  ,0,0  ,0  ,1,0.1  ,0.9,0	 },
	{"Element_9" ,COL(0xB0A090),0           ,0,0    ,0  ,0.5},
	{"ICE"       ,COL(0xD0D0FF),State_SOLID ,0,-1000,40 ,1  ,0,0.8,1  ,1,0.1  ,0.3,4	 },
	{"SNOW"      ,COL(0xFFFFFF),State_POWDER,1,-500 ,10 ,0.5,0,0.2,0.2,0,0.02 ,0.5,1	 },
	{"STEAM"     ,COL(0xE0E0E0),State_NONE  ,1,0    ,30 ,1  ,0,0.2,0.2,1,0.05 ,0.5,1	 },
	{"SUPERBALL" ,COL(0xFF40A0),State_POWDER,1,0    ,10 ,0.5,0,0  ,0  ,0,0.1  ,0.3,8	 },
	{"CLONE"     ,COL(0x907010),State_SOLID ,0,0    ,0  ,0.5,0,0.2,0.2,1,0.1  ,0.3,3	 },
	{"FIREWORKS" ,COL(0xFF9966),State_POWDER,1,0    ,10 ,0.5,0,0.5,0.5,0,0.1  ,0.3,8	 },
	{"OIL"       ,COL(0x803020),State_LIQUID,1,0    ,30 ,0.8,0,0  ,0  ,1,0.1  ,0	,3	 },
	{"C4"        ,COL(0xFFFFCC),State_SOLID ,0,0    ,100,0.5,0,0.5,0.5,1,0.1  ,0.2,4	 },
	{"Element_18",COL(0xFFE0AE)},
	{"STONE"     ,COL(0x808080),State_POWDER,1,0    ,20 ,0.5,0,0.9,0.9,1,0.1  ,0.1,9	 },
	{"MAGMA"     ,COL(0xFF6633),State_HOT   ,1,10000,50 ,0.5,1,0.2,0.2,1,0.1  ,0	,9	 },
	{"VIRUS"     ,COL(0x800080),State_POWDER,1,0    ,10 ,0.5,0,0  ,0  ,1,0.1  ,0.5,1	 },
	{"Element_22",COL(0xFFE0AE)},
	{"NITRO"     ,COL(0x447700),State_LIQUID,1,0    ,100,0.8,0,0  ,0  ,1,0.1  ,0.3,5	 },
	{"ANT"       ,COL(0xC080C0),State_POWDER,1,1500 ,5  ,0.5,0,0.3,0.3,0,0.1  ,0.5,1	 },
	{"TORCH"     ,COL(0xFFA020),State_HOT   ,0,4000 ,10 ,0  ,1,0  ,0  ,1,0.1  ,0.3,0	 },
	{"GAS"       ,COL(0xCC9999),State_GAS   ,1,500  ,5  ,1  ,0,0  ,0  ,1,-0.01,0.5,-1 },
	{"SOAPY"     ,COL(0xE0E0E0),State_LIQUID,1,0    ,30 ,1  ,0,0  ,1  ,1,0.1  ,0.4,4	 },
	{"THUNDER"   ,COL(0xFFFF20),State_HOT   ,0,2000 ,0  ,0  ,1,0  ,0  ,1,0.1  ,0	,100},
	{"METAL"     ,COL(0x404040),State_SOLID ,0,0    ,10 ,0.5,0,0.9,0.9,1,0.2  ,0	,9	 },
	{"Element_30",COL(0xFFE0AE)},
	{"BOMB"      ,COL(0x666600),State_POWDER,1,0    ,10 ,0.5,0,0.9,0.9,1,0.1  ,0.1,10 },
	{"Element_32",COL(0xFFE0AE)},
	{"LASER"     ,COL(0xCC0000),State_HOT   ,1,5500 ,5  ,0  ,1,0  ,0  ,0,0.1  ,0	,0	 },
	{"ACID"      ,COL(0xCCFF00),State_LIQUID,1,0    ,0  ,0.8,0,0  ,0  ,1,0.1  ,0.4,6	 },
	{"VINE"      ,COL(0x00BB00),State_SOLID ,0,500  ,10 ,0.5,0,0.8,0.2,0,0.1  ,0.4,1	 },
	{"SALT"      ,COL(0xFFFFFF),State_POWDER,1,0    ,5  ,0.5,0,0.2,0.2,1,0.1  ,0.5,1	 },
	{"SEAWATER" ,COL(0x3399FF),State_LIQUID,1,0    ,40 ,0.8,0,0  ,0  ,1,0.1  ,0.4,5	 },
	{"GLASS"     ,COL(0x011111),State_SOLID ,0,0    ,0  ,0.9,0,0.9,0.5,1,0.1  ,0.2,8	 },
	{"BIRD"      ,COL(0x807050),State_GAS   ,1,2000 ,10 ,0.1,0,0.1,0.1,1,0.05 ,0.5,0	 },
	{"Save_BALL" ,COL(0xFFE0AE)},
	{"MERCURY"   ,COL(0xAAAAAA),State_LIQUID,1,0    ,20 ,1  ,0,0.9,0.9,0,0.2  ,0  ,20 },
	{"SPARK"     ,COL(0xFFCC33),State_HOT   ,1,3000 ,5  ,0.5,1,0.9,0.9,0,0.1  ,0.5,1	 },
	{"FUSE"      ,COL(0x443322),State_SOLID ,0,0    ,50 ,0.5,0,0.5,0.5,1,0.1  ,0.2,4	 },
	{"CLOUD"     ,COL(0xCCCCCC),State_GAS   ,1,0    ,5  ,1  ,0,0  ,0  ,1,-0.02,0.5,-2 },
	{"PUMP"      ,COL(0x003333),State_SOLID ,0,0    ,0  ,0.5,0,0.9,0.9,1,0.1  ,0  ,9	 },
};
