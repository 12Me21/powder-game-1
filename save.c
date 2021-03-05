#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "platform.h"
#include "sim.h"
#include "menu.h"
#include "elements.h"
#include "vector.h"
#include "reset.h"
#include "save.h"

static int number(char x) {
	if (x>='0' || x<='9')
		return x-48;
	return -1;
}

SavePixel Save_data[H][W];

void loadSaveFile(FILE* stream) {
	const char base64[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,62,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0};
	int version = number(fgetc(stream));
	
	int hsize;
	if (version==0)
		hsize = 8;
	else if (version>=1)
		hsize = 16;
	char data[hsize];
	fread(&data[1], 1, hsize-1, stream);
	
	char* bgmode_str = "0123456789:;ABCDEF";
	char* index = strchr(bgmode_str, data[2]);
	int bgmode=-1;
	if (bgmode_str)
		bgmode = index-bgmode_str;
	if (bgmode==0)
		Menu_bgMode = 2;
	else if (bgmode!=-1)
		Menu_bgMode = bgmode-1;
	Menu_dotLimit = number(data[3]);
	Menu_gridSize = number(data[4]);
	Menu_gameSpeed = number(data[5]);
	Menu_edgeMode = number(data[6]);
	if (version==0)
		Menu_carefully = 100;
	else if (version>=1)
		Menu_carefully = base64[data[8]] | base64[data[9]]<<6;

	int* q[0x1000] = {0};
	int qSize[0x1000] = {0};
	int e[W*H];
	int* ep = &e[0];
	char chrs[3];
	for (int qIndex=1; !feof(stream); qIndex++) {
		// read 3 chars.
		if (fread(chrs, 1, 3, stream) != 3)
			break;
		int q_read = base64[chrs[0]]<<6 | base64[chrs[1]];

		// copy items from `qSize[q_read]` to `e`
		int length = 0;
		if (q_read) {
			length = qSize[q_read];
			ep = mempcpy(ep, q[q_read], length*sizeof(int));
		}
		// push 1 char to `e`
		*ep++ = base64[chrs[2]];
		length++;
		
		if (qIndex<0x1000) {
			// copy the last `length` items from e to q[qindex]
			q[qIndex] = memcpy(
				alloca(sizeof(int)*length),
				ep-length,
				sizeof(int)*length
			);
			qSize[qIndex] = length;
		}
	}
	*ep++ = 0;
	*ep++ = 0;
	
	ep = e;
	for (int d=0; d<W*H; ) {
		int b = *ep++;
		if (b==Elem_FAN || b==Elem_FIREWORKS || b==Elem_BOX || b==Elem_SAVE_BALL) {
			Save_data[0][d++] = (SavePixel){b, *ep++};
		} else if (b==Elem_PLAYER2) {
			Save_data[0][d++] = (SavePixel){Elem_PLAYER, *ep++};
		} else if (*ep<48) {
			Save_data[0][d++].type = b;
		} else {
			//1 or 2 digits in hexadecimal
			int w = *ep++ - 48; //low nibble
			if (*ep>=48) //if next digit
				w += (*ep++ - 48)<<4; //get high nibble
			// run length encoding
			for (int i=0; i<w; i++)
				Save_data[0][d++].type = b;
		}
	}
}

void load1(void) {
	int total=0;
	Sim_reset(true);
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
			int t = Save_data[y][x].type;
			int sx=x+8, sy=y+8;
			switch (t) {
			when(0):;
				Part_at[sy][sx] = Part_EMPTY;
			when(Elem_BLOCK):;
				Part_blocks[y/4+2][x/4+2].block = 1;
				Part_at[sy][sx] = Part_BLOCK;
			when(Elem_FIGHTER):;
				//Wheels.create(sx,sy);
			when(Elem_WHEEL):;
				//Wheels.create(sx,sy);
			when(Elem_BOX):;
				Entity_create(sx,sy,Elem_BOX, Save_data[y][x].meta);
			when(Elem_PLAYER):;
				Entity_create(sx,sy,Elem_PLAYER2, Save_data[y][x].meta);
			when(Elem_SAVE_BALL):;
				Ball_create(sx, sy, Save_data[y][x].meta);
			otherwise:
				total++;
				if (Menu_dotLimit<=0 && Part_LIMITS[0]<total)
					Menu_dotLimit=1;
				if(Menu_dotLimit<=1 && Part_LIMITS[1]<total)
					Menu_dotLimit=2;
				Part* a = Part_create(sx, sy, t);
				int meta = Save_data[y][x].meta;
				if (t == Elem_FAN) {
					a->vel = (Point){0.1*(real)cos(meta*PI/32), 0.1*-(real)sin(meta*PI/32)};
					Part_at[sy][sx] = Part_BGFAN;
				} else if (t == Elem_FIREWORKS)
					a->meta = meta;
			}
		}
	}
	Part_shuffle();
}

void Save_Load_test(void* filename) {
	FILE* f = Platform_fopen(filename);
	if (f) {
		loadSaveFile(f);
		load1();
	}
}

static bool onscreen(int x, int y){
	return x>=8 && x<W+8 && y>=8 && y<H+8;
}

static int wrap(int a, int b) {
	if (a<0)
		return b;
	if (a>b)
		return 0;
	return a;
}

void Save_save1(void) {
	memset(Save_data, 0, sizeof(Save_data));
	// blocks
	for (int y=0;y<H;y++)
		for (int x=0;x<W;x++)
			if (Part_blocks[(int)y/4+2][(int)x/4+2].block == 1)
				Save_data[y][x].type=Elem_BLOCK;
	// particles
	for (Part* p=Part_0; p<Part_next; p++) {
		int x = p->pos.x;
		int y = p->pos.y;
		if (onscreen(x,y)) {
			SavePixel* px = &Save_data[y-8][x-8];
			px->type = p->type;
			if (p->type == Elem_FAN) {
				px->meta = wrap(64*Vec_angle(p->vel)/TAU, 63);
			} else if (p->type == Elem_FIREWORKS) {
				px->meta = p->meta%100;
				//fix thunder saving badly :(
			} else if (p->type==Elem_THUNDER){
				if ((p->meta&0xFFFC)==6000)
					px->type = Elem_METAL;
				else if (p->meta >= 7000)
					px->type = Elem_GLASS;
				else if ((p->meta&0xFFFC)==6100)
					px->type = Elem_MERCURY;
			}
		}
	}
}
