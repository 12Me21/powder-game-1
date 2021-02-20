#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elements.h"
#include "draw.h"
#include "part.h"
#include "bg.h"

static Color normalMenuImage[HEIGHT-308][WIDTH];

static void Draw_count(int x, int y, int n, Color c) {
	char buffer[29];
	sprintf(buffer, "  %d", n);
	Draw_spacedText(12+x,311+y,buffer,c,0,-1);
}

int Pen_x, Pen_y;

bool Menu_numberMenu = false;
bool Menu_copyMode = false;
bool Menu_paused = false;
bool Menu_cursorInMenu = false;
int Menu_penMode = 0;
int Menu_leftSelection = 0;
int Menu_rightSelection = 0;
int Menu_penSize = 0;
int Menu_zoomLevel = 0;
int Menu_dotLimit = 0;
int Menu_gridSize = 0;
int Menu_carefully = 0;
int Menu_bgMode = Bg_NONE;
int Menu_edgeMode = 0;
int Menu_gameSpeed = 0;
bool Menu_minimapEnabled = false;
int buttonflash = 0;
int Menu_fps = 0;

int Part_LIMITS[3] = {10000, 20000, 40000}; //todo;

void Menu_render(void) {
	memcpy(Draw_pxRef(0, 308), normalMenuImage, sizeof(normalMenuImage));
	int* counts = Part_updateCounts();
	int c=12;
	int e=311;
	if (Menu_numberMenu) {
		Draw_rectangle(c+4+0+8,e+0,48,137,0x404040);
		Draw_rectangle(c+4+56+8,e+0,48,137,0x404040);
		Draw_rectangle(c+4+112+8,e+0,48,137,0x404040);
		Draw_rectangle(c+4+168+8,e+0,48,137,0x404040);
		Draw_rectangle(c+4+224+8,e+42,47,53,0x404040);
		Draw_rectangle(c+4+224+16,e+98,39,25,0x404040);
		Draw_rectangle(c+4+224+8,e+126,47,11,0x404040);
		Draw_rectangle(c+4+112+8-1,e+0+4+14*3,1,7,0x404040);//clear part of THUN
		Draw_count(4+0,0,counts[Elem_POWDER],0xF2BD6B);
		Draw_count(4+0,14,counts[Elem_WATER],0x4040FF);
		Draw_count(4+0,28,counts[Elem_FIRE],0xFF4040);
		Draw_count(4+0,42,counts[Elem_SEED],0x90C040);
		Draw_count(4+0,56,counts[Elem_WOOD],0x805020);
		Draw_count(4+0,70,counts[Elem_GUNPOWDER],0xB08050);
		Draw_count(4+0,84,counts[Elem_FAN],0x8080FF);
		Draw_count(4+0,98,counts[Elem_ICE],0xD0D0FF);
		Draw_count(4+0,112,counts[Elem_SNOW],0xFFFFFF);
		Draw_count(4+0,126,counts[Elem_STEAM],0xE0E0E0);

		Draw_count(4+56,0,counts[Elem_SUPERBALL],0xFF40A0);
		Draw_count(4+56,14,counts[Elem_CLONE],0x907010);
		Draw_count(4+56,28,counts[Elem_FIREWORKS],0xFF9966);
		Draw_count(4+56,42,counts[Elem_OIL],0x803020);
		Draw_count(4+56,56,counts[Elem_C4],0xFFFFCC);
		Draw_count(4+56,70,counts[Elem_STONE],0x808080);
		Draw_count(4+56,84,counts[Elem_MAGMA],0xFF6633);
		Draw_count(4+56,98,counts[Elem_VIRUS],0x800080);
		Draw_count(4+56,112,counts[Elem_NITRO],0x447700);
		Draw_count(4+56,126,counts[Elem_ANT],0xC080C0);

		Draw_count(4+112,0,counts[Elem_TORCH],0xFFA020);
		Draw_count(4+112,14,counts[Elem_GAS],0xCC9999);
		Draw_count(4+112,28,counts[Elem_SOAPY],0xE0E0E0);
		Draw_count(4+112,42,counts[Elem_THUNDER],0xFFFF20);
		Draw_count(4+112,56,counts[Elem_METAL],0x404040);
		Draw_count(4+112,70,counts[Elem_BOMB],0x666600);
		Draw_count(4+112,84,counts[Elem_LASER],0xCC0000);
		Draw_count(4+112,98,counts[Elem_ACID],0xCCFF00);
		Draw_count(4+112,112,counts[Elem_VINE],0x00BB00);
		Draw_count(4+112,126,counts[Elem_SALT],0xFFFFFF);

		Draw_count(4+168,0,counts[Elem_SALTWATER],0x3399FF);
		Draw_count(4+168,14,counts[Elem_GLASS],0x404040);
		Draw_count(4+168,28,counts[Elem_BIRD],0x807050);
		Draw_count(4+168,42,counts[Elem_MERCURY],0xAAAAAA);
		Draw_count(4+168,56,counts[Elem_SPARK],0xFFCC33);
		Draw_count(4+168,70,counts[Elem_FUSE],0x443322);
		Draw_count(4+168,84,counts[Elem_CLOUD],0xCCCCCC);
		Draw_count(4+168,98,counts[Elem_PUMP],0x003333);
	}
	if (Menu_numberMenu)
		Draw_line(8,308,408,308,0x660000);
	if (Menu_copyMode)
		Draw_spacedText(c+4+280-1,e+42,"Copy",0xFF4040,-1,-2);
	else
		Draw_spacedText(c+4+280+23,e+42,"Paste",0xFF4040,-1,-3);
	static char* a[] = {"free","line","lock","paint"};
	Draw_spacedText(c+4+280+(4*(8-2)),e+70,a[Menu_penMode],-1,0,-2);
	Draw_spacedText(c+4+280+(4*(8-2)),e+70,a[Menu_penMode],0xFFFFFF,-1,-2);
	Draw_printf(c+4+280-1,e+84,0xFFFFFF,0,-1, "      %d", Menu_penSize);
	Draw_spacedText(c+4+280+(6*(8-2)),e+98,(char*[]){"x1","x2","x4","x8","16"}[Menu_zoomLevel],0xFFFFFF,0,-2);

	Draw_printf(c+4+280,e+112,0xFFFFFF,0,-2, "       %d", 1<<Menu_gameSpeed);
	if (!Menu_paused)
		Draw_spacedText(c+4+280-1,e+126,"Start",0xFF4040,-1,-3);
	else
		Draw_spacedText(c+4+280+25,e+126,"Stop",0xFF4040,-1,-2);
	if (buttonflash>0) {
		buttonflash--;
		if (buttonflash>1)
			Draw_text(c+4+336,e+14,"SAVE",0xFFFFFF,0xFF0000);
	}
	if (buttonflash<0) {
		buttonflash++;
		if (buttonflash<-1)
			Draw_text(c+4+336,e+28,"LOAD",0xFFFFFF,0xFF0000);
	}
	if (Menu_minimapEnabled)
		Draw_spacedText(c+4+336,e+42,"MiniMap",0xFFFFFF,0xFF0000,-1);
	
	char* str = Menu_numberMenu ? "     num" : "     str";
	Draw_spacedText(c+4+336,e+56,str,-1,0,-2);
	Draw_spacedText(c+4+336,e+56,str,0xFFFFFF,-1,-2);
	str = Menu_edgeMode ? "OFF" : "LOOP";
	Draw_spacedText(c+4+336+25,e+70,str,-1,0,-2);
	Draw_spacedText(c+4+336+25,e+70,str,0xFFFFFF,-1,-2);
	//Draw_text(c+4+336,e+84,"     "+Menu_gridSize,8388608,0)
	str = (char*[]){"none","air","line","blur","shade","aura","light","toon","mesh","gray","track","dark","TG","siluet"}[Menu_bgMode];
	Draw_spacedText(c+4+336+6*3,e+98,str,-1,0,-2);
	Draw_spacedText(c+4+336+6*3,e+98,str,0xFFFFFF,-1,-2);
	Draw_text(c+4+336+8*4,e+112,(char*[]){"S","M","L"}[Menu_dotLimit],0xFFFFFF,0);
	Draw_rectangle(c+0+56*(Menu_leftSelection/10),e+Menu_leftSelection%10*14,3,3,0xFF0000);
	///rectangle(c+0+56*floor(Menu_middleSelection/10),e+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	Draw_rectangle(c+0+56*(Menu_rightSelection/10),e+8+Menu_rightSelection%10*14,3,3,0x0000FF);
	Draw_printf(64,451,-1,0,-1," %d",Pen_x-8);
	Draw_printf(64,451,-1,0,-1,"      %d",Pen_y-8);
	//Draw_printf(141,451,-1,0,-1,"   %d",Parts_limits[Menu_dotLimit]-Parts_used);
	Draw_printf(16,451,-1,0,0,"%dfps",Menu_fps);
	//if(sldebug==1){
	//	k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	//}
	//draw Menu_minimapEnabled
	/*if (Menu_minimapEnabled) {
		c=15;
		if (mouse.old.x<116 && Menu_cursorInMenu)
			c=127;
		e=314;
		Draw_rectangle(c-3,e-3,106,81,0x808080);
		save1();
		a=0;
		c=WIDTH*e+c;
		for (b=0;b<300;b+=4,c+=WIDTH-100) {
			for (d=0;d<400;d+=4,c++) {
				e=b*400+d;
				if (savedataarray[e]==0)
					e+=401;
				a=
					Menu_bgMode==Bg_DARK?
						states[savedataarray[e]]==State_HOT?
							savedataarray[e]
						:
							0
					:
						Menu_bgMode==Bg_SILUET?
							savedataarray[e]==0?
								0
							:
								1
						:
							savedataarray[e];
				
				screenbuffer[c]=
					Menu_bgMode==Bg_GRAY?
pp						grays[a]
					:
						Menu_bgMode==Bg_SILUET?
							a==0?
								0xFFFFFF
							:
								0
						:
							colors[a];
			}
		}
		}
	//*/
	//setsize(normalmenuimage,WIDTH,HEIGHT-308);
}

