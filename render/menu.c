#include "../common.h"
#include "../menu.h"
#include "../elements.h"
#include "../sim.h"
#include "bg.h"
#include "draw.h"
#include "../object.h"
#include "../save.h"
#include "../input.h"

static Color normalMenuImage[MENU_HEIGHT][MENU_WIDTH];

enum ButtonX {
	col5 = 232,
	col6 = 288,
	col7 = 344,
};

enum RowY {
	row1 = 3,
	row2 = 17,
	row3 = 31,
	row4 = 45,
	row5 = 59,
	row6 = 73,
	row7 = 87,
	row8 = 101,
	row9 = 115,
	row10 = 129,
};

static const axis rowLast = 143;

static void drawLabel(int pos, Elem elem) {
	if (!elem)
		return;
	axis y = 3+(pos%10)*14;
	axis x = 8+(pos/10)*56;
	const ElementDef* d = &ELEMENTS[elem];
	int spacing = 0;
	if (d->name) {
		int l = strlen(d->name);
		if (l>=7)
			spacing = -1;
		if (l>=8)
			spacing = -2;
		Draw_spacedText(x, y, d->name, d->menuColor, RGB(0,0,0), spacing);
	}
}

#define Col_WIND RGB(0x80,0x80,0xFF)
#define Col_WHITE RGB(0xFF,0xFF,0xFF)
#define Col_TAN RGB(0xF2,0xBD,0x6B)
#define Col_CREATE RGB(0x90,0x70,0x10)
#define Col_BLACK RGB(0,0,0)
#define Col_NONE (Color){.c=0}
#define Col_RED RGB(255,0,0)

AUTORUN {
	Draw_mrectangle(0,0,MENU_WIDTH,MENU_HEIGHT,RGB(64,64,64));
	Draw_spacedText(203,rowLast,"DAN-BALL.jp (C) 2007 ha55ii",Col_NONE,Col_BLACK,-1);
	
	for (int i=0; i<39; i++) {
		Elem e = Menu_BUTTONS[i].element;
		e[ELEMENTS].menuColor = e[ELEMENTS].color;
		drawLabel(i, e);
	}
	
	Draw_text(col5,row1,"WIND",Col_WIND,Col_BLACK);
	Draw_text(col5,row2,"AIR",Col_WIND,Col_BLACK);
	Draw_text(col5,row3,"DRAG",Col_WHITE,Col_BLACK);
	Draw_text(col5,row4,"B",RGB(0xFF,0xE0,0xE0),Col_BLACK);
	Draw_text(col5,row4," U",RGB(0xFF,0xFF,0xE0),Col_BLACK);
	Draw_text(col5,row4,"  B",RGB(0xE0,0xFF,0xE0),Col_BLACK);
	Draw_text(col5,row4,"   B",RGB(0xE0,0xFF,0xFF),Col_BLACK);
	Draw_text(col5,row4,"    L",RGB(0xE0,0xE0,0xFF),Col_BLACK);
	Draw_text(col5,row4,"     E",RGB(0xFF,0xE0,0xFF),Col_BLACK);
	Draw_text(col5,row5,"WHEEL",RGB(0xB0,0xA0,0x90),Col_BLACK);
	Draw_text(col5,row6,"PLAYER",Col_TAN,Col_BLACK);
	Draw_spacedText(col5,row7,"FIGHTER",Col_TAN,Col_BLACK,-1);
	Draw_text(col5,row8,"BOX",Col_TAN,Col_BLACK);
	Draw_text(col5,row9,"BALL",Col_TAN,Col_BLACK);
	Draw_text(col5,row10,"CREATE",Col_CREATE,Col_BLACK);
	
	Draw_text(col6,row1,"BLOCK",RGB(0x80,0x80,0x80),Col_BLACK);
	Draw_text(col6,row2,"ERASE",RGB(0x80,0x80,0x80),Col_BLACK);
	Draw_text(col6,row3,"CLEAR",Col_WHITE,Col_BLACK);
	Draw_spacedText(col6-1,row4,"Copy",Col_WHITE,Col_BLACK,-2);
	Draw_spacedText(col6+23,row4,"Paste",Col_WHITE,Col_BLACK,-3);
	Draw_text(col6,row5,"TEXT",Col_WHITE,Col_BLACK);
	Draw_spacedText(col6,row6,"PEN",Col_WHITE,Col_BLACK,-1);
	Draw_spacedText(col6,row7,"PEN-S ",Col_WHITE,Col_BLACK,-1);
	Draw_spacedText(col6,row8,"SCALE",Col_WHITE,Col_BLACK,-1);
	Draw_spacedText(col6,row9,"SPEEDx",Col_WHITE,Col_BLACK,-1);
	Draw_spacedText(col6-1,row10,"Start",Col_WHITE,Col_BLACK,-3);
	Draw_spacedText(col6+25,row10,"Stop",Col_WHITE,Col_BLACK,-2);
	
	Draw_spacedText(col7,row1,"FILE -",RGB(0xFF,0xA0,0xA0),Col_BLACK,0);
	Draw_text(col7,row2,"SAVE",RGB(0xFF,0xA0,0xA0),Col_BLACK);
	Draw_text(col7,row3,"LOAD",RGB(0xFF,0xA0,0xA0),Col_BLACK);
	Draw_spacedText(col7,row4,"MiniMap",RGB(0xFF,0xA0,0xA0),Col_BLACK,-1);
	Draw_spacedText(col7,row5,"MENU-",Col_WHITE,Col_BLACK,-2);
	Draw_spacedText(col7,row6,"SIDE-",Col_WHITE,Col_BLACK,-3);
	Draw_text(col7,row7,"GRID",RGB(0x80,0x00,0x00),Col_BLACK);
	Draw_spacedText(col7,row8,"BG-",Col_WHITE,Col_BLACK,-2);
	Draw_text(col7,row9,"DOT ",Col_WHITE,Col_BLACK);
	Draw_text(col7,row10,"RESET",Col_WHITE,Col_BLACK);
	
	Draw_spacedText(0,rowLast,"   fps",Col_NONE,Col_BLACK,0);
	Draw_spacedText(56,rowLast,"x    y",Col_NONE,Col_BLACK,-1);
	Draw_spacedText(133,rowLast,"dot",Col_NONE,Col_BLACK,-1);
	memcpy(normalMenuImage, Menu_grp, sizeof(normalMenuImage));
}

