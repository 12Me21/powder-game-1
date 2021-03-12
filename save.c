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
int carefullyCreated2 = 0;
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
	else
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
		int type = *ep++;
		if (type==Elem_FAN || type==Elem_FIREWORKS || type==Elem_BOX || type==Elem_SAVE_BALL) {
			Save_data[0][d++] = (SavePixel){type, *ep++};
		} else if (type==Elem_PLAYER2) {
			Save_data[0][d++] = (SavePixel){Elem_PLAYER, *ep++};
		} else if (*ep<48) {
			Save_data[0][d++].type = type;
		} else { // run length encoded
			// 012345789:;<=>?
			int w = *ep++ - '0'; //low nibble
			if (*ep>='0') //if next digit
				w += (*ep++ - '0')<<4; //get high nibble
			for (int i=0; i<w; i++)
				Save_data[0][d++].type = type;
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
				Dot_at[sy][sx] = Dot_EMPTY;
			when(Elem_BLOCK):;
				Blocks[y/4+2][x/4+2].block = 1;
				Dot_at[sy][sx] = Dot_BLOCK;
			when(Elem_FIGHTER):;
				//Wheels.create(sx,sy);
			when(Elem_WHEEL):;
				//Wheels.create(sx,sy);
			when(Elem_BOX):;
				Object_create(sx,sy,Elem_BOX, Save_data[y][x].meta);
			when(Elem_PLAYER):;
				Object_create(sx,sy,Elem_PLAYER2, Save_data[y][x].meta);
			when(Elem_SAVE_BALL):;
				Ball_create(sx, sy, Save_data[y][x].meta);
			otherwise:
				total++;
				if (Menu_dotLimit<=0 && Dot_LIMITS[0]<total)
					Menu_dotLimit=1;
				if(Menu_dotLimit<=1 && Dot_LIMITS[1]<total)
					Menu_dotLimit=2;
				Dot* a = Dot_create(sx, sy, t);
				int meta = Save_data[y][x].meta;
				if (t == Elem_FAN) {
					a->vel = (Point){0.1*(real)cos(meta*PI/32), 0.1*-(real)sin(meta*PI/32)};
					Dot_at[sy][sx] = Dot_BGFAN;
				} else if (t == Elem_FIREWORKS)
					a->meta = meta;
			}
		}
	}
	Dot_shuffle();
}

void Save_Load_test(void* filename) {
	FILE* f = Platform_fopen(filename);
	if (f) {
		loadSaveFile(f);
		load1();
	}
}

bool Save_onscreen(axis x, axis y) {
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
#define DEFCALL(type) void type##_save(SavePixel save[H][W]); type##_save(Save_data);
	
	memset(Save_data, 0, sizeof(Save_data));
	DEFCALL(Block);
	DEFCALL(Dot);
	DEFCALL(Wheel);
	DEFCALL(Object);
	DEFCALL(Ball);
	//carefullycreated2=clamp(carefullycreated+100,0,4095);
}

/*void Save_makeThumbnail() {
	
  }*/

static int checksum(char* text) {
	int checksum = 0;
	int i=0;
	for (char* c=text; *c; c++)
		checksum += (int)*c*((i++ & 0xFF)+1);
	return checksum;
}

char* Save_string(SavePixel save[H][W]) {
	char data[W*H];
	char* d = data;
	for (int a=0; a<W*H; a++) {
		int type = save[0][a].type;
		if (type==Elem_FAN || type==Elem_FIREWORKS || type==Elem_BOX || type==Elem_SAVE_BALL) {
			*d++ = type;
			*d++ = save[0][a].meta;
		} else if (type==Elem_PLAYER) {
			*d++ = Elem_PLAYER2;
			*d++ = save[0][a].meta;
		} else {
			int run=1;
			*d++ = type;
			for (; a<W*H && run<255; a++) {
				if (save[0][a+1].type==type)
					run++;
				else
					break;
			}
			if (run>1) {
				if (run<0x10)
					*d++ = '0'+run;
				else {
					*d++ = '0'+(run & 0xF);
					*d++ = '0'+(run>>4);
				}
			}
		}
	}
	int dLen = d-data;
	const char base64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.*";
	char* fd = malloc(20*dLen+4);
	char* f = fd;
	*f++ = '1';
	*f++ = '0';
	*f++ = "0123456789:;ABCDEF"[Menu_bgMode+1];
	*f++ = '0'+Menu_dotLimit;
	*f++ = '0'+Menu_gridSize;
	*f++ = '0'+Menu_gameSpeed;
	*f++ = '0'+Menu_edgeMode;
	*f++ = '0';
	*f++ = base64[carefullyCreated2 & 0b111111];
	*f++ = base64[carefullyCreated2>>6 & 0b111111];
	*f++ = '0';
	*f++ = '0';
	*f++ = '0';
	*f++ = '0';
	*f++ = '0';
	*f++ = '0';
	int* q[0x1000] = {0};
	int qLen[0x1000] = {0};
	int w=1;
	int n=1;
	for (int a=0; a<dLen; a+=w) {
		int r=0;
		w=1;
		for (int y=1; y<n; y++) {
			if (qLen[y] == w) {
				for (int c=0; c<w; c++) {
					if (q[y][c]!=data[a+c])
						goto fail;
				}
				r = y;
				w++;
				if (a+w>=dLen)
					break;
			fail:;
			}
		}
		*f++ = base64[r>>6];
		*f++ = base64[r&0b111111];
		*f++ = base64[data[a+w-1]];
		if (n<0x1000) {
			qLen[n] = w;
			q[n] = alloca(sizeof(int)*w);
			memcpy(q[n], &data[a], sizeof(int)*w);
			n++;
		}
	}
	if (!f[-1]) //idk
		f[-1] = base64[0];
	*f = '\0'; //no inc
	int cs = checksum(fd);
	*f++ = 'a'+(cs & 0b1111);
	*f++ = 'A'+(cs>>4 & 0b1111);
	*f++ = '0'+(cs>>8 & 0b111);
	*f++ = '\0';
	return fd;
}
