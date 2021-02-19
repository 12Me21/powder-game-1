#include <stdlib.h>
#include "common.h"
#include "vector.h"
#include "elements.h"
#include "draw.h"
#include "part.h"
#include "bg.h"
#include "menu.h"

#define PARTS_MAX 40000

// it's important that these are directly before the part array
Part Part_EMPTY[1] = {{.type=Elem_EMPTY}};
Part Part_BGFAN[1] = {{.type=Elem_BGFAN}};;;
Part Part_WHEEL[1] = {{.type=Elem_WHEEL}};;;
Part Part_BALL[1] = {{.type=Elem_BALL}};;  
Part Part_BLOCK[1] = {{.type=Elem_BLOCK}};;;
static Part parts[PARTS_MAX];
Part* next = parts;

Part* Part_at[HEIGHT][WIDTH];

Block Part_blocks[HEIGHT/4][WIDTH/4];

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

void Part_swap(Part* part1, Part* part2, int xy1, int xy2) {
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
		Color* dest = &grp[(int)i->pos.y][(int)i->pos.x];
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
