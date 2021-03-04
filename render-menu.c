#include <stdio.h>
#include <string.h>
#include "common.h"
#include "menu.h"
#include "elements.h"
#include "part.h"
#include "bg.h"
#include "draw.h"
#include "entity.h"
#include "save.h"
#include "input.h"

static Color normalMenuImage[MENU_HEIGHT][MENU_WIDTH];

static const axis col1 = 8;
static const axis col2 = 64;
static const axis col3 = 120;
static const axis col4 = 176;
static const axis col5 = 232;
static const axis col6 = 288;
static const axis col7 = 344;

static const axis row1 = 3;
static const axis row2 = 64;
static const axis row3 = 120;
static const axis row4 = 176;
static const axis row5 = 232;
static const axis row6 = 288;
static const axis row7 = 344;

static const axis rowLast = 143;

AUTORUN {
	Draw_mrectangle(0,0,MENU_WIDTH,MENU_HEIGHT,0x404040);
	Draw_spacedText(203,rowLast,"DAN-BALL.jp (C) 2007 ha55ii",-1,0,-1);
	Draw_text(col1,row1,"POWDER",0xF2BD6B,0);
	Draw_text(col1,17,"WATER",0x4040FF,0);
	Draw_text(col1,31,"FIRE",0xFF4040,0);
	Draw_text(col1,45,"SEED",0x90C040,0);
	Draw_text(col1,59,"WOOD",0x805020,0);
	// -2 spaced text needs to be drawn this special way
	// maybe fix this
	Draw_spacedText(col1,73,"G-POWDER",-1,0,-2);
	Draw_spacedText(col1,73,"G-POWDER",0xB08050,-1,-2);
	Draw_text(col1,87,"FAN",0x8080FF,0);
	Draw_text(col1,101,"ICE",0xD0D0FF,0);
	Draw_text(col1,115,"SNOW",0xFFFFFF,0);
	Draw_text(col1,129,"STEAM",0xE0E0E0,0);
		
	Draw_text(col2,row1,"S-BALL",0xFF40A0,0);
	Draw_text(col2,17,"CLONE",0x907010,0);
	Draw_spacedText(col2,31,"F-WORKS",0xFF9966,0,-1);
	Draw_text(col2,45,"OIL",0x803020,0);
	Draw_text(col2,59,"C-4",0xFFFFCC,0);
	Draw_text(col2,73,"STONE",0x808080,0);
	Draw_text(col2,87,"MAGMA",0xFF6633,0);
	Draw_text(col2,101,"VIRUS",0x800080,0);
	Draw_text(col2,115,"NITRO",0x447700,0);
	Draw_text(col2,129,"ANT",0xC080C0,0);
		
	Draw_text(col3,row1,"TORCH",0xFFA020,0);
	Draw_text(col3,17,"GAS",0xCC9999,0);
	Draw_text(col3,31,"SOAPY",0xE0E0E0,0);
	Draw_spacedText(col3,45,"THUNDER",0xFFFF20,0,-1);
	Draw_text(col3,59,"METAL",0x404040,0);
	Draw_text(col3,73,"BOMB",0x666600,0);
	Draw_text(col3,87,"LASER",0xCC0000,0);
	Draw_text(col3,101,"ACID",0xCCFF00,0);
	Draw_text(col3,115,"VINE",0x00BB00,0);
	Draw_text(col3,129,"SALT",0xFFFFFF,0);
		
	Draw_spacedText(col4,row1,"S-WATER",0x3399FF,0,-1);
	Draw_text(col4,17,"GLASS",0x404040,0);
	Draw_text(col4,31,"BIRD",0x807050,0);
	Draw_spacedText(col4,45,"MERCURY",0xAAAAAA,0,-1);
	Draw_text(col4,59,"SPARK",0xFFCC33,0);
	Draw_text(col4,73,"FUSE",0x443322,0);
	Draw_text(col4,87,"CLOUD",0xCCCCCC,0);
	Draw_text(col4,101,"PUMP",0x003333,0);
		
	Draw_text(col5,row1,"WIND",0x8080FF,0);
	Draw_text(col5,17,"AIR",0x8080FF,0);
	Draw_text(col5,31,"DRAG",0xFFFFFF,0);
	Draw_text(col5,45,"B",0xFFE0E0,0);
	Draw_text(col5,45," U",0xFFFFE0,0);
	Draw_text(col5,45,"  B",0xE0FFE0,0);
	Draw_text(col5,45,"   B",0xE0FFFF,0);
	Draw_text(col5,45,"    L",0xE0E0FF,0);
	Draw_text(col5,45,"     E",0xFFE0FF,0);
	Draw_text(col5,59,"WHEEL",0xB0A090,0);
	Draw_text(col5,73,"PLAYER",0xF2BD6B,0);
	Draw_spacedText(col5,87,"FIGHTER",0xF2BD6B,0,-1);
	Draw_text(col5,101,"BOX",0xF2BD6B,0);
	Draw_text(col5,115,"BALL",0xF2BD6B,0);
	Draw_text(col5,129,"CREATE",0x907010,0);
	
	Draw_text(col6,row1,"BLOCK",0x808080,0);
	Draw_text(col6,17,"ERASE",0x808080,0); //rename?
	Draw_text(col6,31,"CLEAR",0xFFFFFF,0);
	Draw_spacedText(col6-1,45,"Copy",-1,0,-2);
	Draw_spacedText(col6-1,45,"Copy",0xFFFFFF,-1,-2);
	Draw_spacedText(col6+23,45,"Paste",-1,0,-3);
	Draw_spacedText(col6+23,45,"Paste",0xFFFFFF,-1,-3);
	Draw_text(col6,59,"TEXT",0xFFFFFF,0);
	Draw_spacedText(col6,73,"PEN",-1,0,-1);
	Draw_spacedText(col6,73,"PEN",0xFFFFFF,-1,-1);
	Draw_spacedText(col6,87,"PEN-S ",0xFFFFFF,0,-1);
	Draw_spacedText(col6,101,"SCALE",0xFFFFFF,0,-1);
	Draw_spacedText(col6,115,"SPEEDx",0xFFFFFF,0,-1);
	Draw_spacedText(col6-1,129,"Start",-1,0,-3);
	Draw_spacedText(col6-1,129,"Start",0xFFFFFF,-1,-3);
	Draw_spacedText(col6+25,129,"Stop",-1,0,-2);
	Draw_spacedText(col6+25,129,"Stop",0xFFFFFF,-1,-2);
	
	Draw_text(col7,row1,"UPLOAD",0xFFA0A0,0);
	Draw_text(col7,17,"SAVE",0xFFA0A0,0);
	Draw_text(col7,31,"LOAD",0xFFA0A0,0);
	Draw_spacedText(col7,45,"MiniMap",0xFFA0A0,0,-1);
	Draw_spacedText(col7,59,"MENU-",-1,0,-2);
	Draw_spacedText(col7,59,"MENU-",0xFFFFFF,-1,-2);
	Draw_spacedText(col7,73,"SIDE-",-1,0,-3);
	Draw_spacedText(col7,73,"SIDE-",0xFFFFFF,-1,-3);
	Draw_text(col7,87,"GRID",0x800000,0);
	Draw_spacedText(col7,101,"BG-",-1,0,-2);
	Draw_spacedText(col7,101,"BG-",0xFFFFFF,-1,-2);
	Draw_text(col7,115,"DOT ",0xFFFFFF,0);
	Draw_text(col7,129,"RESET",0xFFFFFF,0);
	
	Draw_spacedText(56,rowLast,"x    y",-1,0,-1);
	Draw_spacedText(133,rowLast,"dot",-1,0,-1);
	memcpy(normalMenuImage, Menu_grp, sizeof(normalMenuImage));
}

