#include <math.h>
#include "menu.h"
#include "vector.h"
#include "random.h"
#include "input.h"
#include "elements.h"
#include "dot.h"
#include "wheel.h"
#include "save.h"

Wheel Wheel_wheels[Wheel_MAX];
Wheel* const Wheel_END = &Wheel_wheels[Wheel_MAX];
Wheel* Wheel_next = Wheel_wheels;

extern const char Wheel_frames[16][32][32];

void Wheel_update(void) {
	if (Menu_dragging) {
		Wheel_FOR (w) {
			Point d = {Pen_x-w->x, Pen_y-w->y};
			if (Vec_fastDist(d)<16)
				w->vel -= d.x*(Pen_y-Pen_oldy)-d.y*(Pen_x-Pen_oldx);
		}
	}
	Wheel_FOR (w) {
		const char (*frame)[32] = Wheel_frames[(int)w->angle];
		for (axis y=0; y<32; y++) {
			for (axis x=0; x<32; x++) {
				if (frame[y][x]=='.') {
					Block* cell = Block_at(w->x+x-16, w->y+y-16);
					real wind = cell->vel.x*(y-15.5) - cell->vel.y*(x-15.5);
					w->vel += 0.0001*wind;
				}
				Dot* p = Dot_at[w->y+y-16][w->x+x-16];
				if (p>=Dot_0 && frame[y][x]==' ' && y!=31 && frame[y+1][x]=='.') {
					real weight = 0*(y-15.5)-1*(x-15.5);
					w->vel += weight*ELEMENTS[p->type].wheelWeight*0.0001;
				}
			}
		}
		w->vel *= 0.99;
		w->vel = clamp(w->vel, -2, 2);
		real g = (int)(w->angle+16);
		w->angle += w->vel;
		g = (int)(w->angle+16)-g;
		if (w->angle<0)
			w->angle += 16;
		if (w->angle>=16)
			w->angle -= 16;
		if (g) {
			typedef struct WheelDot {
				Dot* part;
				real x,y;
			} WheelDot;

			WheelDot parts[1024];
			WheelDot* next = parts;

			frame = Wheel_frames[(int)floor(w->angle)];
			for (axis y=0; y<32; y++) {
				for (axis x=0; x<32; x++) {
					if (frame[y][x]==' ') {
						Dot* p = Dot_at[w->y+y-16][w->x+x-16];
						if (p>=Dot_0)
							*next++ = (WheelDot){p, (y-15.5)*g*0.1, -(x-15.5)*g*0.1};
					}
				}
			}
			for (WheelDot* wp=parts; wp<next; wp++) {
				Dot* part = wp->part;
				*Dot_pos2(part->pos) = Dot_EMPTY;
				Dot* p = *Dot_pos(part->pos.x+wp->x, part->pos.y);
				if (p<Dot_BLOCK)
					part->pos.x += wp->x;
				p = *Dot_pos(part->pos.x, part->pos.y+wp->y);
				if (p<Dot_BLOCK)
					part->pos.y += wp->y;
				*Dot_pos2(part->pos) = part;
				switch (part->type) {
				when(Elem_WOOD):;
					if (Rnd_perchance(20))
						part->type = Elem_POWDER;
				when(Elem_ICE):;
					part->type = Elem_SNOW;
				when(Elem_FUSE):;
					part->type = Elem_GUNPOWDER;
				when(Elem_PUMP):;
					if (Rnd_perchance(10)) {
						part->type = Elem_SPARK;
						part->charge = 0;
					}
				}
			}
		}
	}
}

void Wheel_remove(Wheel* w) {
	if (w != Wheel_next) {
		Wheel_next--;
		*w = *Wheel_next;
	}
}

void Wheel_create(axis x, axis y) {
	Wheel_FOR (w) {
		if (x==w->x && y==w->y)
			return;
	}
	if (Wheel_next >= Wheel_END) return;
	*Wheel_next = (Wheel){
		.x = x,
		.y = y,
		.angle = 0.5,
		.vel = 0,
	};
	Wheel_next++;
}

void Wheel_update1(void) {
	// remove old wheel parts from grid
	Wheel_FOR (w) {
		for (axis y=0; y<32; y++)
			for (axis x=0; x<32; x++) {
				Dot** p = Dot_pos(w->x-16+x, w->y-16+y);
				if (*p == Dot_WHEEL)
					*p = Dot_EMPTY;
			}
	}
	// add new ones
	Wheel_FOR (w) {
		const char (*frame)[32] = Wheel_frames[(int)w->angle];
		for (axis y=0; y<32; y++)
			for (axis x=0; x<32; x++) {
				if (frame[y][x]=='.') {
					Dot** p = Dot_pos(w->x-16+x, w->y-16+y);
					if (*p <= Dot_BGFAN)
						*p = Dot_WHEEL;
				}
			}
	}
}

void Wheel_save(SavePixel save[H][W]) {
	Wheel_FOR (w) {
		save[w->y-8][w->x-8] = (SavePixel){Elem_WHEEL, 0};
	}
}

void Wheel_reset(void) {
	Wheel_next = Wheel_wheels;
}
