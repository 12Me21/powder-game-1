#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "vector.h"
#include "elements.h"
#include "draw.h"
#include "part.h"
#include "bg.h"
#include "menu.h"
#include "input.h"

#define PARTS_MAX 40000

int wa;

// it's important that these are directly before the part array
Part Part_EMPTY[1] = {{.type=Elem_EMPTY}};
Part Part_BGFAN[1] = {{.type=Elem_BGFAN}};;;
Part Part_WHEEL[1] = {{.type=Elem_WHEEL}};;;
Part Part_BALL[1] = {{.type=Elem_BALL}};;  
Part Part_BLOCK[1] = {{.type=Elem_BLOCK}};;;
static Part parts[PARTS_MAX];
Part* Part_0 = parts;
Part* next = parts;

Part* Part_at[HEIGHT][WIDTH];

Block Part_blocks[HEIGHT/4][WIDTH/4];
Block Part_blocks_end[0];

Part** Part_pos2(Vec pos) {
	return &Part_at[(int)pos->y][(int)pos->x];
}

static int Part_counts[Elem_MAX];
int* Part_updateCounts(void) {
	int i;
	for (i=0; i<Elem_MAX; i++)
		Part_counts[i] = 0;
	Part* p;
	for (p=parts; p<next; p++)
		if (p->type > 0)
			Part_counts[p->type]++;
	return Part_counts;
}

Part* Part_create(double x, double y, unsigned char element) {
	if (next>=parts+PARTS_MAX || x<7 || x>=409 || y<7 || y>=309)
		return NULL;
	*next = (Part){
		{x,y},
		{0,0},
		element,
		0,
		0,
		false,
	};
	*Part_pos2(&next->pos) = next;
	return next++;
}

void Part_remove(Part* part) {
	*Part_pos2(&part->pos) = Part_EMPTY;
	next--;
	if (next != part) {
		*part = *next;
		*Part_pos2(&part->pos) = part->type==Elem_FAN ? Part_BGFAN : part;
	}
}

void Part_swap(Part* part1, Part* part2) {
	Vector temp = part1->pos;
	temp = part2->pos;
	part2->pos = temp;
	
	Part* temp3 = *Part_pos2(&part1->pos);
	*Part_pos2(&part1->pos) = *Part_pos2(&part2->pos);
	*Part_pos2(&part2->pos) = temp3;
}

Part* Part_blow(Part* part, Vec airvel) {
	Vec_mul(airvel, 3.8/(Vec_fastDist(airvel)+1));
	if (*Part_pos2(&(Vector){part->pos.x+airvel->x, part->pos.y})<=Part_BGFAN)
		part->pos.x += airvel->x;
	if (*Part_pos2(&(Vector){part->pos.x, part->pos.y+airvel->y})<=Part_BGFAN)
		part->pos.y += airvel->y;
	*Part_pos2(&part->pos) = part;
	return part;
}

void Part_render(void) {
	if (Menu_bgMode==Bg_TOON)
		return;
	Part* i;
	for (i=parts; i<next; i++) {
		int type = i->type;
		if (type==Elem_PUMP && i->pumpType!=0)
			type = i->pumpType;
		Color color;
		if (Menu_bgMode==Bg_GRAY)
			color = ELEMENTS[type].grayColor;
		else
			color = ELEMENTS[type].color;
		Color* dest = Draw_pxRef(i->pos.x, i->pos.y);
		int red, green, blue;
		if (Menu_bgMode == Bg_LIGHT) {
			red=((color&0xFF0000)>>18)+(*dest>>16&0xFF);
			if(red>0xFF) red=0xFF;
			green=((color&0x00FF00)>>10)+(*dest>>8&0xFF);
			if(green>0xFF) green=0xFF;
			blue=((color&0x0000FF)>>2)+(*dest&0xFF);
			if(blue>0xFF) blue=0xFF;
			*dest = red<<16|green<<8|blue;
		} else if (Menu_bgMode == Bg_SILUET) {
			red=(*dest>>16&0xFF)-(0xFF-(color>>16&0xFF)+10);
			if (red<0) red=0;
			green=(*dest>>8&0xFF)-(0xFF-(color>>8&0xFF)+10);
			if (green<0) green=0;
			blue=(*dest&0xFF)-(0xFF-(color&0xFF)+10);
			if (blue<0) blue=0;
			*dest = red<<16|green<<8|blue;
		} else {
			*dest = color;
		}
	}
}

