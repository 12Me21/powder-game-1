#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "common.h"
#include "elements.h"
#include "part.h"
#include "input.h"
#include "menu.h"
#include "bg.h"
#include "entity.h"
#include "ball.h"
#include "platform.h"
#include "cell.h"
#include "wheel.h"
#include "bubble.h"
#include "reset.h"

//todo: split this file into menu rendering + menu buttons/controls

enum PenMode {Pen_FREE, Pen_LINE, Pen_LOCK, Pen_PAINT};
int wa; //this is the state when navigating the upload menu

axis Pen_x=0, Pen_y=0;
axis Pen_oldx=0, Pen_oldy=0;
Point Menu_pen = {0,0};
Point Menu_penOld = {0,0};
Point Pen_dir = {0,0};

int Menu_hover = -1;
bool Menu_numberMenu = false;
bool Menu_dragStart = false, Menu_dragging = false;
bool Menu_copyMode = false;
bool Menu_paused = false;
bool Menu_cursorInMenu = false;
int Menu_penMode = 0;
int Menu_leftSelection = 10;
int Menu_rightSelection = 0;
int Menu_penSize = 0;
int Menu_zoomLevel = 0;
axis Menu_zoomX = 0, Menu_zoomY = 0;
int Menu_dotLimit = 0;
int Menu_gridSize = 0;
int Menu_carefully = 0;
int Menu_bgMode = Bg_NONE;
int Menu_edgeMode = 0;
int Menu_gameSpeed = 0;
bool Menu_minimapEnabled = false;
int buttonflash = 0;
int Menu_fps = 0;

const int Part_LIMITS[3] = {10000, 20000, 40000}; //todo;

static int wrap(int a, int b) {
	if (a<0)
		return b;
	if (a>b)
		return 0;
	return a;
}

static bool mouseinside(axis x, axis y, axis width, axis height) {
	return !(mouse.pos.x<x||mouse.pos.x>=x+width||mouse.pos.y<y||mouse.pos.y>=y+height);
}

static void clampZoom(void) {
	Menu_zoomX = clamp(Menu_zoomX, 0, W-ceil((real)W/(1<<Menu_zoomLevel)));
	Menu_zoomY = clamp(Menu_zoomY, 0, H-ceil((real)H/(1<<Menu_zoomLevel)));
}

