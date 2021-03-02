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

//todo: split this file into menu rendering + menu buttons/controls

enum PenMode {Pen_FREE, Pen_LINE, Pen_LOCK, Pen_PAINT};
int wa; //this is the state when navigating the upload menu

axis Pen_x=0, Pen_y=0;
axis Pen_oldx=0, Pen_oldy=0;
Vector Pen_dir = {0,0};

int Menu_hover = -1;
bool Menu_numberMenu = false;
bool Menu_copyMode = false;
bool Menu_paused = false;
bool Menu_cursorInMenu = false;
int Menu_penMode = 0;
int Menu_leftSelection = 10;
int Menu_rightSelection = 0;
int Menu_penSize = 0;
int Menu_zoomLevel = 0;
axis Menu_zoomX = 0;
axis Menu_zoomY = 0;
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

static void moveZoom(axis x, axis y) {
	Menu_zoomX = clamp(x, 0, W-ceil((float)W/(1<<Menu_zoomLevel)));
	Menu_zoomY = clamp(y, 0, H-ceil((float)H/(1<<Menu_zoomLevel)));
}

void Menu_input(void) {
	if (Mouse_old.y>=H && Mouse_risingClick)
		Menu_cursorInMenu=true;
	else if (Mouse_old.y<H)
		Menu_cursorInMenu=false;
	if (!Menu_cursorInMenu) {
		Menu_hover = -1;
		return;
	}
	// clicked a menu button
	int c=12;
	int e=H+11;
	if (mouseinside(c-8,e-8,391,139)/*&& wa==0*/) {
		int d = (Mouse_old.x-(c-8))/Menu_BUTTONWIDTH;
		int b = (Mouse_old.y-(e-8))/Menu_BUTTONHEIGHT;
		int selection = clamp(Menu_BUTTONROWS*d+b,0,69);
		Menu_hover = selection;
		switch (selection) {
		when(Menu_COPYPASTE):;
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
		when(Menu_PEN):;
			Menu_penMode = wrap(Menu_penMode+Mouse_fallingDirection, 3);
		when(Menu_PENSIZE):;
			Menu_penSize = wrap(Menu_penSize+Mouse_fallingDirection, 9);
		when(Menu_SCALE):;
			if (Mouse_rising.left) {
				if (Menu_leftSelection==Menu_SCALE) {
					if (Menu_zoomLevel<4) {
						Menu_zoomLevel++;
						Menu_zoomX += W>>Menu_zoomLevel>>1;
						Menu_zoomY += H>>Menu_zoomLevel>>1;
					} else
						Menu_zoomLevel = 0;
				}
				Menu_leftSelection = selection;
			} else if (Mouse_rising.right) {
				if (Menu_rightSelection==Menu_SCALE) {
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
			moveZoom(Menu_zoomX, Menu_zoomY);
		when(Menu_SPEED):;
			Menu_gameSpeed = wrap(Menu_gameSpeed+Mouse_fallingDirection, 3);
		when(Menu_START):;
			Menu_paused=wrap((Menu_paused?1:0)+Mouse_fallingDirection,1)==1;
		when(Menu_UPLOAD):;
			if (Mouse_fallingDirection)
				wa=1;
		when(Menu_SAVE):;
			if (Mouse_rising.left || Mouse_rising.right) {
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
}

void Menu_update(void) {
	static long last;
	long ms = Platform_millisec();
	double fps = (1000.0)/(ms-last);
	last = ms;
	Menu_fps = (Menu_fps*9+fps)/10;
	
	if (Menu_cursorInMenu)
		return;
	Pen_oldx = Pen_x;
	Pen_oldy = Pen_y;
	Pen_x = Mouse_old.x;
	Pen_y = Mouse_old.y;
	if (Menu_zoomLevel>0) {
		Pen_x = Menu_zoomX+(Pen_x>>Menu_zoomLevel);
		Pen_y = Menu_zoomY+(Pen_y>>Menu_zoomLevel);
	}
	Pen_x = clamp(Pen_x+8,8,W-1);
	Pen_y = clamp(Pen_y+8,8,H-1);
	// todo: line mode etc.
	Vector c = {Pen_x,Pen_y};
	Pen_dir.x = Pen_oldx-5*Pen_dir.x;
	Pen_dir.y = Pen_oldy-5*Pen_dir.y;
	double q = 5;
	Vector ee;
	Vec_sub2(&ee, &c, &Pen_dir);
	q -= Vec_fastNormalize(&ee);
	double d = q*0.5;
	double a = q*0.5;
	c.x += ee.x*a;
	c.y += ee.y*a;
	Pen_dir.x -= ee.x*d;
	Pen_dir.y -= ee.y*d;
	Vec_sub2(&Pen_dir, &c, &Pen_dir);
	Vec_fastNormalize(&Pen_dir);
	if (Menu_zoomLevel!=0 && Mouse_now.middle) {
		Menu_zoomX -= (Mouse_old.x-Mouse_older.x)/(1<<Menu_zoomLevel);
		Menu_zoomY -= (Mouse_old.y-Mouse_older.y)/(1<<Menu_zoomLevel);
		moveZoom(Menu_zoomX, Menu_zoomY);
	}
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
						axis f,g;
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
									if(((i==0 && Mouse_old.right && Menu_rightSelection<38) || (i==1 && Mouse_old.left && Menu_leftSelection<38)) && Random_(100)<50) {
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
					Block* cell = &Part_blocks[Pen_y/4+y][Pen_x/4+x];
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
			when(Menu_BUBBLE):;
				Bubble_draw(Pen_x, Pen_y, rising, old);
			when(Menu_PLAYER): case Menu_FIGHTER: case Menu_BOX: case Menu_CREATE:
				if (!rising) break;
				int f = Pen_x>>2<<2;
				int g = Pen_y>>2<<2;
				Block* cell = &Part_blocks[Pen_y>>2][Pen_x>>2];
				if (!cell->block) {
					switch (selection) {
					when(Menu_FIGHTER):;
						Entity_create(f, g, 0, 0);
					when(Menu_BOX):;
						Entity_create(f, g, Elem_BOX, Menu_penSize);
					when(Menu_PLAYER):;
						int b = Menu_BUTTONS[Menu_leftSelection].player ?: Menu_BUTTONS[Menu_rightSelection].player;
						Entity_create(f, g, Elem_PLAYER, b);
					when(Menu_CREATE):
						Entity_create(f, g, Elem_BOX, 10);
					}
				}
			when(Menu_BALL):;
				cell = &Part_blocks[Pen_y>>2][Pen_x>>2];
				if (cell->block==0 && rising) {
					int b = Menu_BUTTONS[Menu_leftSelection].ball ?: Menu_BUTTONS[Menu_rightSelection].ball;
					if (b)
						Ball_create(Pen_x, Pen_y, b);
				}
			when(Menu_WHEEL):;
				if (rising) {
					axis x = clamp(Pen_x, 24, W-9);
					axis y = clamp(Pen_y, 24, H-9);
					Wheel_create(x, y);
				}
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
										pd += cell->pres;
										cell->pres = 0;
									when(Menu_ERASE):
										cell->block = -2;
									when(Menu_CLEAR):
										if (cell->block == 0) {
											cell->block = -2;
											cell->vel = (Vector){0,0};
											pd+=cell->pres;
											cell->pres=0;
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
						int y,z,b;
						for (y=(Pen_oldx<<8)+127,z=(Pen_oldy<<8)+127,b=0;b<=w;b++,y+=n,z+=r) {
							Part* e;
							for (e=Part_0; e<Part_next; e++)
								if (y>>8==(int)e->pos.x && z>>8==(int)e->pos.y)
									Part_remove(e--);
						}
					}
					if (selection == Menu_BLOCK || selection == Menu_CLEAR) {
						Part* p;//todo: make macros for this!
						for (p=Part_0; p<Part_next; p++)
							if (Part_blocks[(int)p->pos.y>>2][(int)p->pos.x>>2].block != 0)
								Part_remove(p--);

					}
					if (selection==Menu_ERASE || selection==Menu_CLEAR) {
						Block* cell;
						forRange (cell, =Part_blocks[0], <Part_blocks_end, ++) {
							if (cell->block==-2)
								cell->block = 0;
						}
					}
					int x;
					for (y=8;y<H+8;y++) {
						for (x=8;x<W+8;x++) {
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