void Part_shuffle(void) {
	Part* p;
	for (p=parts; p<next; p++) {
		Part* c = &parts[rand() % (next-parts)];
		Part temp = *p;
		*p = *c;
		*c = temp;

		*Part_pos2(&p->pos) = p->type==Elem_FAN ? Part_BGFAN : p;
		*Part_pos2(&c->pos) = c->type==Elem_FAN ? Part_BGFAN : c;
	}
}

void Part_reset(int a) {
	int x,y;
	for (y=0;y<308/4;y++) {
		for (x=0;x<WIDTH/4;x++) {
			Part_blocks[y][x] = (Block){
				.vel={0,0},
				.vel2={0,0},
				.pres=0,
				.pres2=0,
				.block=0,
			};
		}
	}
	if (a==0) {
		for (x=1;x<WIDTH/4-1;x++) {
			Part_blocks[1][x].block = 1;
			Part_blocks[308/4-1][x].block = 1;
		}
		for (y=1;x<308/4-1;y++) {
			Part_blocks[y][1].block = 1;
			Part_blocks[y][WIDTH/4-1].block = 1;
		}
	}
	next = parts;
	for (y=0;y<308;y++)
		for (x=0;x<WIDTH;x++)
			Part_at[y][x] = Part_EMPTY;
	if (a==0) {
		for (y=0;y<308;y++)
			for (x=0;x<WIDTH;x++)
				if (Part_blocks[y/4][x/4].block==1)
					Part_at[y][x] = Part_BLOCK;
	}
}

void Part_update(void) {
	// todo: wheels
	bool dragStart = (Menu_leftSelection == Menu_DRAG && Mouse_rising.left) || (Menu_rightSelection == Menu_DRAG && Mouse_rising.right); //todo: function for this
	bool dragging = (Menu_leftSelection == Menu_DRAG && Mouse_old.left) || (Menu_rightSelection == Menu_DRAG && Mouse_old.right);
	Part* p;
	forRange (p, =parts, <next, ++) {
		if (!Menu_cursorInMenu && wa==0) {
			if (!p->held) {
				if (dragStart) {
					if (p->type == Elem_FAN)
						continue;
					Vector d = {Pen_x, Pen_y};
					Vec_sub(&d, &p->pos);
					if (Vec_fastDist(&d) < 4*Menu_penSize)
						p->held = true;
				}
			} else if (dragging) {
				Vector d = {Pen_x, Pen_y};
				Vec_sub(&d, &p->pos);
				Vec_mul(&d, 0.1);
				Vec_add(&p->vel, &d);
			} else {
				p->held = false;
			}
		}
		if (p->type != Elem_FAN)
			*Part_pos2(&p->pos) = Part_EMPTY;
		ElemFunc f = ELEMENTS[p->type].update;
		if (f) {
			if (f(p, &Part_blocks[(int)p->pos.y/4][(int)p->pos.x/4]))
				p--; //part died
		}
	} //for

	// check parts that go off screen
	forRange (p, =parts, <next, ++) {
		if (Menu_edgeMode==0) { // void edge
			if (p->pos.x<8||p->pos.y>=408||p->pos.y<8||p->pos.y>=308) {
				Part_remove(p--);
			}
		} else { //loop edge
			if (p->pos.x<8) {
				Part** o = &Part_at[(int)p->pos.y][(int)p->pos.x+400];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<308) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.x += 400;
					*o = p;
				} else {
					Part_remove(p--);
				}
			} else if (p->pos.x>=408) {
				Part** o = &Part_at[(int)p->pos.y][(int)p->pos.x-400];
				if (*o<=Part_BGFAN && p->pos.y>=8 && p->pos.y<308) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.x -= 400;
					*o = p;
				} else {
					Part_remove(p--);
				}
			} else if (p->pos.y<8) {
				Part** o = &Part_at[(int)p->pos.y+300][(int)p->pos.x];
				if (*o<=Part_BGFAN) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.y += 300;
					*o = p;
				} else {
					Part_remove(p--);
				}
			} else if (p->pos.y>=308) {
				Part** o = &Part_at[(int)p->pos.y-300][(int)p->pos.x];
				if (*o<=Part_BGFAN) {
					*Part_pos2(&p->pos) = Part_EMPTY;
					p->pos.y -= 300;
					*o = p;
				} else {
					Part_remove(p--);
				}
			}
		}
	}
}