void Menu_input(void) {
	Menu_dragStart = (Menu_leftSelection == Menu_DRAG && mouse.left.gotPress) || (Menu_rightSelection == Menu_DRAG && mouse.right.gotPress); //todo: function for this
	Menu_dragging = (Menu_leftSelection == Menu_DRAG && mouse.left.wasHeld) || (Menu_rightSelection == Menu_DRAG && mouse.right.wasHeld);
	
	if (mouse.pos.y>=H && Mouse_risingClick)
		Menu_cursorInMenu=true;
	else if (mouse.pos.y<H)
		Menu_cursorInMenu=false;
	if (!Menu_cursorInMenu) {
		Menu_hover = -1;
		return;
	}
	// clicked a menu button
	axis c=4;
	axis e=H+3;
	if (mouseinside(c,e,391,139)/*&& wa==0*/) {
		axis d = (mouse.pos.x-c)/Menu_BUTTONWIDTH;
		axis b = (mouse.pos.y-e)/Menu_BUTTONHEIGHT;
		int selection = clamp(Menu_BUTTONROWS*d+b,0,69);
		Menu_hover = selection;
		switch (selection) {
		when(Menu_COPYPASTE):;
			if (mouse.left.gotPress) {
				if (Menu_leftSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_leftSelection = selection;
			}
			if (mouse.right.gotPress) {
				if (Menu_rightSelection == Menu_COPYPASTE)
					Menu_copyMode = !Menu_copyMode;
				Menu_rightSelection = selection;
			}
		when(Menu_PEN):;
			Menu_penMode = wrap(Menu_penMode+Mouse_fallingDirection, 3);
		when(Menu_PENSIZE):;
			Menu_penSize = wrap(Menu_penSize+Mouse_fallingDirection, 9);
		when(Menu_SCALE):;
			if (mouse.left.gotPress) {
				if (selection==Menu_SCALE) {
					if (Menu_zoomLevel<4) {
						Menu_zoomLevel++;
						Menu_zoomX += W>>Menu_zoomLevel>>1;
						Menu_zoomY += H>>Menu_zoomLevel>>1;
					} else
						Menu_zoomLevel = 0;
				}
				Menu_leftSelection = selection;
			} else if (mouse.right.gotPress) {
				if (selection==Menu_SCALE) {
					if (Menu_zoomLevel>0) {
						Menu_zoomX -= W>>Menu_zoomLevel>>1;
						Menu_zoomY -= H>>Menu_zoomLevel>>1;
						Menu_zoomLevel--;
					} else {
						Menu_zoomLevel = 4;
						Menu_zoomX += W/2-(W>>Menu_zoomLevel>>1);
						Menu_zoomY += H/2-(H>>Menu_zoomLevel>>1);
					}
				}
				Menu_rightSelection = selection;
			}
			clampZoom();
		when(Menu_SPEED):;
			Menu_gameSpeed = wrap(Menu_gameSpeed+Mouse_fallingDirection, 3);
		when(Menu_START):;
			Menu_paused=wrap((Menu_paused?1:0)+Mouse_fallingDirection,1)==1;
		when(Menu_UPLOAD):;
			if (Mouse_fallingDirection)
				wa=1;
		when(Menu_SAVE):;
			if (mouse.right.gotPress || mouse.left.gotPress) {
				//save1();
				//makesavestring();
				buttonflash=10;
			}
		when(Menu_LOAD):;
			if (Mouse_fallingDirection!=0) {
				//loadsavestring();
				//load1();
				buttonflash=-10;
			}
		when(Menu_MINIMAP):;
			Menu_minimapEnabled = wrap(Menu_minimapEnabled+Mouse_fallingDirection,1);
		when(Menu_MENU):;
			Menu_numberMenu = wrap(Menu_numberMenu+Mouse_fallingDirection, 1);
		when(Menu_SIDE):;
			Menu_edgeMode = wrap(Menu_edgeMode+Mouse_fallingDirection, 1);
		when(Menu_GRID):;
			Menu_gridSize=wrap(Menu_gridSize+Mouse_fallingDirection, 7);
		when(Menu_BG):;
			Menu_bgMode = wrap(Menu_bgMode+Mouse_fallingDirection, 13);
			if (Mouse_fallingDirection)
				Bg_reset();
		when(Menu_DOT):;
			Menu_dotLimit = wrap(Menu_dotLimit+Mouse_fallingDirection, 2);
		when(Menu_RESET):;
			if (Mouse_fallingDirection)
				Sim_reset(false);
		otherwise:
			if (selection < 38 || selection >= 40) {
				if (mouse.left.gotPress)
					Menu_leftSelection = selection;
				else if (mouse.right.gotPress)
					Menu_rightSelection = selection;
			}
		}
	}
}

void Menu_update(void) {
	static long last;
	long ms = Platform_nanosec();
	if (ms>last) {
		real fps = (1000000000.0)/(ms-last);
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
		if (selection < 38) {
			if (Menu_penMode == Pen_LINE)
				old = gotRelease;
			if (old) {
				axis vx = Pen_x - Pen_oldx;
				axis vy = Pen_y - Pen_oldy;
				if (Menu_penSize>1 || !Menu_paused || Menu_zoomLevel>1 || vx || vy || Menu_penMode == Pen_PAINT) {
					axis w = abs(vx);
					if (w<abs(vy)) w=abs(vy);
					if (w<1) w=1;
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
								Part* p = Part_at[g][f];
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
										if (p>=Part_0 && p->type!=e)
											Part_paint(f, g, p->type, e, meta);
									}
								} else if (p == Part_EMPTY) {
									Elem pa = Menu_BUTTONS[selection].element;
									if (otherBtn->wasHeld && selection<38)
										pa = Menu_BUTTONS[otherSel].element;
									
									Part* e = Part_create(f, g, pa);
									if (e>=Part_0) {
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
		} else {
			switch (selection) {
			when(Menu_WIND):;
				Point b = Vec_mul2(Pen_dir, 10);
				Block* e = &Part_blocks[Pen_y>>2][Pen_x>>2];
				if (old && e->block == 0) {
					Vec_add(&e->vel, b);
					if (Vec_fastDist(e->vel)>10 && Menu_paused) {
						Vec_fastNormalize(&e->vel);
						Vec_mul(&e->vel, 10);
					}
				}
			when(Menu_AIR):;
				void addPressure(axis x, axis y, real amount) {
					Block* cell = &Part_blocks[Pen_y/4+y][Pen_x/4+x];
					if (!cell->block)
						Cell_addPressure(cell, amount);
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
				Block* cell = &Part_blocks[Pen_y>>2][Pen_x>>2];
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
				cell = &Part_blocks[Pen_y>>2][Pen_x>>2];
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
					axis n = Pen_x/4 - Pen_oldx/4;
					axis r = Pen_y/4 - Pen_oldy/4;
					axis w = abs(n);
					if (abs(r)>w) w=abs(r);
					if (1>w) w=1;
					n = (n<<8)/w;
					r = (r<<8)/w;
					int y = (Pen_oldx/4<<8)-127;
					int z = (Pen_oldy/4<<8)-127;
					for (int b=0; b<=w; b++, y+=n, z+=r) {
						int c = (y>>8) - Menu_penSize/2;
						int v = (z>>8) - Menu_penSize/2;
						int Y = c+(real)Menu_penSize/2+0.5;
						int Ka = v+(real)Menu_penSize/2+0.5;
						for (axis g=v; g<=v+Menu_penSize; g++) {
							for (axis f=c; f<=c+Menu_penSize; f++) {
								if ((f-Y)*(f-Y)+(g-Ka)*(g-Ka)<=Menu_penSize*Menu_penSize/4) {
									Block* cell = &Part_blocks[(int)clamp(g,2,(H+16)/4-3)][(int)clamp(f,2,(W+16)/4-3)];
									switch(selection) {
									when(Menu_BLOCK):;
										cell->block = 1;
										cell->vel = (Point){0,0};
										Cell_clearPressure(cell);
									when(Menu_ERASE):;
										cell->block = -2;
									when(Menu_CLEAR):;
										if (cell->block == 0) {
											cell->block = -2;
											cell->vel = (Point){0,0};
											Cell_clearPressure(cell);
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
							for (Part* e=Part_0; e<Part_next; e++)
								if (y>>8==(int)e->pos.x && z>>8==(int)e->pos.y)
									Part_remove(e--);
						}
					}
					if (selection == Menu_BLOCK || selection == Menu_CLEAR) {
						//todo: make macros for this!
						for (Part* p=Part_0; p<Part_next; p++)
							if (Part_blocks[(int)p->pos.y>>2][(int)p->pos.x>>2].block != 0)
								Part_remove(p--);

					}
					if (selection==Menu_ERASE || selection==Menu_CLEAR) {
						for (Block* cell=Part_blocks[0]; cell<Part_blocks_end; cell++) {
							if (cell->block==-2)
								cell->block = 0;
						}
					}
					for (int y=8;y<H+8;y++) {
						for (int x=8;x<W+8;x++) {
							Block* cell = &Part_blocks[y>>2][x>>2];
							Part** part = &Part_at[y][x];
							if (cell->block==0 && *part == Part_BLOCK)
								*part = Part_EMPTY;
							else if (cell->block==1 && *part < Part_BLOCK)
								*part = Part_BLOCK;
						}
					}
				}
			}
		}
	}
}
