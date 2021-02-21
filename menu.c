#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elements.h"
#include "draw.h"
#include "part.h"
#include "input.h"
#include "menu.h"
#include "bg.h"
#include "save.h"
#include "entity.h"

//todo: split this file into menu rendering + menu buttons/controls

static Color normalMenuImage[MENU_HEIGHT][WIDTH];

enum PenMode {Pen_FREE, Pen_LINE, Pen_LOCK, Pen_PAINT};
extern int wa;
static void Draw_count(int x, int y, int n, Color c) {
	char buffer[29];
	sprintf(buffer, "  %d", n);
	Draw_spacedText(12+x,H+11+y,buffer,c,0,-1);
}

int Pen_x, Pen_y;
int Pen_oldx, Pen_oldy;
Vector Pen_dir;

bool Menu_numberMenu = false;
bool Menu_copyMode = false;
bool Menu_paused = false;
bool Menu_cursorInMenu = false;
int Menu_penMode = 0;
int Menu_leftSelection = 10;
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

static int wrap(int a, int b) {
	if (a<0)
		return b;
	if (a>b)
		return 0;
	return a;
}

static bool mouseinside(int x, int y, int width, int height) {
	return !(Mouse_old.x<x||Mouse_old.x>=x+width||Mouse_old.y<y||Mouse_old.y>=y+height);
}