double pd = 0; //mystery

void Cell_update(void) {
	int open = 0;
	Block* c;
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
		if (!c->block)
			open++;
	if (open>0) {
		pd /= open;
		forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
			if (!c->block)
				c->pres += pd;
		pd = 0;
	}
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++)
		c->vel2 = c->vel;
	int b, d;
	forRange (b, =2, <79-2, ++) {
		forRange (d, =2, <104-2, ++) {
			Block* a = &Part_blocks[b][d];
			if (a->block!=1) {
				Vector c = a->vel;
				double n = Vec_fastNormalize(&c);
				if (n!=0) {
					double r = fabs(c.x);
					double w = fabs(c.y);
					double y = r/(r+w)*n*0.5;
					double n = w/(r+w)*n*0.5;
					Vector e, f;
					Vec_mul2(&e, &c, y);
					Vec_mul2(&f, &c, n);
					int z = c.x<0 ? -1 : 1;
					int v = c.y<0 ? -1 : 1;
					Block* horiz = &Part_blocks[b][d+z];
					Block* vert = &Part_blocks[b+v][d];
					Block* both = &Part_blocks[b+v][d+z];
					if (r>w) {
						if (horiz->block <= 0) {
							Vec_sub(&a->vel2, &e);
							Vec_add(&horiz->vel2, &e);
							horiz->pres += y;
							a->pres -= y;
						} else {
							Vec_sub(&a->vel2, &e); //yes, twice.
							Vec_sub(&a->vel2, &e);
						}
						if (both->block <= 0) {
							Vec_sub(&a->vel2, &f);
							Vec_add(&both->vel2, &f);
							a->pres -= n;
							both->pres += n;
						} else {
							Vec_sub(&a->vel2, &f);
							Vec_sub(&a->vel2, &f);
						}
					} else {
						if (vert->block <= 0) {
							Vec_sub(&a->vel2, &f);
							Vec_add(&vert->vel2, &f);
							a->pres -= y;
							vert->pres += y;
						} else {
							Vec_sub(&a->vel2, &f);
							Vec_sub(&a->vel2, &f);
						}
						if (both->block <= 0) {
							Vec_sub(&a->vel2, &e);
							Vec_add(&both->vel2, &e);
							a->pres -= n;
							both->pres += n;
						} else {
							Vec_sub(&a->vel2, &e);
							Vec_sub(&a->vel2, &e);
						}
					}
				}
			}
		}
	} //
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
		c->pres2 = c->pres;
	}
	forRange (b, =2, <79-2, ++) {
		forRange (d, =2, <104-2, ++) {
			Block* a = &Part_blocks[b][d];
			if (a->block == 1) continue;
			void pcheck(int x, int y) {
				Block* o = &Part_blocks[b+y][d+x];
				if (o->block <= 0) {
					double diff = .0625*(a->pres - o->pres);
					a->vel2.x -= diff;
					a->pres2 -= diff;
				}
			}
			pcheck(-1, 0);
			pcheck( 1, 0);
			pcheck( 0,-1);
			pcheck( 0, 1);
			pcheck(-1,-1);
			pcheck( 1,-1);
			pcheck(-1, 1);
			pcheck( 1, 1);
		}
	}
	forRange (c, =Part_blocks[0], <Part_blocks_end, ++) {
		if (c->block != 1) { //woah -1??
			c->vel = c->vel2;
			c->pres = c->pres2;
		} else {
			c->pres = 0;
			c->vel = (Vector){0,0};
		}
	}
}
