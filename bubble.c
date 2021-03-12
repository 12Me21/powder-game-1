#include <math.h>
#include <stdlib.h>
#include "menu.h"
#include "vector.h"
#include "random.h"
#include "input.h"
#include "elements.h"
#include "dot.h"
#include "bubble.h"

Bubble Bubble_bubbles[2000];
Bubble* const Bubble_END = &Bubble_bubbles[2000];
Bubble* Bubble_next = Bubble_bubbles;

int nextGroup = 0;

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
		if (onscreen(a,d) && *Dot_pos(a, d)<=Dot_BGFAN)
			Dot_create(a, d, type);
	}
}

static void pull(Bubble* a, Bubble* b) {
	Point diff;
	diff.xy = b->pos.xy - a->pos.xy;
	real dist = Vec_fastNormalize(&diff);
	if (dist!=0) {
		dist = 5-dist;
		a->pos.xy -= diff.xy*dist*0.5;
		b->pos.xy += diff.xy*dist*0.5;
	}
}

void Bubble_update(void) {
	Bubble_FOR (b) {
		Block* cell = &Blocks[(int)b->pos.y/4][(int)b->pos.x/4];
		Point vel = cell->vel;
		Vec_mul(&vel, 3.8/(Vec_fastDist(vel)+1));
		b->pos.xy += vel.xy;
	}
	Bubble_FOR (b) {
		if (!b->held) {
			if (Menu_dragStart) {
				if (Vec_fastDist(Vec_sub2(Menu_pen, b->pos))<10)
					b->held = true;
			}
		} else if (Menu_dragging) {
			b->pos.xy += 0.9*(Menu_pen.xy - b->pos.xy);
		} else {
			b->held = false;
		}
	}
	// todo: this is messy
	for (Bubble* b=Bubble_bubbles; b<Bubble_next-1; /*b++*/) {
		Bubble* d;
		int e=0;
		for (d=b; d<Bubble_next && d->group==b->group; d++)
			e++;
		Point v = {0,0};
		for (d=b; d<b+e; d++) {
			v.xy += d->pos.xy;
		}
		v.xy /= e;
		for (d=b; d<b+e; d++) {
			Point f;
			f.xy = v.xy - d->pos.xy;
			real c = Vec_fastNormalize(&f);
			if (c!=0) {
				c = e*(5/(PI+PI)*2)-c; //PI+PI is slightly less than TAU
				d->pos.xy -= f.xy*c*0.1;
			}
		}
		for (d=b; d<b+e-1; d++)
			pull(d, d+1);
		pull(d, b);
		b += e;
	}
	Bubble_FOR (b) {
		Dot* part = Dot_EMPTY;
		if (b->pos.x>=0 && b->pos.x<WIDTH && b->pos.y>=0 && b->pos.y<HEIGHT) {
			part = *Dot_pos2(b->pos);
			if (part<=Dot_BGFAN) continue;
			if (part>=Dot_0 && part->type==Elem_SOAPY) continue;
		}
		int c = b->group;
		Bubble *a, *e;
		for (a=b; a>Bubble_bubbles && c==(a-1)->group; a--) {
		}
		for (e=b; a>Bubble_bubbles && c==e->group; e++) {
		}
		int type = part>=Dot_0 ? part->type : Elem_STEAM;
		Bubble* d;
		for (d=a; d<e-1; d++)
			partLine(d->pos.x, d->pos.y, (d+1)->pos.x, (d+1)->pos.y, type);
		partLine(d->pos.x, d->pos.y, a->pos.x, a->pos.y, type);
		// deallocate
		for (; e<Bubble_next; a++, e++)
			*a = *e;
		Bubble_next -= (e-a);
	}
}

void Bubble_nextId(void) {
	nextGroup++;
}

void Bubble_draw(axis x, axis y, bool rising, bool old) {
	if (Bubble_next > Bubble_END-5)
		return;
	x = x&~3;
	y = y&~3;
	Block* cell = &Blocks[y>>2][x>>2];
	if (cell->block!=0)
		Bubble_nextId();
	else {
		if (rising)
			Bubble_nextId();
		if (old) {
			int q = 0;
			for (Bubble* n = Bubble_next-1; n>=Bubble_bubbles && n->group==nextGroup; n--)
				q++;
			if (q<5) {
				Bubble_nextId();
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
	if (Bubble_next < Bubble_END) {
		*Bubble_next = (Bubble){
			.pos = {x,y},
			.group = nextGroup,
			.held = false,
		};
		Bubble_next++;
	}
}

void Bubble_reset(void) {
	Bubble_next = Bubble_bubbles;
	nextGroup = 0;
}
