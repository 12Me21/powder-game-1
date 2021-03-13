#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define Bubble_SPACING 5

// draw a line of dots from a to b
static void partLine(Point a, Point b, Elem type) {
	b.xy -= a.xy;
	Point step;
	int steps;
	// major direction: x
	if (fabs(b.x)>=fabs(b.y)) {
		steps = (int)fabs(b.x);
		if (b.x!=0)
			step.y = b.y / fabs(b.x);
		step.x = b.x>=0 ? 1 : -1;
	} else {
		steps = (int)fabs(b.y);
		if (b.y!=0)
			step.x = b.x / fabs(b.y);
		step.y = b.y>=0 ? 1 : -1;
	}
	a.x += 0.5;
	a.y += 0.5;
	for (int i=0; i<=steps; i++) {
		if (!(a.x<8 || a.x>=WIDTH-8 || a.y<8 || a.y>=HEIGHT-8 || *Dot_pos2(a)>Dot_BGFAN))
			Dot_create(a.x, a.y, type);
		a.xy += step.xy;
	}
}

// ensure bubble nodes are 5px apart
static void pull(Bubble* a, Bubble* b) {
	Point offset;
	offset.xy = b->pos.xy - a->pos.xy;
	real distance = Vec_fastNormalize(&offset);
	if (distance!=0) {
		Complex movement = offset.xy*(Bubble_SPACING-distance);
		// move the nodes so they are 5px apart, splitting the movement between them
		a->pos.xy -= movement*0.5;
		b->pos.xy += movement*0.5;
	}
}

// remove bubble nodes from first to end-1
void Bubble_remove(Bubble* first, Bubble* end) {
	// shift items backwards to fill empty space
	memmove(first, end, (Bubble_next-end)*sizeof(Bubble));
	Bubble_next -= end-first;
}

void Bubble_update(void) {
	// bubbles + air velocity interaction
	Bubble_FOR (b) {
		Block* cell = Block_at(b->pos.x, b->pos.y);
		Point vel = cell->vel;
		Vec_mul(&vel, 3.8/(Vec_fastDist(vel)+1));
		b->pos.xy += vel.xy;
	}
	// check dragging bubbles
	Bubble_FOR (b) {
		if (!b->held) {
			if (Menu_dragStart) {
				if (Vec_fastDist(Vec_sub2(Menu_pen, b->pos))<10)
					b->held = true;
			}
		} else if (Menu_dragging)
			b->pos.xy += 0.9*(Menu_pen.xy - b->pos.xy);
		else
			b->held = false;
	}
	// movement
	Bubble_FOR (b) {
		// count number of parts in group
		int count=0;
		for (Bubble* d=b; d<Bubble_next && d->group==b->group; d++)
			count++;
		// calculate center (average position) of bubble
		Point center = {0,0};
		for (Bubble* d=b; d<b+count; d++)
			center.xy += d->pos.xy;
		center.xy /= count;
		// pull bubble parts towards center
		real targetRadius = count*(Bubble_SPACING/(PI+PI)*2); //PI+PI is slightly less than TAU
		for (Bubble* d=b; d<b+count; d++) {
			Point diff;
			diff.xy = center.xy - d->pos.xy;
			real dist = Vec_fastNormalize(&diff);
			if (dist!=0)
				d->pos.xy -= diff.xy*(targetRadius-dist)*0.1;
		}
		// pull bubble parts towards each other
		for (Bubble* d=b; d<b+count-1; d++)
			pull(d, d+1);
		pull(b+count-1, b);
		
		b += count-1;
	}
	// check collisions
	Bubble* first = Bubble_bubbles;
	Bubble_FOR (b) {
		// keep track of first part in group
		if (b->group != first->group)
			first = b;
		// check for collision with anything other than soapy
		Dot* part = Dot_EMPTY;
		if (b->pos.x>=0 && b->pos.x<WIDTH && b->pos.y>=0 && b->pos.y<HEIGHT) {
			part = *Dot_pos2(b->pos);
			if (part<=Dot_BGFAN) continue;
			if (part>=Dot_0 && part->type==Elem_SOAPY) continue;
		}

		// (collision was found)
		
		int type = part>=Dot_0 ? part->type : Elem_STEAM;
		// find end of group
		Bubble *end;
		for (end=b; end<Bubble_next; end++) {
			if (end->group!=first->group)
				break;
		}
		// create lines
		Bubble* d;
		for (d=first; d<end-1; d++)
			partLine(d->pos, (d+1)->pos, type);
		partLine(d->pos, first->pos, type);
		
		Bubble_remove(first, end);
		// next
		b = first-1;
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
	Block* cell = Block_at(x, y);
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
	if (Bubble_next >= Bubble_END) return;
	*Bubble_next = (Bubble){
		.pos = {x,y},
		.group = nextGroup,
		.held = false,
	};
	Bubble_next++;
}

void Bubble_reset(void) {
	Bubble_next = Bubble_bubbles;
	nextGroup = 0;
}
