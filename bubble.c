#include <math.h>
#include <stdlib.h>
#include "menu.h"
#include "vector.h"
#include "input.h"
#include "elements.h"
#include "part.h"
#include "bubble.h"

Bubble Bubble_bubbles[2000];
Bubble* const Bubble_end = &Bubble_bubbles[2000];
Bubble* Bubble_next = Bubble_bubbles;

int Qd = 0;

static bool onscreen(axis x, axis y){
	return x>=8 && x<WIDTH-8 && y>=8 && y<H+8;
}

static void partLine(real a, real d, real b, real c, int type) {
	b -= a;
	c -= d;
	int f;
	if (abs(b)>=abs(c)) {
		f = floor(abs(b));
		if (b)
			c /= abs(b);
		b = b>=0 ? 1 : -1;
	} else {
		f = floor(abs(c));
		if (c)
			b /= abs(c);
		c = c>=0 ? 1 : -1;
	}
	a += 0.5;
	d += 0.5;
	for (int g=0; g<=f; g++,a+=b,d+=c) {
		if (onscreen(a,d) && *Part_pos(a, d)<=Part_BGFAN)
			Part_create(a, d, type);
	}
}

static void pull(Bubble* a, Bubble* b) {
	Point diff = {b->x-a->x, b->y-a->y};
	real dist = Vec_fastNormalize(&diff);
	if (dist!=0) {
		dist = 5-dist;
		a->x -= diff.x*dist*0.5;
		a->y -= diff.y*dist*0.5;
		b->x += diff.x*dist*0.5;
		b->y += diff.y*dist*0.5;
	}
}

void Bubble_update(void) {
	for (Bubble* b=Bubble_bubbles; b<Bubble_next; b++) {
		Block* cell = &Part_blocks[(int)b->y/4][(int)b->x/4];
		Point vel = cell->vel;
		Vec_mul(&vel, 3.8/(Vec_fastDist(vel)+1));
		b->x += vel.x;
		b->y += vel.y;
	}
	for (Bubble* b=Bubble_bubbles; b<Bubble_next; b++) {
		if (!b->held) {
			if (Menu_dragStart) {
				if (Vec_fastDist((Point){Pen_x-b->x, Pen_y-b->y})<10)
					b->held = true;
			}
		} else if (Menu_dragging) {
			b->x += 0.9*(Pen_x-b->x);
			b->y += 0.9*(Pen_y-b->y);
		} else {
			b->held = false;
		}
	}
	for (Bubble* b=Bubble_bubbles; b<Bubble_next-1; /*b++*/) {
		Bubble* d;
		int e=0;
		for (d=b; d<Bubble_next && d->ke==b->ke; d++)
			e++;
		Point v = {0,0};
		for (d=b; d<b+e; d++) {
			v.x += d->x;
			v.y += d->y;
		}
		v.x /= e;
		v.y /= e;
		for (d=b; d<b+e; d++) {
			Point f = {v.x-d->x, v.y-d->y};
			real c = Vec_fastNormalize(&f);
			if (c!=0) {
				c = e*(5/(PI+PI)*2)-c; //PI+PI is slightly less than TAU
				d->x -= f.x*c*0.1;
				d->y -= f.y*c*0.1;
			}
		}
		for (d=b; d<b+e-1; d++)
			pull(d, d+1);
		pull(d, b);
		b+=e;
	}
	for (Bubble* b=Bubble_bubbles; b<Bubble_next; b++) {
		Part* part = Part_EMPTY;
		if (b->x>=0 && b->x<WIDTH && b->y>=0 && b->y<H+16) {
			part = *Part_pos(b->x, b->y);
			if (part<=Part_BGFAN) continue;
			if (part>=Part_0 && part->type==Elem_SOAPY) continue;
		}
		int c = b->ke;
		Bubble *a, *e;
		for (a=b; a>Bubble_bubbles && c==(a-1)->ke; a--) {
		}
		for (e=b; a>Bubble_bubbles && c==e->ke; e++) {
		}
		int type = part>=Part_0 ? part->type : Elem_STEAM;
		Bubble* d;
		for (d=a; d<e-1; d++)
			partLine(d->x, d->y, (d+1)->x, (d+1)->y, type);
		partLine(d->x, d->y, a->x, a->y, type);
		// deallocate
		for (; e<Bubble_next; a++, e++)
			*a = *e;
		Bubble_next -= (e-a);
	}
}

void Bubble_draw(axis x, axis y, bool rising, bool old) {
	if (Bubble_next > Bubble_end-5) //todo: END should be uppercase
		return;
	x = x&~3;
	y = y&~3;
	Block* cell = &Part_blocks[y>>2][x>>2];
	if (cell->block!=0)
		Qd++;
	else {
		if (rising)
			Qd++;
		if (old) {
			int q = 0;
			for (Bubble* n = Bubble_next-1; n>=Bubble_bubbles && n->ke==Qd; n--)
				q++;
			if (q<5) {
				Qd++;
				Bubble_create(x+Random_(4), y+Random_(4));
				Bubble_create(x+Random_(4), y+Random_(4));
				Bubble_create(x+Random_(4), y+Random_(4));
				Bubble_create(x+Random_(4), y+Random_(4));
			}
			Bubble_create(x+Random_(4), y+Random_(4));
		}
	}
}

void Bubble_create(axis x, axis y) {
	if (Bubble_next < Bubble_end) {
		*Bubble_next = (Bubble){
			.x = x,
			.y = y,
			.ke = Qd,
			.held = false,
		};
		Bubble_next++;
	}
}