void Draw_init(void) {
	Draw_rectangle(0,0,WIDTH,HEIGHT,0x404040);
	Draw_spacedText(211,451,"DAN-BALL.jp (C) 2007 ha55ii",-1,0,-1);
	Draw_text(16,311,"POWDER",0xF2BD6B,0);
	Draw_text(16,325,"WATER",0x4040FF,0);
	Draw_text(16,339,"FIRE",0xFF4040,0);
	Draw_text(16,353,"SEED",0x90C040,0);
	Draw_text(16,367,"WOOD",0x805020,0);
	// -2 spaced text needs to be drawn this special way
	// maybe fix this
	Draw_spacedText(16,381,"G-POWDER",-1,0,-2);
	Draw_spacedText(16,381,"G-POWDER",0xB08050,-1,-2);
	Draw_text(16,395,"FAN",0x8080FF,0);
	Draw_text(16,409,"ICE",0xD0D0FF,0);
	Draw_text(16,423,"SNOW",0xFFFFFF,0);
	Draw_text(16,437,"STEAM",0xE0E0E0,0);
		
	Draw_text(72,311,"S-BALL",0xFF40A0,0);
	Draw_text(72,325,"CLONE",0x907010,0);
	Draw_spacedText(72,339,"F-WORKS",0xFF9966,0,-1);
	Draw_text(72,353,"OIL",0x803020,0);
	Draw_text(72,367,"C-4",0xFFFFCC,0);
	Draw_text(72,381,"STONE",0x808080,0);
	Draw_text(72,395,"MAGMA",0xFF6633,0);
	Draw_text(72,409,"VIRUS",0x800080,0);
	Draw_text(72,423,"NITRO",0x447700,0);
	Draw_text(72,437,"ANT",0xC080C0,0);
		
	Draw_text(128,311,"TORCH",0xFFA020,0);
	Draw_text(128,325,"GAS",0xCC9999,0);
	Draw_text(128,339,"SOAPY",0xE0E0E0,0);
	Draw_spacedText(128,353,"THUNDER",0xFFFF20,0,-1);
	Draw_text(128,367,"METAL",0x404040,0);
	Draw_text(128,381,"BOMB",0x666600,0);
	Draw_text(128,395,"LASER",0xCC0000,0);
	Draw_text(128,409,"ACID",0xCCFF00,0);
	Draw_text(128,423,"VINE",0x00BB00,0);
	Draw_text(128,437,"SALT",0xFFFFFF,0);
		
	Draw_spacedText(184,311,"S-WATER",0x3399FF,0,-1);
	Draw_text(184,325,"GLASS",0x404040,0);
	Draw_text(184,339,"BIRD",0x807050,0);
	Draw_spacedText(184,353,"MERCURY",0xAAAAAA,0,-1);
	Draw_text(184,367,"SPARK",0xFFCC33,0);
	Draw_text(184,381,"FUSE",0x443322,0);
	Draw_text(184,395,"CLOUD",0xCCCCCC,0);
	Draw_text(184,409,"PUMP",0x003333,0);
		
	Draw_text(240,311,"WIND",0x8080FF,0);
	Draw_text(240,325,"AIR",0x8080FF,0);
	Draw_text(240,339,"DRAG",0xFFFFFF,0);
	Draw_text(240,353,"B",0xFFE0E0,0);
	Draw_text(240,353," U",0xFFFFE0,0);
	Draw_text(240,353,"  B",0xE0FFE0,0);
	Draw_text(240,353,"   B",0xE0FFFF,0);
	Draw_text(240,353,"    L",0xE0E0FF,0);
	Draw_text(240,353,"     E",0xFFE0FF,0);
	Draw_text(240,367,"WHEEL",0xB0A090,0);
	Draw_text(240,381,"PLAYER",0xF2BD6B,0);
	Draw_spacedText(240,395,"FIGHTER",0xF2BD6B,0,-1);
	Draw_text(240,409,"BOX",0xF2BD6B,0);
	Draw_text(240,423,"BALL",0xF2BD6B,0);
	Draw_text(240,437,"CREATE",0x907010,0);
	Draw_text(296,311,"BLOCK",0x808080,0);
	Draw_text(296,325,"ERASE",0x808080,0); //rename?
	Draw_text(296,339,"CLEAR",0xFFFFFF,0);
	Draw_spacedText(295,353,"Copy",-1,0,-2);
	Draw_spacedText(295,353,"Copy",0xFFFFFF,-1,-2);
	Draw_spacedText(319,353,"Paste",-1,0,-3);
	Draw_spacedText(319,353,"Paste",0xFFFFFF,-1,-3);
	Draw_text(296,367,"TEXT",0xFFFFFF,0);
	Draw_spacedText(296,381,"PEN",-1,0,-1);
	Draw_spacedText(296,381,"PEN",0xFFFFFF,-1,-1);
	Draw_spacedText(296,395,"PEN-S ",0xFFFFFF,0,-1);
	Draw_spacedText(296,409,"SCALE",0xFFFFFF,0,-1);
	Draw_spacedText(296,423,"SPEEDx",0xFFFFFF,0,-1);
	Draw_spacedText(295,437,"Start",-1,0,-3);
	Draw_spacedText(295,437,"Start",0xFFFFFF,-1,-3);
	Draw_spacedText(321,437,"Stop",-1,0,-2);
	Draw_spacedText(321,437,"Stop",0xFFFFFF,-1,-2);
	Draw_text(352,311,"UPLOAD",0xFFA0A0,0);
	Draw_text(352,325,"SAVE",0xFFA0A0,0);
	Draw_text(352,339,"LOAD",0xFFA0A0,0);
	Draw_spacedText(352,353,"MiniMap",0xFFA0A0,0,-1);
	Draw_spacedText(352,367,"MENU-",-1,0,-2);
	Draw_spacedText(352,367,"MENU-",0xFFFFFF,-1,-2);
	Draw_spacedText(352,381,"SIDE-",-1,0,-3);
	Draw_spacedText(352,381,"SIDE-",0xFFFFFF,-1,-3);
	Draw_text(352,395,"GRID",0x800000,0);
	Draw_spacedText(352,409,"BG-",-1,0,-2);
	Draw_spacedText(352,409,"BG-",0xFFFFFF,-1,-2);
	Draw_text(352,423,"DOT ",0xFFFFFF,0);
	Draw_text(352,437,"RESET",0xFFFFFF,0);
	Draw_spacedText(64,451,"x    y",-1,0,-1);
	Draw_spacedText(141,451,"dot",-1,0,-1);
	memcpy(normalMenuImage, Draw_pxRef(0, 308), sizeof(normalMenuImage));
}
