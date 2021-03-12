#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "common.h"
#include "input.h"
#include "dot.h"
#include "menu.h"
//#include "bg.h"
#include "platform.h"
#include "sim.h"

//todo: split this file into menu rendering + menu buttons/controls

enum PenMode {Pen_FREE, Pen_LINE, Pen_LOCK, Pen_PAINT};

axis Pen_x=0, Pen_y=0;
axis Pen_oldx=0, Pen_oldy=0;
Point Menu_pen = {0,0};
Point Menu_penOld = {0,0};
Point Pen_dir = {0,0};

static void clampZoom(void) {
	Menu_zoomX = clamp(Menu_zoomX, 0, W-ceil((real)W/(1<<Menu_zoomLevel)));
	Menu_zoomY = clamp(Menu_zoomY, 0, H-ceil((real)H/(1<<Menu_zoomLevel)));
}

void Menu_update(void) {
	static long last;
	long ms = Platform_nanosec();
	if (ms>last) {
		real fps = (1000000000.0)/(ms-last);
		fps *= 1<<Menu_gameSpeed;
		last = ms;
		Menu_fps = (Menu_fps*9+fps)/10;
	} else {
		Menu_fps = 99999999;
	}
	
	if (Menu_cursorInMenu)
		return;
	Menu_penOld = Menu_pen;
	Menu_pen = mouse.pos;

	Pen_oldx = Pen_x;
	Pen_oldy = Pen_y;
	Pen_x = mouse.pos.x;
	Pen_y = mouse.pos.y;
	if (Menu_zoomLevel>0) {
		Pen_x = Menu_zoomX+(Pen_x>>Menu_zoomLevel);
		Pen_y = Menu_zoomY+(Pen_y>>Menu_zoomLevel);
		Menu_pen.x = Menu_zoomX+((int)Menu_pen.x>>Menu_zoomLevel);
		Menu_pen.y = Menu_zoomY+((int)Menu_pen.y>>Menu_zoomLevel);
	}
	Pen_x = clamp(Pen_x+8,8,WIDTH-8-1);
	Pen_y = clamp(Pen_y+8,8,HEIGHT-8-1);
	Menu_pen.x = clamp(Menu_pen.x+8,8,WIDTH-8-1);
	Menu_pen.y = clamp(Menu_pen.y+8,8,HEIGHT-8-1);
	// todo: line mode etc.
	Point c = {Pen_x,Pen_y};
	Pen_dir.x = Pen_oldx-5*Pen_dir.x;
	Pen_dir.y = Pen_oldy-5*Pen_dir.y;
	real q = 5;
	Point ee = Vec_sub2(c, Pen_dir);
	q -= Vec_fastNormalize(&ee);
	real d = q*0.5;
	real a = q*0.5;
	c.x += ee.x*a;
	c.y += ee.y*a;
	Pen_dir.x -= ee.x*d;
	Pen_dir.y -= ee.y*d;
	Pen_dir = Vec_sub2(c, Pen_dir);
	Vec_fastNormalize(&Pen_dir);
	if (Menu_zoomLevel!=0 && mouse.middle.held) {
		Menu_zoomX -= (mouse.pos.x-mouse.oldPos.x)/(1<<Menu_zoomLevel);
		Menu_zoomY -= (mouse.pos.y-mouse.oldPos.y)/(1<<Menu_zoomLevel);
		clampZoom();
	}
	for (int i=0;i<=1;i++) {
		ButtonState* btn = i ? &mouse.right : &mouse.left;
		ButtonState* otherBtn = !i ? &mouse.right : &mouse.left;
		int selection = i ? Menu_rightSelection : Menu_leftSelection;
		int otherSel = i ? Menu_leftSelection : Menu_rightSelection;
		bool gotPress = btn->gotPress;
		bool gotRelease = btn->gotRelease;
		bool old = btn->wasHeld;
		if (selection<Menu_ELEMENTS || selection==Menu_CLEAR) {
			if (Menu_penMode == Pen_LINE)
				old = gotRelease;
			if (old) {
				axis vx = Pen_x - Pen_oldx;
				axis vy = Pen_y - Pen_oldy;
				if (Menu_penSize>1 || !Menu_paused || Menu_zoomLevel>1 || vx || vy || Menu_penMode == Pen_PAINT) {
					axis w = abs(vx);
					if (w<abs(vy)) w=abs(vy);
					w = atLeast(w, 1);
					vx = (vx<<8)/w;
					vy = (vy<<8)/w;
					axis x2 = (Pen_oldx<<8)+127;
					axis y2 = (Pen_oldy<<8)+127;
					// for each point along line
					for (int c=0; c<=w; c++,x2+=vx,y2+=vy) {
						axis xStart = (x2>>8)-Menu_penSize;
						axis yStart = (y2>>8)-Menu_penSize;
						axis xEnd=xStart+2*Menu_penSize;
						axis yEnd=yStart+2*Menu_penSize;
						if (xStart<8) xStart=8;
						if (yStart<8) yStart=8;
						if (xEnd>W+8-1) xEnd=W+8-1;
						if (yEnd>H+8-1) yEnd=H+8-1;
						for (axis g=yStart; g<=yEnd; g++) {
							for (axis f=xStart; f<=xEnd; f++) {
								// circle
								axis dx = f-(x2>>8);
								axis dy = g-(y2>>8);
								if (Menu_penSize*Menu_penSize+1 < dx*dx+dy*dy) continue;
								Dot* p = Dot_at[g][f];
								if (Menu_penMode == Pen_PAINT) {
									Elem e = Menu_BUTTONS[selection].element ?: Elem_POWDER;
									int meta = 0;
									if (e!=Elem_FAN) {
										if (e==Elem_FIREWORKS) {
											meta = Menu_BUTTONS[Menu_leftSelection].firework ?: Menu_BUTTONS[Menu_rightSelection].firework ?: Elem_POWDER;
										} else if (e==Elem_LASER) {
											meta = 8*Vec_angle(Pen_dir)/TAU+0.5;
											if (meta>=8)
												meta = 0;
											meta = meta+1;
										}
										if (p>=Dot_0 && p->type!=e)
											Dot_paint(f, g, p->type, e, meta);
									}
								} else {
									if (selection==Menu_CLEAR) {
										if (p>=Dot_0) {
											Dot_remove(p);
											Dot_at[g][f] = Dot_EMPTY;
										}
									} else if (p == Dot_EMPTY) {
										Elem pa = Menu_BUTTONS[selection].element;
										if (otherBtn->wasHeld && selection<Menu_ELEMENTS)
											pa = Menu_BUTTONS[otherSel].element;
										
										Dot* e = Dot_create(f, g, pa);
										if (e>=Dot_0) {
											if (pa==Elem_FAN) {
												e->vel = Vec_mul2(Pen_dir, 0.1);
											} else if (pa==Elem_FIREWORKS) {
												e->meta = Menu_BUTTONS[otherSel].firework ?:  Elem_POWDER;
											} else if (pa==Elem_LASER) {
												int meta = 8*Vec_angle(Pen_dir)/TAU+0.5;
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
			}
		} else {
			switch (selection) {
			when(Menu_WIND):;
				Point b = Vec_mul2(Pen_dir, 10);
				Block* e = &Dot_blocks[Pen_y>>2][Pen_x>>2];
				if (old && e->block == 0) {
					Vec_add(&e->vel, b);
					if (Vec_fastDist(e->vel)>10 && Menu_paused) {
						Vec_fastNormalize(&e->vel);
						Vec_mul(&e->vel, 10);
					}
				}
			when(Menu_AIR):;
				void addPressure(axis x, axis y, real amount) {
					Block* cell = &Dot_blocks[Pen_y/4+y][Pen_x/4+x];
					if (!cell->block)
						Block_addPressure(cell, amount);
				}
				if (old) {
					int v=(Menu_penSize+1)*(Menu_penSize+1)*0.25;
					v = i ? -v : v;
					addPressure(0,0,v);
					addPressure(-1,0,v);
					addPressure(0,-1,v);
					addPressure(-1,-1,v);
				}
			when(Menu_BUBBLE):;
				Bubble_draw(Pen_x, Pen_y, gotPress, old);
			when(Menu_PLAYER): case Menu_FIGHTER: case Menu_BOX: case Menu_CREATE:
				if (!gotPress) break;
				axis f = Pen_x>>2<<2;
				axis g = Pen_y>>2<<2;
				Block* cell = &Dot_blocks[Pen_y>>2][Pen_x>>2];
				if (!cell->block) {
					switch (selection) {
					when(Menu_FIGHTER):;
						Entity_create(f, g, 0, 0);
					when(Menu_BOX):;
						Entity_create(f, g, Elem_BOX, Menu_penSize);
					when(Menu_PLAYER):;
						Elem type = Menu_BUTTONS[otherSel].player;
						Entity_create(f, g, Elem_PLAYER, type);
					when(Menu_CREATE):;
						Entity_create(f, g, Elem_BOX, 10);
					}
				}
			when(Menu_BALL):;
				cell = &Dot_blocks[Pen_y>>2][Pen_x>>2];
				if (cell->block==0 && gotPress) {
					Elem type = Menu_BUTTONS[otherSel].ball;
					if (type)
						Ball_create(Pen_x, Pen_y, type);
				}
			when(Menu_WHEEL):;
				if (gotPress) {
					axis x = clamp(Pen_x, 24, W-9);
					axis y = clamp(Pen_y, 24, H-9);
					Wheel_create(x, y);
				}
			when(Menu_BLOCK): case Menu_ERASE: case Menu_CLEAR:
				if (Menu_penMode==Pen_LINE)
					old = btn->gotRelease;
				if (old) {
					// god, more line drawing shit
					axis n = (int)Pen_x/4 - (int)Pen_oldx/4;
					axis r = (int)Pen_y/4 - (int)Pen_oldy/4;
					axis w = abs(n);
					if (abs(r)>w) w=abs(r);
					w = atLeast(w, 1);
					n = (n<<8)/w;
					r = (r<<8)/w;
					int y = ((int)Pen_oldx/4<<8)-127;
					int z = ((int)Pen_oldy/4<<8)-127;
					for (int b=0; b<=w; b++, y+=n, z+=r) {
						int c = (y>>8) - (int)Menu_penSize/2;
						int v = (z>>8) - (int)Menu_penSize/2;
						int Y = c+(real)Menu_penSize/2+0.5;
						int Ka = v+(real)Menu_penSize/2+0.5;
						for (axis g=v; g<=v+Menu_penSize; g++) {
							for (axis f=c; f<=c+Menu_penSize; f++) {
								if ((f-Y)*(f-Y)+(g-Ka)*(g-Ka)<=Menu_penSize*Menu_penSize/4) {
									Block* cell = &Dot_blocks[(int)clamp(g,2,(HEIGHT)/4-3)][(int)clamp(f,2,(WIDTH)/4-3)];
									switch(selection) {
									when(Menu_BLOCK):;
										cell->block = 1;
										cell->vel = (Point){0,0};
										Block_clearPressure(cell);
									when(Menu_ERASE):;
										cell->block = -2;
									when(Menu_CLEAR):;
										if (cell->block == 0) {
											cell->block = -2;
											cell->vel = (Point){0,0};
											Block_clearPressure(cell);
										}
									}
								}
							}
						}
					}
					/// aaaaa
					// this is broken i think
					if (selection==Menu_CLEAR && Menu_penSize==0) {
						int n=Pen_x-Pen_oldx;
						int r=Pen_y-Pen_oldy;
						int w=abs(n);
						if (abs(r)>w) w = abs(r);
						if (1>w) w = 1;
						n = (n<<8)/w;
						r = (r<<8)/w;
						for (int y=(Pen_oldx<<8)+127,z=(Pen_oldy<<8)+127,b=0;b<=w;b++,y+=n,z+=r) {
							Dot_FOR (e) {
								if (y>>8==(int)e->pos.x && z>>8==(int)e->pos.y)
									Dot_remove(e--);
							}
						}
					}
					if (selection == Menu_BLOCK || selection == Menu_CLEAR) {
						Dot_FOR (p) {
							if (Dot_blocks[(int)p->pos.y>>2][(int)p->pos.x>>2].block != 0)
								Dot_remove(p--);
						}
					}
					if (selection==Menu_ERASE || selection==Menu_CLEAR) {
						Block_FOR(cell) {
							if (cell->block==-2)
								cell->block = 0;
						}
					}
					for (int y=8;y<H+8;y++) {
						for (int x=8;x<W+8;x++) {
							Block* cell = &Dot_blocks[y>>2][x>>2];
							Dot** part = &Dot_at[y][x];
							if (cell->block==0 && *part == Dot_BLOCK)
								*part = Dot_EMPTY;
							else if (cell->block==1 && *part < Dot_BLOCK)
								*part = Dot_BLOCK;
						}
					}
				}
			}
		}
	}
}

MenuButtonDef Menu_BUTTONS[] = {
	{Elem_POWDER,Elem_POWDER,Elem_POWDER,Elem_POWDER},
	{Elem_WATER,Elem_WATER,Elem_WATER,Elem_WATER},
	{Elem_FIRE,Elem_FIRE,Elem_FIRE,Elem_FIRE},
	{Elem_SEED,Elem_SEED,Elem_SEED,Elem_SEED},
	{Elem_GUNPOWDER,Elem_GUNPOWDER,Elem_GUNPOWDER,Elem_GUNPOWDER},
	{Elem_FAN,0,Elem_FAN,Elem_FAN},
	{Elem_ICE,0,0,Elem_ICE},
	{Elem_SUPERBALL,Elem_SUPERBALL,Elem_SUPERBALL,0},
	{Elem_CLONE,0,0,Elem_CLONE},
	{Elem_FIREWORKS,0,Elem_FIREWORKS,0},
	{Elem_OIL,Elem_OIL,Elem_OIL,Elem_OIL},
	{Elem_C4,0,0,Elem_C4},
	{Elem_STONE,Elem_STONE,Elem_STONE,Elem_STONE},
	{Elem_MAGMA,Elem_MAGMA,Elem_MAGMA,Elem_MAGMA},
	{Elem_VIRUS,Elem_VIRUS,Elem_VIRUS,Elem_VIRUS},
	{Elem_NITRO,Elem_NITRO,Elem_NITRO,Elem_NITRO},
	{Elem_ANT,Elem_ANT,Elem_ANT,0},
	{Elem_TORCH,0,0,Elem_TORCH},
	{Elem_GAS,Elem_GAS,Elem_GAS,Elem_GAS},
	{Elem_SOAPY,Elem_SOAPY,Elem_SOAPY,Elem_SOAPY},
	{Elem_THUNDER,Elem_THUNDER,0,Elem_THUNDER},
	{Elem_METAL,0,0,Elem_METAL},
	{Elem_BOMB,Elem_BOMB,Elem_BOMB,Elem_BOMB},
	{Elem_LASER,Elem_LASER,Elem_LASER,0},
	{Elem_ACID,Elem_ACID,Elem_ACID,Elem_ACID},
	{Elem_VINE,0,0,0},
	{Elem_SALT,Elem_SALT,Elem_SALT,Elem_SALT},
	{Elem_GLASS,0,0,Elem_GLASS},
	{Elem_BIRD,Elem_BIRD,Elem_BIRD,Elem_BIRD},
	{Elem_MERCURY,Elem_MERCURY,Elem_MERCURY,0},
	{Elem_SPARK,Elem_SPARK,Elem_SPARK,0},
	{Elem_FUSE,0,0,Elem_FUSE},
	{Elem_CLOUD,Elem_CLOUD,Elem_CLOUD,Elem_CLOUD},
	{Elem_PUMP,0,0,Elem_PUMP},
	//{0,0,0,0},
	{Elem_WOOD,0,0,Elem_WOOD},
	{Elem_SNOW,Elem_SNOW,Elem_SNOW,0},
	{Elem_STEAM,Elem_STEAM,Elem_STEAM,Elem_STEAM},
	{Elem_SEAWATER,Elem_SEAWATER,Elem_SEAWATER,Elem_SEAWATER},
	{Elem_CONCRETE,Elem_CONCRETE,Elem_CONCRETE,Elem_CONCRETE},
	{0,0,0,0},
	// rest is 0
};

void Menu_reset(void) {
	Pen_oldx = Pen_oldy = Pen_x = Pen_y = 8;
	Menu_pen = (Point){8,8};
	Menu_penOld = (Point){8,8};
	Pen_dir = (Point){0,0};
}