void Menu_render(void) {
	if (!Menu_cursorInMenu /*&& !wa*/) {
		if (Menu_leftSelection==Menu_BLOCK||Menu_leftSelection==Menu_ERASE||Menu_leftSelection==Menu_CLEAR||Menu_rightSelection==Menu_BLOCK||Menu_rightSelection==Menu_ERASE||Menu_rightSelection==Menu_CLEAR) {
			const char* paths[] = {
				"",
				"111222333444",
				"1111111222222233333334444444",
				"11111111111222222222223333333333344444444444",
				"111111122221111222222233332222333333344443333444444411114444",
				"1111111111122221111222222222223333222233333333333444433334444444444411114444",
				"11111111111111122221111222222222222222333322223333333333333334444333344444444444444411114444",
				"111111111112222111122221111222222222223333222233332222333333333334444333344443333444444444441111444411114444",
				"1111111111111112222111122221111222222222222222333322223333222233333333333333344443333444433334444444444444441111444411114444",
				"11111111111111111112222111122221111222222222222222222233332222333322223333333333333333333444433334444333344444444444444444441111444411114444",
				"111111111111111222211111111222222221111222222222222222333322222222333333332222333333333333333444433333333444444443333444444444444444111144444444111111114444",
			};
			axis cy = ((Pen_oldy>>2)-1-(int)(Menu_penSize/2) + (axis[]){0,1,1,1,2,2,2,3,3,3,4}[Menu_penSize])*4;
			axis cx = ((Pen_oldx>>2)-1-(int)(Menu_penSize/2) + (axis[]){0,1,1,1,1,1,1,1,1,1,1}[Menu_penSize])*4;
			for (const char* c=paths[Menu_penSize]; *c; c++) {
				axis x = clamp(cx, 0, WIDTH-1);
				axis y = clamp(cy, 0, H+8);
				grp[y][x] = 0xC00000;
				switch (*c) {
				when('1'):; cx++;
				when('2'):; cy++;
				when('3'):; cx--;
				when('4'):; cy--;
				}
			}
		}
		if (Menu_leftSelection==Menu_FAN||Menu_rightSelection==Menu_FAN||Menu_leftSelection==Menu_WIND||Menu_rightSelection==Menu_WIND||Menu_leftSelection==Menu_LASER||Menu_rightSelection==Menu_LASER){ //fan,wind,laser (buttons, not element ids)
			Point a = Vec_mul2(Pen_dir, 30);
			Draw_line(Pen_x+a.x, Pen_y+a.y, Pen_x, Pen_y, 0xFF0000);
		}
	}

	memcpy(Menu_grp, normalMenuImage, sizeof(normalMenuImage));
	if (Menu_numberMenu) {
		int* counts = Part_updateCounts();
		void Draw_count(int i, int elem) {
			axis x = i/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
			axis y = i%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
			char buffer[29];
			buffer[0] = ELEMENTS[elem].name[0];
			buffer[1] = 0;
			Draw_mrectangle(4+x+4, 11-8+y, Menu_BUTTONWIDTH, Menu_BUTTONHEIGHT, 0x404040);
			Draw_text(4+4+x,11-8+y,buffer,ELEMENTS[elem].color, 0);
			sprintf(buffer, "  %d", counts[elem]);
			Draw_spacedText(4+x,11-8+y,buffer,ELEMENTS[elem].color,0,-1);
		}
		for (int i=0; i<38; i++) {
			Draw_count(i, Menu_BUTTONS[i].element);
		}
		Draw_mrectangle(0,0,W,1,0x660000);
	}
	if (Menu_hover>=0) {
		axis bx = 4+Menu_hover/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
		axis by = 2+Menu_hover%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
		for (axis y=0; y<Menu_BUTTONHEIGHT-1; y++)
			for (axis x=0; x<Menu_BUTTONWIDTH; x++) {
				Color* px = &Menu_grp[by+y][bx+x];
				if (*px == 0x404040)
					*px = 0x400000;
			}
	}
	// ...
	if (Menu_copyMode)
		Draw_spacedText(col6-1,45,"Copy",0xFF4040,-1,-2);
	else
		Draw_spacedText(col6+23,45,"Paste",0xFF4040,-1,-3);
	static char* a[] = {"free","line","lock","paint"};
	Draw_spacedText(8+280+(4*(8-2)),73,a[Menu_penMode],-1,0,-2);
	Draw_spacedText(8+280+(4*(8-2)),73,a[Menu_penMode],0xFFFFFF,-1,-2);
	Draw_printf(8+280-1,87,0xFFFFFF,0,-1, "      %d", Menu_penSize);
	Draw_printf(8+280,101,0xFFFFFF,0,-2,"      %s",(char*[]){"x1","x2","x4","x8","16"}[Menu_zoomLevel]);
	Draw_printf(8+280,115,0xFFFFFF,0,-2, "       %d", 1<<Menu_gameSpeed);
	if (!Menu_paused)
		Draw_spacedText(col6-1,129,"Start",0xFF4040,-1,-3);
	else
		Draw_spacedText(col6+25,129,"Stop",0xFF4040,-1,-2);
	if (buttonflash>0) {
		buttonflash--;
		if (buttonflash>1)
			Draw_text(col7,3+14,"SAVE",0xFFFFFF,0xFF0000);
	}
	if (buttonflash<0) {
		buttonflash++;
		if (buttonflash<-1)
			Draw_text(col7,3+28,"LOAD",0xFFFFFF,0xFF0000);
	}
	if (Menu_minimapEnabled)
		Draw_spacedText(8+336,3+42,"MiniMap",0xFFFFFF,0xFF0000,-1);
	char* str = Menu_numberMenu ? "     num" : "     str";
	Draw_spacedText(8+336,59,str,-1,0,-2);
	Draw_spacedText(8+336,59,str,0xFFFFFF,-1,-2);
	str = Menu_edgeMode ? "OFF" : "LOOP";
	Draw_spacedText(8+336+25,73,str,-1,0,-2);
	Draw_spacedText(8+336+25,73,str,0xFFFFFF,-1,-2);
	Draw_printf(8+336,87,0x800000,0,0,"     %d",Menu_gridSize); //this is too dark
	str = (char*[]){"none","air","line","blur","shade","aura","light","toon","mesh","gray","track","dark","TG","siluet"}[Menu_bgMode];
	Draw_spacedText(8+336+6*3,101,str,-1,0,-2);
	Draw_spacedText(8+336+6*3,101,str,0xFFFFFF,-1,-2);
	Draw_text(8+336+8*4,3+112,(char*[]){"S","M","L"}[Menu_dotLimit],0xFFFFFF,0);
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_leftSelection/Menu_BUTTONROWS),11-8+Menu_leftSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,4,0xFF0000);
	///rectangle(4+0+56*floor(Menu_middleSelection/10),3+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_rightSelection/Menu_BUTTONROWS),11+Menu_rightSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,4,0x0000FF);
	Draw_printf(64-8,rowLast,-1,0,-1," %d",Pen_x-8);
	Draw_printf(64-8,rowLast,-1,0,-1,"      %d",Pen_y-8);
	//Draw_printf(141,451,-1,0,-1,"   %d",Parts_limits[Menu_dotLimit]-Parts_used);
	Draw_printf(0,rowLast,-1,0,0,"%3dfps",Menu_fps);
	//if(sldebug==1){
	//	k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	//}
	//draw Menu_minimapEnabled
	if (Menu_minimapEnabled) {
		axis sx=15-8;
		if (mouse.oldPos.x<116 && Menu_cursorInMenu)
			sx=127-8;
		axis sy=14;
		Draw_mrectangle(sx-3,sy-3,W/4+6,H/4+6,0x808080);
		Save_save1();
		for (axis y=0; y<H; y+=4) {
			for (axis d=0; d<W; d+=4) {
				Elem type = Save_data[y][d].type ?: Save_data[y+1][d+1].type;
				Elem a = 0;
				if (Menu_bgMode == Bg_DARK) {
					if (ELEMENTS[type].state == State_HOT)
						a = type;
				} else if (Menu_bgMode==Bg_SILUET) {
					if (type)
						a = 1;
				} else
					a = type;
				Color col;
				if (Menu_bgMode==Bg_GRAY)
					col = ELEMENTS[a].grayColor;
				else if (Menu_bgMode==Bg_SILUET)
					col = a==0 ? 0xFFFFFF : 0;
				else
					col = ELEMENTS[a].color;
				Menu_grp[sy+y/4][sx+d/4] = col;
			}
		}
	}
}