static void drawCursor() {
	if (Menu_leftSelection==Menu_BLOCK||Menu_leftSelection==Menu_ERASE/*||Menu_leftSelection==Menu_CLEAR||Menu_rightSelection==Menu_BLOCK||Menu_rightSelection==Menu_ERASE||Menu_rightSelection==Menu_CLEAR*/) {
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
		axis cx = ((Pen_oldx>>2)-1-(int)(Menu_penSize/2) + (axis[]){0,1,1,1,2,2,2,3,3,3,4}[Menu_penSize])*4;
		axis cy = ((Pen_oldy>>2)-1-(int)(Menu_penSize/2) + (axis[]){0,1,1,1,1,1,1,1,1,1,1}[Menu_penSize])*4;
		for (const char* c=paths[Menu_penSize]; *c; c++) {
			axis x = clamp(cx, 0, WIDTH-1);
			axis y = clamp(cy, 0, H+8);
			grp[y][x].r ^= 255;
			grp[y][x].g ^= 255;
			grp[y][x].b ^= 255;
			switch (*c) {
			when('1'):; cx++;
			when('2'):; cy++;
			when('3'):; cx--;
			when('4'):; cy--;
			}
		}
	}
	/*if (Menu_leftSelection==Menu_FAN||Menu_rightSelection==Menu_FAN||Menu_leftSelection==Menu_WIND||Menu_rightSelection==Menu_WIND||Menu_leftSelection==Menu_LASER||Menu_rightSelection==Menu_LASER){ //fan,wind,laser (buttons, not element ids)
		Point a = Vec_mul2(Pen_dir, 30);
		Draw_line(Pen_x, Pen_y, Pen_x+a.x, Pen_y+a.y, 0xFF0000); // I swapped order here
		}*/
		
	axis xStart = atLeast((Pen_oldx)-Menu_penSize, 8);
	axis yStart = atLeast((Pen_oldy)-Menu_penSize, 8);
	axis xEnd = atMost(xStart+2*Menu_penSize, W+8-1);
	axis yEnd = atMost(yStart+2*Menu_penSize, H+8-1);
	for (axis g=yStart; g<=yEnd; g++) {
		for (axis f=xStart; f<=xEnd; f++) {
			// circle
			axis dx = f-Pen_oldx;
			axis dy = g-Pen_oldy;
			if (Menu_penSize*Menu_penSize+1 < dx*dx+dy*dy) continue;
			/*Color c = grp[g][f];
			int r = atMost(RED(c) + 30, 255);
			int gg = atMost(GREEN(c) + 30, 255);
			int b = atMost(BLUE(c) + 30, 255);*/
			grp[g][f].r ^= 255;
			grp[g][f].g ^= 255;
			grp[g][f].b ^= 255;
		}
	}
	
	//Draw_rectangle(Pen_x, Pen_y, 1, 1, 0xFF0000);
}

