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

AUTORUN {
	Draw_mrectangle(0,0,MENU_WIDTH,MENU_HEIGHT,0x404040);
	Draw_spacedText(203,143,"DAN-BALL.jp (C) 2007 ha55ii",-1,0,-1);
	Draw_text(8,3,"POWDER",0xF2BD6B,0);
	Draw_text(8,17,"WATER",0x4040FF,0);
	Draw_text(8,31,"FIRE",0xFF4040,0);
	Draw_text(8,45,"SEED",0x90C040,0);
	Draw_text(8,59,"WOOD",0x805020,0);
	// -2 spaced text needs to be drawn this special way
	// maybe fix this
	Draw_spacedText(8,73,"G-POWDER",-1,0,-2);
	Draw_spacedText(8,73,"G-POWDER",0xB08050,-1,-2);
	Draw_text(8,87,"FAN",0x8080FF,0);
	Draw_text(8,101,"ICE",0xD0D0FF,0);
	Draw_text(8,115,"SNOW",0xFFFFFF,0);
	Draw_text(8,129,"STEAM",0xE0E0E0,0);
		
	Draw_text(64,3,"S-BALL",0xFF40A0,0);
	Draw_text(64,17,"CLONE",0x907010,0);
	Draw_spacedText(64,31,"F-WORKS",0xFF9966,0,-1);
	Draw_text(64,45,"OIL",0x803020,0);
	Draw_text(64,59,"C-4",0xFFFFCC,0);
	Draw_text(64,73,"STONE",0x808080,0);
	Draw_text(64,87,"MAGMA",0xFF6633,0);
	Draw_text(64,101,"VIRUS",0x800080,0);
	Draw_text(64,115,"NITRO",0x447700,0);
	Draw_text(64,129,"ANT",0xC080C0,0);
		
	Draw_text(120,3,"TORCH",0xFFA020,0);
	Draw_text(120,17,"GAS",0xCC9999,0);
	Draw_text(120,31,"SOAPY",0xE0E0E0,0);
	Draw_spacedText(120,45,"THUNDER",0xFFFF20,0,-1);
	Draw_text(120,59,"METAL",0x404040,0);
	Draw_text(120,73,"BOMB",0x666600,0);
	Draw_text(120,87,"LASER",0xCC0000,0);
	Draw_text(120,101,"ACID",0xCCFF00,0);
	Draw_text(120,115,"VINE",0x00BB00,0);
	Draw_text(120,129,"SALT",0xFFFFFF,0);
		
	Draw_spacedText(176,3,"S-WATER",0x3399FF,0,-1);
	Draw_text(176,17,"GLASS",0x404040,0);
	Draw_text(176,31,"BIRD",0x807050,0);
	Draw_spacedText(176,45,"MERCURY",0xAAAAAA,0,-1);
	Draw_text(176,59,"SPARK",0xFFCC33,0);
	Draw_text(176,73,"FUSE",0x443322,0);
	Draw_text(176,87,"CLOUD",0xCCCCCC,0);
	Draw_text(176,101,"PUMP",0x003333,0);
		
	Draw_text(232,3,"WIND",0x8080FF,0);
	Draw_text(232,17,"AIR",0x8080FF,0);
	Draw_text(232,31,"DRAG",0xFFFFFF,0);
	Draw_text(232,45,"B",0xFFE0E0,0);
	Draw_text(232,45," U",0xFFFFE0,0);
	Draw_text(232,45,"  B",0xE0FFE0,0);
	Draw_text(232,45,"   B",0xE0FFFF,0);
	Draw_text(232,45,"    L",0xE0E0FF,0);
	Draw_text(232,45,"     E",0xFFE0FF,0);
	Draw_text(232,59,"WHEEL",0xB0A090,0);
	Draw_text(232,73,"PLAYER",0xF2BD6B,0);
	Draw_spacedText(232,87,"FIGHTER",0xF2BD6B,0,-1);
	Draw_text(232,101,"BOX",0xF2BD6B,0);
	Draw_text(232,115,"BALL",0xF2BD6B,0);
	Draw_text(232,129,"CREATE",0x907010,0);
	
	Draw_text(288,3,"BLOCK",0x808080,0);
	Draw_text(288,17,"ERASE",0x808080,0); //rename?
	Draw_text(288,31,"CLEAR",0xFFFFFF,0);
	Draw_spacedText(288-1,45,"Copy",-1,0,-2);
	Draw_spacedText(288-1,45,"Copy",0xFFFFFF,-1,-2);
	Draw_spacedText(311,45,"Paste",-1,0,-3);
	Draw_spacedText(311,45,"Paste",0xFFFFFF,-1,-3);
	Draw_text(288,59,"TEXT",0xFFFFFF,0);
	Draw_spacedText(288,73,"PEN",-1,0,-1);
	Draw_spacedText(288,73,"PEN",0xFFFFFF,-1,-1);
	Draw_spacedText(288,87,"PEN-S ",0xFFFFFF,0,-1);
	Draw_spacedText(288,101,"SCALE",0xFFFFFF,0,-1);
	Draw_spacedText(288,115,"SPEEDx",0xFFFFFF,0,-1);
	Draw_spacedText(288-1,129,"Start",-1,0,-3);
	Draw_spacedText(288-1,129,"Start",0xFFFFFF,-1,-3);
	Draw_spacedText(313,129,"Stop",-1,0,-2);
	Draw_spacedText(313,129,"Stop",0xFFFFFF,-1,-2);
	
	Draw_text(344,3,"UPLOAD",0xFFA0A0,0);
	Draw_text(344,17,"SAVE",0xFFA0A0,0);
	Draw_text(344,31,"LOAD",0xFFA0A0,0);
	Draw_spacedText(344,45,"MiniMap",0xFFA0A0,0,-1);
	Draw_spacedText(344,59,"MENU-",-1,0,-2);
	Draw_spacedText(344,59,"MENU-",0xFFFFFF,-1,-2);
	Draw_spacedText(344,73,"SIDE-",-1,0,-3);
	Draw_spacedText(344,73,"SIDE-",0xFFFFFF,-1,-3);
	Draw_text(344,87,"GRID",0x800000,0);
	Draw_spacedText(344,101,"BG-",-1,0,-2);
	Draw_spacedText(344,101,"BG-",0xFFFFFF,-1,-2);
	Draw_text(344,115,"DOT ",0xFFFFFF,0);
	Draw_text(344,129,"RESET",0xFFFFFF,0);
	
	Draw_spacedText(56,143,"x    y",-1,0,-1);
	Draw_spacedText(133,143,"dot",-1,0,-1);
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
			Vector a;
			Vec_mul2(&a, &Pen_dir, 30);
			Draw_line(Pen_x+a.x, Pen_y+a.y, Pen_x, Pen_y, 0xFF0000);
		}
	}

	memcpy(Menu_grp, normalMenuImage, sizeof(normalMenuImage));
	if (Menu_numberMenu) {
		int* counts = Part_updateCounts();
		void Draw_count(int i, int elem) {
			int x = i/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
			int y = i%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
			char buffer[29];
			sprintf(buffer, "  %d", counts[elem]);
			Draw_mrectangle(12+x+4+8, 11+y, Menu_BUTTONWIDTH-8, Menu_BUTTONHEIGHT, 0x404040);
			Draw_spacedText(12+x,11+y,buffer,ELEMENTS[elem].color,0,-1);
		}
		/*		Draw_rectangle(c+4+0+8,3+0,48,137,0x404040);
		Draw_rectangle(c+4+56+8,3+0,48,137,0x404040);
		Draw_rectangle(c+4+112+8,3+0,48,137,0x404040);
		Draw_rectangle(c+4+168+8,3+0,48,137,0x404040);
		Draw_rectangle(c+4+224+8,3+42,47,45,0x404040);
		Draw_rectangle(c+4+224+16,3+98,31,17,0x404040);
		Draw_rectangle(c+4+224+8,3+126,47,11,0x404040);*/
		Draw_mrectangle(8+112+8-1,3+0+4+14*3,1,7,0x404040);//clear part of THUN*/
		int i;
		for (i=0; i<38; i++) {
			
			Draw_count(i, Menu_BUTTONS[i].element);
		}
		Draw_mrectangle(8,8,W,1,0x660000);
	}
	if (Menu_hover>=0) {
		int bx = 4+Menu_hover/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
		int by = 2+Menu_hover%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
		int x,y;
		for (y=0; y<Menu_BUTTONHEIGHT-1; y++)
			for (x=0; x<Menu_BUTTONWIDTH; x++) {
				Color* px = &Menu_grp[by+y][bx+x];
				if (*px == 0x404040)
					*px = 0x400000;
			}
	}
	// ...
	if (Menu_copyMode)
		Draw_spacedText(8+280-1,45,"Copy",0xFF4040,-1,-2);
	else
		Draw_spacedText(8+280+23,45,"Paste",0xFF4040,-1,-3);
	static char* a[] = {"free","line","lock","paint"};
	Draw_spacedText(8+280+(4*(8-2)),73,a[Menu_penMode],-1,0,-2);
	Draw_spacedText(8+280+(4*(8-2)),73,a[Menu_penMode],0xFFFFFF,-1,-2);
	Draw_printf(8+280-1,87,0xFFFFFF,0,-1, "      %d", Menu_penSize);
	Draw_printf(8+280,101,0xFFFFFF,0,-2,"      %s",(char*[]){"x1","x2","x4","x8","16"}[Menu_zoomLevel]);
	Draw_printf(8+280,115,0xFFFFFF,0,-2, "       %d", 1<<Menu_gameSpeed);
	if (!Menu_paused)
		Draw_spacedText(8+280-1,129,"Start",0xFF4040,-1,-3);
	else
		Draw_spacedText(8+280+25,129,"Stop",0xFF4040,-1,-2);
	if (buttonflash>0) {
		buttonflash--;
		if (buttonflash>1)
			Draw_text(8+336,3+14,"SAVE",0xFFFFFF,0xFF0000);
	}
	if (buttonflash<0) {
		buttonflash++;
		if (buttonflash<-1)
			Draw_text(8+336,3+28,"LOAD",0xFFFFFF,0xFF0000);
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
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_leftSelection/Menu_BUTTONROWS),11+Menu_leftSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,3,0xFF0000);
	///rectangle(4+0+56*floor(Menu_middleSelection/10),3+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_rightSelection/Menu_BUTTONROWS),11+Menu_rightSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,3,0x0000FF);
	Draw_printf(64-8,143,-1,0,-1," %d",Pen_x-8);
	Draw_printf(64-8,143,-1,0,-1,"      %d",Pen_y-8);
	//Draw_printf(141,451,-1,0,-1,"   %d",Parts_limits[Menu_dotLimit]-Parts_used);
	Draw_printf(0,143,-1,0,0,"%3dfps",Menu_fps);
	//if(sldebug==1){
	//	k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	//}
	//draw Menu_minimapEnabled
	if (Menu_minimapEnabled) {
		int c=15-8;
		if (Mouse_old.x<116 && Menu_cursorInMenu)
			c=127-8;
		int e=14;
		Draw_mrectangle(c-3,e-3,W/4+6,H/4+6,0x808080);
		save1();
		int a=0;
		axis b,d;
		for (b=0; b<H; b+=4) {
			for (d=0; d<W; d+=4) {
				e = b*W+d;
				if (saveDataArray[e]==0) //try avoid empty?
					e += W+1;
				a = 0;
				if (Menu_bgMode == Bg_DARK) {
					if (ELEMENTS[saveDataArray[e]].state == State_HOT)
						a = saveDataArray[e];
				} else if (Menu_bgMode==Bg_SILUET) {
					if (saveDataArray[e]!=0)
						a = 1;
				} else
					a = saveDataArray[e];
				Color col;
				if (Menu_bgMode==Bg_GRAY)
					col = ELEMENTS[a].grayColor;
				else if (Menu_bgMode==Bg_SILUET)
					col = a==0 ? 0xFFFFFF : 0;
				else
					col = ELEMENTS[a].color;
				Menu_grp[14+b/4][c+d/4] = col;
			}
		}
	}
}
