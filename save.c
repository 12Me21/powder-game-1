#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "menu.h"
#include "part.h"
#include "elements.h"
#include "platform.h"
#include "vector.h"
#include "entity.h"
#include "ball.h"
#include "cell.h"
#include "reset.h"


static int number(char x) {
	if (x>='0' || x<='9')
		return x-48;
	return -1;
}

int Save_dataArray[W*H]; //todo:
int Save_metaArray[W*H];

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
	int e[W*H], eIndex=0, qIndex=1;
	while (!feof(stream)) {
		int q_size=1;
		char a = fgetc(stream);
		char b = fgetc(stream);
		if (a==EOF || b==EOF)
			break;
		int q_read = base64[a]<<6 | base64[b];
		if (q_read>0) {
			int i;
			for (i=0; i<qSize[q_read]; i++)
				e[eIndex++] = q[q_read][i];
			q_size = qSize[q_read]+1;
		}
		a = fgetc(stream);
		if (a==EOF)
			break;
		e[eIndex++] = base64[a];
		if (qIndex<0x1000) {
			if (q[qIndex]) {
				free(q[qIndex]);
				q[qIndex] = NULL;
			}
			q[qIndex] = malloc(sizeof(int)*q_size);
			qSize[qIndex] = q_size;
			int i;
			for (i=0; i<q_size; i++)
				q[qIndex][i]=e[eIndex-q_size+i];
			qIndex++;
		}
	}
	int i;
	for (i=0; i<0x1000; i++)
		if (q[i])
			free(q[i]);
	e[eIndex++] = 0;
	e[eIndex++] = 0;
	int a=0;
	int d;
	for (d=0; d<W*H; ) {
		int b = e[a++];
		if (b==Elem_FAN || b==Elem_FIREWORKS || b==Elem_BOX || b==Elem_SAVE_BALL) {
			Save_dataArray[d] = b;
			Save_metaArray[d++] = e[a++];
		} else if (b==Elem_PLAYER2) {
			Save_dataArray[d] = Elem_PLAYER;
			Save_metaArray[d++] = e[a++];
		} else if (e[a]<48) {
			Save_dataArray[d++] = b;
		} else {
			//1 or 2 digits in hexadecimal
			int w = e[a++]-48; //low nibble
			if (e[a]>=48) //if next digit
				w += (e[a++]-48)<<4; //get high nibble
			int i;
			for (i=0; i<w; i++)
				Save_dataArray[d++] = b;
		}
	}
}

void load1(void) {
	int total=0;
	Sim_reset(true);
	int x,y;
	for (y=0; y<H; y++) {
		for (x=0; x<W; x++) {
			int xy = W*y+x;
			int t = Save_dataArray[xy];
			switch (t) {
			when(0):
				xy=(y+8)*WIDTH+(x+8);
				Part_at[y+8][x+8] = Part_EMPTY;
			when(Elem_BLOCK):
				Part_blocks[y/4+2][x/4+2].block = 1;
				Part_at[y+8][x+8] = Part_BLOCK;
			when(Elem_WHEEL):
				//Wheels.create(x+8,y+8);
			when(Elem_WHEEL2):
				//Wheels.create(x+8,y+8);
			when(Elem_BOX):
				Entity_create(x+8,y+8,Elem_BOX, Save_metaArray[xy]);
			when(Elem_PLAYER):
				Entity_create(x+8,y+8,Elem_PLAYER2, Save_metaArray[xy]);
			when(Elem_SAVE_BALL):
				Ball_create(x+8, y+8, Save_metaArray[xy]);
			otherwise:
				total++;
				if (Menu_dotLimit<=0 && Part_LIMITS[0]<total)
					Menu_dotLimit=1;
				if(Menu_dotLimit<=1 && Part_LIMITS[1]<total)
					Menu_dotLimit=2;
				Part* a = Part_create(x+8, y+8, t);
				int meta = Save_metaArray[xy];
				if (t == Elem_FAN) {
					a->vel = (Point){0.1*(real)cos(meta*PI/32), 0.1*-(real)sin(meta*PI/32)};
					Part_at[y+8][x+8] = Part_BGFAN;
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
	memset(Save_dataArray, 0, sizeof(Save_dataArray));
	memset(Save_metaArray, 0, sizeof(Save_metaArray));
	// blocks
	int x,y;
	for (y=0;y<H;y++)
		for (x=0;x<W;x++)
			if (Part_blocks[(int)y/4+2][(int)x/4+2].block == 1)
				Save_dataArray[W*y+x]=Elem_BLOCK;
	// particles
	Part* p;
	for (p=Part_0; p<Part_next; p++) {
		int x = p->pos.x;
		int y = p->pos.y;
		if (onscreen(x,y)) {
			int xy=W*(y-8)+(x-8); //w must be 400 to be compatible with vanilla pg
			Save_dataArray[xy] = p->type;
			if (p->type == Elem_FAN) {
				Save_metaArray[xy] = wrap(64*Vec_angle(p->vel)/TAU, 63);
			} else if (p->type == Elem_FIREWORKS) {
				Save_metaArray[xy] = p->meta%100;
				//fix thunder saving badly :(
			} else if (p->type==Elem_THUNDER){
				if ((p->meta&0xFFFC)==6000)
					Save_dataArray[xy] = Elem_METAL;
				else if (p->meta >= 7000)
					Save_dataArray[xy] = Elem_GLASS;
				else if ((p->meta&0xFFFC)==6100)
					Save_dataArray[xy] = Elem_MERCURY;
			}
		}
	}
}