static void str(char* buf, int n) {
	int x = n;
	int i = 0;
	for (; x!=0; i++) {
		x /= 10;
	}
	buf[i--] = 0;
	for (; i>=0; i--) {
		buf[i] = x % 10;
		x /= 10;
	}
}

static void Draw_count(int i, int count, char name, Color color) {
	axis x = i/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
	axis y = i%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
	char buffer[29];
	buffer[0] = name;
	buffer[1] = 0;
	Draw_mrectangle(4+x+4, 11-8+y, Menu_BUTTONWIDTH, Menu_BUTTONHEIGHT, RGB(0x40,0x40,0x40));
	Draw_text(4+4+x, 11-8+y, buffer,color, Col_BLACK);
	buffer[0] = ' ';
	buffer[1] = ' ';
	
	//sprintf(buffer, "  %d", count);
	Draw_spacedText(4+4+x, 11-8+y, buffer, color, Col_BLACK, -1);
}

void Menu_render(void) {
	if (!Menu_cursorInMenu /*&& !wa*/) {
		drawCursor();
	}

	memcpy(Menu_grp, normalMenuImage, sizeof(normalMenuImage));
	if (Menu_numberMenu) {
		int* counts = Dot_updateCounts();
		for (int i=0; i<39; i++) {
			Elem elem = Menu_BUTTONS[i].element;
			Draw_count(i, counts[elem], ELEMENTS[elem].name[0], ELEMENTS[elem].menuColor);
		}
		Draw_count(43, Bubble_next-Bubble_bubbles, 'B', RGB(0xFF,0xE0,0xE0)); //is this correct for first char?
		Draw_count(44, Wheel_next-Wheel_wheels, 'W', RGB(0xB0,0xA0,0x90));
		int ecounts[5] = {0};
		Object_FOR (en) {
			if (en->type>=Object_CREATE)
				ecounts[4]++;
			else if (en->type>=Object_PLAYER)
				ecounts[2]++;
			else if (en->type>=Object_BOX)
				ecounts[1]++;
			else if (en->type>=Object_FIGHTER)
				ecounts[0]++;
			
		}
		Ball_FOR (b) {
			if (b->used)
				ecounts[3]++;
		}
		Draw_count(45, ecounts[2], 'P', RGB(0xF2,0xBD,0x6B));
		Draw_count(46, ecounts[0], 'F', RGB(0xF2,0xBD,0x6B));
		Draw_count(47, ecounts[1], 'B', RGB(0xF2,0xBD,0x6B));
		Draw_count(48, ecounts[3], 'B', RGB(0xF2,0xBD,0x6B));
		Draw_count(49, ecounts[4], 'C', RGB(0x90,0x70,0x10));
	}
	if (Menu_hover>=0) {
		Draw_mrectangle(0,0,W,1,RGB(0x66,0x00,0x00));
		axis bx = 4+Menu_hover/Menu_BUTTONROWS*Menu_BUTTONWIDTH;
		axis by = 2+Menu_hover%Menu_BUTTONROWS*Menu_BUTTONHEIGHT;
		for (axis y=0; y<Menu_BUTTONHEIGHT-1; y++)
			for (axis x=0; x<Menu_BUTTONWIDTH; x++) {
				Color* px = &Menu_grp[by+y][bx+x];
				if (px->c == RGB(0x40,0x40,0x40).c)
					*px = RGB(0x40,0x00,0x00);
			}
	}
	// ...
	if (Menu_copyMode)
		Draw_spacedText(col6-1,row4,"Copy",RGB(0xFF,0x40,0x40),Col_NONE,-2);
	else
		Draw_spacedText(col6+23,row4,"Paste",RGB(0xFF,0x40,0x40),Col_NONE,-3);
	static char* a[] = {"free","line","lock","paint"};
	Draw_spacedText(8+280+(4*(8-2)),row6,a[Menu_penMode],Col_WHITE,Col_BLACK,-2);
	Draw_printf(8+280-1,row7,Col_WHITE,Col_BLACK,-1, "      %d", Menu_penSize);
	Draw_printf(8+280,row8,Col_WHITE,Col_BLACK,-2,"      %s",(char*[]){"x1","x2","x4","x8","16","32","64","aa","ff","help","please","stop","AAAAA"}[Menu_zoomLevel]);
	Draw_printf(8+280,row9,Col_WHITE,Col_BLACK,-2, "       %d", 1<<Menu_gameSpeed);
	if (!Menu_paused)
		Draw_spacedText(col6-1,row10,"Start",RGB(0xFF,0x40,0x40),Col_NONE,-3);
	else
		Draw_spacedText(col6+25,row10,"Stop",RGB(0xFF,0x40,0x40),Col_NONE,-2);
	if (buttonflash>0) {
		buttonflash--;
		if (buttonflash>1)
			Draw_text(col7,row2,"SAVE",Col_WHITE,Col_RED);
	}
	if (buttonflash<0) {
		buttonflash++;
		if (buttonflash<-1)
			Draw_text(col7,row3,"LOAD",Col_WHITE,Col_RED);
	}
	if (Menu_minimapEnabled)
		Draw_spacedText(8+336,row4,"MiniMap",Col_WHITE,Col_RED,-1);
	char* str = Menu_numberMenu ? "     num" : "     str";
	Draw_spacedText(8+336,row5,str,Col_WHITE,Col_BLACK,-2);
	str = Menu_edgeMode ? "OFF" : "LOOP";
	Draw_spacedText(8+336+25,row6,str,Col_WHITE,Col_BLACK,-2);
	Draw_printf(8+336,row7,RGB(0x80,0,0),Col_BLACK,0,"     %d",Menu_gridSize); //this is too dark
	str = (char*[]){"none","air","line","blur","shade","aura","light","toon","mesh","gray","track","dark","TG","siluet"}[Menu_bgMode];
	Draw_spacedText(8+336+6*3,row8,str,Col_WHITE,Col_BLACK,-2);
	Draw_text(8+336+8*4,row9,(char*[]){"S","M","L","X"}[Menu_dotLimit],Col_WHITE,Col_BLACK);
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_leftSelection/Menu_BUTTONROWS),11-8+Menu_leftSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,4,Col_RED);
	///rectangle(4+0+56*floor(Menu_middleSelection/10),3+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	Draw_mrectangle(4+Menu_BUTTONWIDTH*(Menu_rightSelection/Menu_BUTTONROWS),11+Menu_rightSelection%Menu_BUTTONROWS*Menu_BUTTONHEIGHT,3,4,RGB(0,0,255));
	Draw_printf(56,rowLast,RGB(128,128,128),Col_BLACK,-1," %d",Pen_x-8);
	Draw_printf(56,rowLast,RGB(128,128,128),Col_BLACK,-1,"      %d",Pen_y-8);
	Draw_printf(141-8,rowLast,RGB(128,128,128),Col_BLACK,-1,"   %d", Dot_limit - (Dot_next-Dot_0));
	if (Menu_fps<=999)
		Draw_printf(0,rowLast,RGB(128,128,128),Col_BLACK,0,"%3d",Menu_fps);
	else {
		//int d = log10f(Menu_fps); @@@
		//Draw_printf(0,rowLast,0x808080,0,0,"%de%d", (int)roundf(Menu_fps/powf(10,d)), d);
	}
	//if(sldebug==1){
	//	k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	//}
	//draw Menu_minimapEnabled
	if (Menu_minimapEnabled) {
		axis sx=15-8;
		if (mouse.oldPos.x<116 && Menu_cursorInMenu)
			sx=127-8;
		axis sy=14;
		Draw_mrectangle(sx-3,sy-3,W/4+6,H/4+6,RGB(128,128,128));
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
					col = a==0 ? Col_WHITE : Col_BLACK;
				else
					col = ELEMENTS[a].color;
				Menu_grp[sy+y/4][sx+d/4] = col;
			}
		}
	}
}