void Menu_render(void) {
	if (Mouse_old.y>=H && Mouse_risingClick)
		Menu_cursorInMenu=true;
	else if (Mouse_old.y<H)
		Menu_cursorInMenu=false;
	memcpy(Draw_pxRef(0, H+8), normalMenuImage, sizeof(normalMenuImage));
	int c=12;
	int e=H+11;
	if (Menu_numberMenu) {
		int* counts = Part_updateCounts();
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
	// clicked a menu button
	if (mouseinside(c-8,e-8,391,139) && Menu_cursorInMenu && wa==0) {
		int d = (Mouse_old.x-(c-8))/56;
		int b = (Mouse_old.y-(e-8))/14;
		int selection = clamp(10*d+b,0,69);
		switch (selection) {
		when(Menu_COPYPASTE):
			if (Mouse_rising.left) {
				if (Menu_leftSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_leftSelection = selection;
			}
			if (Mouse_rising.right) {
				if (Menu_rightSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_rightSelection = selection;
			}
		when(Menu_PEN):
			Menu_penMode = wrap(Menu_penMode+Mouse_fallingDirection, 3);
		when(Menu_PENSIZE):
			Menu_penSize = wrap(Menu_penSize+Mouse_fallingDirection, 9);
		when(Menu_SPEED):
			Menu_gameSpeed = wrap(Menu_gameSpeed+Mouse_fallingDirection, 3);
		when(Menu_START):
			Menu_paused=wrap((Menu_paused?1:0)+Mouse_fallingDirection,1)==1;
		when(Menu_UPLOAD):
			if (Mouse_fallingDirection)
				wa=1;
		when(Menu_SAVE):
			if (Mouse_rising.left || Mouse_rising.right) {
				//save1();
				//makesavestring();
				buttonflash=10;
			}
		when(Menu_LOAD):
			if (Mouse_fallingDirection!=0) {
				//loadsavestring();
				//load1();
				buttonflash=-10;
			}
		when(Menu_MINIMAP):
			Menu_minimapEnabled = wrap(Menu_minimapEnabled+Mouse_fallingDirection,1);
		when(Menu_MENU):
			Menu_numberMenu = wrap(Menu_numberMenu+Mouse_fallingDirection, 1);
		when(Menu_SIDE):
			Menu_edgeMode = wrap(Menu_edgeMode+Mouse_fallingDirection, 1);
		when(Menu_GRID):
			Menu_gridSize=wrap(Menu_gridSize+Mouse_fallingDirection, 7);
		when(Menu_BG):
			Menu_bgMode = wrap(Menu_bgMode+Mouse_fallingDirection, 13);
			if (Mouse_fallingDirection)
				Bg_reset();
		when(Menu_DOT):
			Menu_dotLimit = wrap(Menu_dotLimit+Mouse_fallingDirection, 2);
		when(Menu_RESET):
			if (Mouse_fallingDirection)
				Part_reset(0);
		otherwise:
			if (selection < 38 || selection >= 40) {
				if (Mouse_rising.left)
					Menu_leftSelection = selection;
				else if (Mouse_rising.right)
					Menu_rightSelection = selection;
			}
		}
	}
	if (Menu_numberMenu)
		Draw_line(8,H+8,W+8,H+8,0x660000);
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
	Draw_printf(c+4+336,e+84,0x800000,0,0,"     %d",Menu_gridSize); //this is too dark
	str = (char*[]){"none","air","line","blur","shade","aura","light","toon","mesh","gray","track","dark","TG","siluet"}[Menu_bgMode];
	Draw_spacedText(c+4+336+6*3,e+98,str,-1,0,-2);
	Draw_spacedText(c+4+336+6*3,e+98,str,0xFFFFFF,-1,-2);
	Draw_text(c+4+336+8*4,e+112,(char*[]){"S","M","L"}[Menu_dotLimit],0xFFFFFF,0);
	Draw_rectangle(c+0+56*(Menu_leftSelection/10),e+Menu_leftSelection%10*14,3,3,0xFF0000);
	///rectangle(c+0+56*floor(Menu_middleSelection/10),e+4+Menu_middleSelection%10*14,3,3,0x00FF00);
	Draw_rectangle(c+0+56*(Menu_rightSelection/10),e+8+Menu_rightSelection%10*14,3,3,0x0000FF);
	Draw_printf(64,H+151,-1,0,-1," %d",Pen_x-8);
	Draw_printf(64,H+151,-1,0,-1,"      %d",Pen_y-8);
	//Draw_printf(141,451,-1,0,-1,"   %d",Parts_limits[Menu_dotLimit]-Parts_used);
	Draw_printf(16,H+151,-1,0,0,"%dfps",Menu_fps);
	//if(sldebug==1){
	//	k.drawtext(64,451,Sc+"sl",0xFFFFFF,0);
	//}
	//draw Menu_minimapEnabled
	if (Menu_minimapEnabled) {
		c=15;
		if (Mouse_old.x<116 && Menu_cursorInMenu)
			c=127;
		e=314;
		Draw_rectangle(c-3,e-3,W/4+6,H/4+6,0x808080);
		save1();
		int a=0;
		int b,d;
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
				*Draw_pxRef(c+d/4, H+14+b/4) = col;
			}
		}
	}
	//*/
	//setsize(normalmenuimage,WIDTH,HEIGHT-308);
}

void Draw_init(void) {
	Draw_rectangle(0,0,WIDTH,HEIGHT,0x404040);
	Draw_spacedText(211,H+151,"DAN-BALL.jp (C) 2007 ha55ii",-1,0,-1);
	Draw_text(16,H+11,"POWDER",0xF2BD6B,0);
	Draw_text(16,H+25,"WATER",0x4040FF,0);
	Draw_text(16,H+39,"FIRE",0xFF4040,0);
	Draw_text(16,H+53,"SEED",0x90C040,0);
	Draw_text(16,H+67,"WOOD",0x805020,0);
	// -2 spaced text needs to be drawn this special way
	// maybe fix this
	Draw_spacedText(16,H+81,"G-POWDER",-1,0,-2);
	Draw_spacedText(16,H+81,"G-POWDER",0xB08050,-1,-2);
	Draw_text(16,H+95,"FAN",0x8080FF,0);
	Draw_text(16,H+109,"ICE",0xD0D0FF,0);
	Draw_text(16,H+123,"SNOW",0xFFFFFF,0);
	Draw_text(16,H+137,"STEAM",0xE0E0E0,0);
		
	Draw_text(72,H+11,"S-BALL",0xFF40A0,0);
	Draw_text(72,H+25,"CLONE",0x907010,0);
	Draw_spacedText(72,H+39,"F-WORKS",0xFF9966,0,-1);
	Draw_text(72,H+53,"OIL",0x803020,0);
	Draw_text(72,H+67,"C-4",0xFFFFCC,0);
	Draw_text(72,H+81,"STONE",0x808080,0);
	Draw_text(72,H+95,"MAGMA",0xFF6633,0);
	Draw_text(72,H+109,"VIRUS",0x800080,0);
	Draw_text(72,H+123,"NITRO",0x447700,0);
	Draw_text(72,H+137,"ANT",0xC080C0,0);
		
	Draw_text(128,H+11,"TORCH",0xFFA020,0);
	Draw_text(128,H+25,"GAS",0xCC9999,0);
	Draw_text(128,H+39,"SOAPY",0xE0E0E0,0);
	Draw_spacedText(128,H+53,"THUNDER",0xFFFF20,0,-1);
	Draw_text(128,H+67,"METAL",0x404040,0);
	Draw_text(128,H+81,"BOMB",0x666600,0);
	Draw_text(128,H+95,"LASER",0xCC0000,0);
	Draw_text(128,H+109,"ACID",0xCCFF00,0);
	Draw_text(128,H+123,"VINE",0x00BB00,0);
	Draw_text(128,H+137,"SALT",0xFFFFFF,0);
		
	Draw_spacedText(184,H+11,"S-WATER",0x3399FF,0,-1);
	Draw_text(184,H+25,"GLASS",0x404040,0);
	Draw_text(184,H+39,"BIRD",0x807050,0);
	Draw_spacedText(184,H+53,"MERCURY",0xAAAAAA,0,-1);
	Draw_text(184,H+67,"SPARK",0xFFCC33,0);
	Draw_text(184,H+81,"FUSE",0x443322,0);
	Draw_text(184,H+95,"CLOUD",0xCCCCCC,0);
	Draw_text(184,H+109,"PUMP",0x003333,0);
		
	Draw_text(240,H+11,"WIND",0x8080FF,0);
	Draw_text(240,H+25,"AIR",0x8080FF,0);
	Draw_text(240,H+39,"DRAG",0xFFFFFF,0);
	Draw_text(240,H+53,"B",0xFFE0E0,0);
	Draw_text(240,H+53," U",0xFFFFE0,0);
	Draw_text(240,H+53,"  B",0xE0FFE0,0);
	Draw_text(240,H+53,"   B",0xE0FFFF,0);
	Draw_text(240,H+53,"    L",0xE0E0FF,0);
	Draw_text(240,H+53,"     E",0xFFE0FF,0);
	Draw_text(240,H+67,"WHEEL",0xB0A090,0);
	Draw_text(240,H+81,"PLAYER",0xF2BD6B,0);
	Draw_spacedText(240,H+95,"FIGHTER",0xF2BD6B,0,-1);
	Draw_text(240,H+109,"BOX",0xF2BD6B,0);
	Draw_text(240,H+123,"BALL",0xF2BD6B,0);
	Draw_text(240,H+137,"CREATE",0x907010,0);
	Draw_text(296,H+11,"BLOCK",0x808080,0);
	Draw_text(296,H+25,"ERASE",0x808080,0); //rename?
	Draw_text(296,H+39,"CLEAR",0xFFFFFF,0);
	Draw_spacedText(295,H+53,"Copy",-1,0,-2);
	Draw_spacedText(295,H+53,"Copy",0xFFFFFF,-1,-2);
	Draw_spacedText(319,H+53,"Paste",-1,0,-3);
	Draw_spacedText(319,H+53,"Paste",0xFFFFFF,-1,-3);
	Draw_text(296,H+67,"TEXT",0xFFFFFF,0);
	Draw_spacedText(296,H+81,"PEN",-1,0,-1);
	Draw_spacedText(296,H+81,"PEN",0xFFFFFF,-1,-1);
	Draw_spacedText(296,H+95,"PEN-S ",0xFFFFFF,0,-1);
	Draw_spacedText(296,H+109,"SCALE",0xFFFFFF,0,-1);
	Draw_spacedText(296,H+123,"SPEEDx",0xFFFFFF,0,-1);
	Draw_spacedText(295,H+137,"Start",-1,0,-3);
	Draw_spacedText(295,H+137,"Start",0xFFFFFF,-1,-3);
	Draw_spacedText(321,H+137,"Stop",-1,0,-2);
	Draw_spacedText(321,H+137,"Stop",0xFFFFFF,-1,-2);
	Draw_text(352,H+11,"UPLOAD",0xFFA0A0,0);
	Draw_text(352,H+25,"SAVE",0xFFA0A0,0);
	Draw_text(352,H+39,"LOAD",0xFFA0A0,0);
	Draw_spacedText(352,H+53,"MiniMap",0xFFA0A0,0,-1);
	Draw_spacedText(352,H+67,"MENU-",-1,0,-2);
	Draw_spacedText(352,H+67,"MENU-",0xFFFFFF,-1,-2);
	Draw_spacedText(352,H+81,"SIDE-",-1,0,-3);
	Draw_spacedText(352,H+81,"SIDE-",0xFFFFFF,-1,-3);
	Draw_text(352,H+95,"GRID",0x800000,0);
	Draw_spacedText(352,H+109,"BG-",-1,0,-2);
	Draw_spacedText(352,H+109,"BG-",0xFFFFFF,-1,-2);
	Draw_text(352,H+123,"DOT ",0xFFFFFF,0);
	Draw_text(352,H+137,"RESET",0xFFFFFF,0);
	Draw_spacedText(64,H+151,"x    y",-1,0,-1);
	Draw_spacedText(141,H+151,"dot",-1,0,-1);
	memcpy(normalMenuImage, Draw_pxRef(0, H+8), sizeof(normalMenuImage));
}

void Menu_update(void) {
	if (Menu_cursorInMenu || wa)
		return;
	int i;
	for (i=0;i<=1;i++) {
		int selection = i ? Menu_rightSelection : Menu_leftSelection;
		bool rising = i ? Mouse_rising.right : Mouse_rising.left;
		bool falling = i ? Mouse_falling.right : Mouse_falling.left;
		bool old = i ? Mouse_old.right : Mouse_old.left;
		if (selection < 38) {
			if (Menu_penMode == Pen_LINE)
				old = falling;
			if (old) {
				int vx = Pen_x - Pen_oldx;
				int vy = Pen_y - Pen_oldy;
				if (Menu_penSize>1 || !Menu_paused || Menu_zoomLevel>1 || vx || vy || Menu_penMode == Pen_PAINT) {
					int w = abs(vx);
					if (w<abs(vy)) w=abs(vy);
					if (w<1) w=1;
					vx = (vx<<8)/w;
					vy = (vy<<8)/w;
					int x2 = (Pen_oldx<<8)+127;
					int y2 = (Pen_oldy<<8)+127;
					int c;
					// for each point along line
					for (c=0; c<=w; c++,x2+=vx,y2+=vy) {
						int xStart = (x2>>8)-Menu_penSize;
						int yStart = (y2>>8)-Menu_penSize;
						int xEnd=xStart+2*Menu_penSize;
						int yEnd=yStart+2*Menu_penSize;
						if (xStart<8) xStart=8;
						if (yStart<8) yStart=8;
						if (xEnd>W+8-1) xEnd=W+8-1;
						if (yEnd>H+8-1) yEnd=H+8-1;
						int f,g;
						for (g=yStart; g<=yEnd; g++) {
							for (f=xStart; f<=xEnd; f++) {
								// circle
								if (Menu_penSize*Menu_penSize+1<(f-(x2>>8))*(f-(x2>>8))+(g-(y2>>8))*(g-(y2>>8))) continue;
								Part* p = Part_at[g][f];
								if (Menu_penMode == Pen_PAINT) {
									int e = Menu_BUTTONS[selection].element ?: Elem_POWDER;
									int meta = 0;
									if (e!=Elem_FAN) {
										if (e==Elem_FIREWORKS) {
											meta = Menu_BUTTONS[Menu_leftSelection].firework ?: Menu_BUTTONS[Menu_rightSelection].firework ?: Elem_POWDER;
										} else if (e==Elem_LASER) {
											meta = 8*Vec_angle(&Pen_dir)/TAU+0.5;
											if (meta>=8)
												meta = 0;
											meta = meta+1;
										}
										if (p>=Part_0 && p->type!=e)
											;//paint(f, g, p->type, e, meta);
									}
								} else if (p == Part_EMPTY) {
									int pa = Menu_BUTTONS[selection].element;
									if((i==0 && Mouse_old.right && Menu_rightSelection<38 || i==1 && Mouse_old.left && Menu_leftSelection<38) && Random_(100)<50) {
										pa = Menu_BUTTONS[i==0?Menu_rightSelection:Menu_leftSelection].element;
									}
									//printf("create %d %d %d\n", f, g, pa);
									Part* e = Part_create(f, g, pa);
									if (e>=Part_0) {
										if (pa==Elem_FAN) {
											Vec_mul2(&e->vel, &Pen_dir, 0.1);
										} else if (pa==Elem_FIREWORKS) {
											e->meta = Menu_BUTTONS[Menu_leftSelection].firework ?: Menu_BUTTONS[Menu_rightSelection].firework ?: Elem_POWDER;
										} else if (pa==Elem_LASER) {
											int meta = 8*Vec_angle(&Pen_dir)/TAU+0.5;
											if (meta>=8)
												meta = 0;
											e->meta = meta+1;
										}
									}
								}
							}
						}
					}
				}
			}
		} else {
			switch (selection) {
			when(Menu_WIND):;
				Vector b;
				Vec_mul2(&b, &Pen_dir, 10);
				Block* e = &Part_blocks[Pen_y>>2][Pen_x>>2];
				if (old && e->block == 0) {
					Vec_add(&e->vel, &b);
					if (Vec_fastDist(&e->vel)>10 && Menu_paused) {
						Vec_fastNormalize(&e->vel);
						Vec_mul(&e->vel, 10);
					}
				}
			when(Menu_AIR):;
				void addPressure(int x, int y, double amount) {
					Block* cell = &Part_blocks[y>>2][x>>2];
					if (!cell->block) {
						cell->pres += amount;
						pd -= amount;
					}
				}
				if (old) {
					int v=(Menu_penSize+1)*(Menu_penSize+1)*0.25;
					v = i ? -v : v;
					addPressure(0,0,v);
					addPressure(-1,0,v);
					addPressure(0,-1,v);
					addPressure(-1,-1,v);
				}
			when(Menu_PLAYER): case Menu_FIGHTER: case Menu_BOX: case Menu_CREATE:
				if (!rising) break;
				int f = Pen_x>>2<<2;
				int g = Pen_y>>2<<2;
				Block* cell = &Part_blocks[Pen_y>>2][Pen_x>>2];
				if (!cell->block) {
					switch (selection) {
					when(Menu_FIGHTER):
						Entity_create(f, g, 0, 0);
					when(Menu_BOX):
						Entity_create(f, g, Elem_BOX, Menu_penSize);
					when(Menu_PLAYER):;
						int b = Menu_BUTTONS[Menu_leftSelection].player ?: Menu_BUTTONS[Menu_rightSelection].player;
						Entity_create(f, g, Elem_PLAYER, b);
					when(Menu_CREATE):
						Entity_create(f, g, Elem_BOX, 10);
					}
				}
				// todo: we still need to do ball, wheel,etc.
			when(Menu_BLOCK): case Menu_ERASE: case Menu_CLEAR:
				if (Menu_penMode==Pen_LINE)
					old = (i==0 ? Mouse_falling.left : Mouse_falling.right);
				if (old) {
					// god, more line drawing shit
					int n = Pen_x/4 - Pen_oldx/4;
					int r = Pen_y/4 - Pen_oldy/4;
					int w = abs(n);
					if (abs(r)>w) w=abs(r);
					if (1>w) w=1;
					n = (n<<8)/w;
					r = (r<<8)/w;
					int y = (Pen_oldx/4<<8)-127;
					int z = (Pen_oldy/4<<8)-127;
					int b;
					for (b=0; b<=w; b++, y+=n, z+=r) {
						int c = (y>>8) - Menu_penSize/2;
						int v = (z>>8) - Menu_penSize/2;
						int Y = c+(float)Menu_penSize/2+0.5;
						int Ka = v+(float)Menu_penSize/2+0.5;
						for (g=v; g<=v+Menu_penSize; g++) {
							for (f=c; f<=c+Menu_penSize; f++) {
								if ((f-Y)*(f-Y)+(g-Ka)*(g-Ka)<=Menu_penSize*Menu_penSize/4) {
									Block* cell = &Part_blocks[(int)clamp(g,2,(H+16)/4-3)][(int)clamp(f,2,(W+16)/4-3)];
									switch(selection) {
									when(Menu_BLOCK):
										cell->block = 1;
										cell->vel = (Vector){0,0};
										pd += e->pres;
										e->pres = 0;
									when(Menu_ERASE):
										cell->block = -2;
									when(Menu_CLEAR):
										if (e->block == 0) {
											e->block = -2;
											e->vel = (Vector){0,0};
											pd+=e->pres;
											e->pres=0;
										}
									}
								}
							}
						}
						/// aaaaa
						if (selection==Menu_CLEAR && Menu_penSize==0) {
							int n=Pen_x-Pen_oldx;
							int r=Pen_y-Pen_oldy;
							int w=abs(n);
							if (abs(r)>w) w = abs(r);
							if (1>w) w = 1;
							n = (n<<8)/w;
							r = (r<<8)/w;
							int y,z,b;
							for (y=(Pen_oldx<<8)+127,z=(Pen_oldy<<8)+127,b=0;b<=w;b++,y+=n,z+=r) {
								Part* e;
								for (e=Part_0; e<Part_next; e++)
									if (y>>8==(int)e->pos.x && z>>8==(int)e->pos.y)
										Part_remove(e--);
							}
						}
					}
				}
			}
		}
	}
}
