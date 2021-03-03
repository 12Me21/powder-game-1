#include <stdbool.h>
#include "common.h"
#include "sim.h"
#include "menu.h"
#include "bg.h"

// todo: full reset function
void Sim_reset(bool a) {
	int x,y;
	for (y=0; y<HEIGHT/4; y++) {
		for (x=0; x<WIDTH/4; x++) {
			Part_blocks[y][x] = (Block){
				.vel={0,0},
				.vel2={0,0},
				.pres=0,
				.pres2=0,
				.block=0,
			};
		}
	}
	if (!a) {
		// todo: make sure all the right blocks are filled here
		for (x=1;x<(W+8)/4;x++) {
			Part_blocks[2][x].block = 1;
			Part_blocks[(H+8)/4-1][x].block = 1;
		}
		for (y=1;y<(H+8)/4;y++) {
			Part_blocks[y][2].block = 1;
			Part_blocks[y][(W+8)/4-1].block = 1;
		}
	}
	Pen_oldx = Pen_oldy = Pen_x = Pen_y = 8;
	Pen_dir = (Vector){0,0};
	Part_next = Part_0;
	for (y=0; y<HEIGHT; y++)
		for (x=0; x<WIDTH; x++)
			Part_at[y][x] = Part_EMPTY;
	Wheel_next = Wheel_wheels;
	Bubble_next = Bubble_bubbles;
	Qd = 0;

	Entity_next = entitys;
	for (Ball* b=balls; b<Ball_END; b++)
		b->used = false;
	if (!a) {
		for (y=0; y<HEIGHT; y++)
			for (x=0; x<WIDTH; x++)
				if (Part_blocks[y/4][x/4].block==1)
					Part_at[y][x] = Part_BLOCK;
	}
	Bg_reset();
}
