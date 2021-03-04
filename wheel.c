#include <math.h>
#include "menu.h"
#include "vector.h"
#include "input.h"
#include "elements.h"
#include "part.h"
#include "draw.h"
#include "bg.h"
#include "wheel.h"

Wheel Wheel_wheels[Wheel_MAX];
Wheel* const Wheel_end = &Wheel_wheels[Wheel_MAX];
Wheel* Wheel_next = Wheel_wheels;

extern const char Wheel_frames[16][32][32];

void Wheel_update(void) {
	if (Menu_dragging) {
		for (Wheel* w=Wheel_wheels;w<Wheel_end;w++) {
			Point d = {Pen_x-w->x, Pen_y-w->y};
			if (Vec_fastDist(d)<16)
				w->vel -= d.x*(Pen_y-Pen_oldy)-d.y*(Pen_x-Pen_oldx);
		}
	}
	for (Wheel* w=Wheel_wheels; w<Wheel_next; w++) {
		const char (*frame)[32] = Wheel_frames[(int)w->angle];
		for (axis y=0; y<32; y++) {
			for (axis x=0; x<32; x++) {
				if (frame[y][x]=='.') {
					Block* cell = &Part_blocks[(w->y+y-16)>>2][(w->x+x-16)];
					real wind = cell->vel.x*(y-15.5) - cell->vel.y*(x-15.5);
					w->vel += 0.0001*wind;
				}
				Part* p = Part_at[w->y+y-16][w->x+x-16];
				if (p>=Part_0 && frame[y][x]==' ' && y!=31 && frame[y+1][x]=='.') {
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
			typedef struct WheelPart {
				Part* part;
				real x,y;
			} WheelPart;

			WheelPart parts[1024];
			WheelPart* next = parts;

			frame = Wheel_frames[(int)floor(w->angle)];
			for (axis y=0; y<32; y++) {
				for (axis x=0; x<32; x++) {
					if (frame[y][x]==' ') {
						Part* p = Part_at[w->y+y-16][w->x+x-16];
						if (p>=Part_0)
							*next++ = (WheelPart){p, (y-15.5)*g*0.1, -(x-15.5)*g*0.1};
					}
				}
			}
			for (WheelPart* wp=parts; wp<next; wp++) {
				Part* part = wp->part;
				*Part_pos2(part->pos) = Part_EMPTY;
				Part* p = *Part_pos(part->pos.x+wp->x, part->pos.y);
				if (p<Part_BLOCK)
					part->pos.x += wp->x;
				p = *Part_pos(part->pos.x, part->pos.y+wp->y);
				if (p<Part_BLOCK)
					part->pos.y += wp->y;
				*Part_pos2(part->pos) = part;
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
						part->pumpType = 0;
					}
				}
			}
		}
	}
}

void Wheel_render(void) {
	Color color = Menu_bgMode==Bg_SILUET ? 0 : 0xB0A090;
	for (Wheel* w=Wheel_wheels; w<Wheel_next; w++) {
		const char (*frame)[32] = Wheel_frames[(int)floor(w->angle)];
		for (axis y=0;y<32;y++) {
			for (axis x=0;x<32;x++)
				if (frame[y][x]=='.')
					grp[w->y+y-16][w->x+x-16] = color;
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
	for (Wheel* w=Wheel_wheels; w<Wheel_next; w++) {
		if (x==w->x && y==w->y)
			return;
	}
	if (Wheel_next < Wheel_end) {
		*Wheel_next = (Wheel){
			.x = x,
			.y = y,
			.angle = 0.5,
			.vel = 0,
		};
		Wheel_next++;
	}
}
