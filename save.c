#include <stddef.h>
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

/*static inline void* memdupa(void* source, size_t length) {
	return memcpy(alloca(length), source, length);
	}*/

/*void loadSaveFile(FILE* stream) {
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

	// Decompressor

	struct {char* data; int length;} q[0x1000] = {0};
	char e[W*H];
	char* ep = &e[0];
	char chrs[3];
	int qIndex = 1;
	while (!feof(stream)) {
		// read 3 chars.
		if (fread(chrs, 1, 3, stream) != 3)
			break;
		// first 2 chars
		int q_read = base64[chrs[0]]<<6 | base64[chrs[1]];

		// copy items from `qSize[q_read]` to `e`
		int length = 0;
		if (q_read) {
			length = q[q_read].length;
			memmove(ep, q[q_read].data, length*sizeof(char));
			ep += length;
		}
		// push last char to `e`
		*ep++ = base64[chrs[2]];
		length++;
		
		if (qIndex<0x1000) {
			// copy the last `length` items from e to q[qindex]
			q[qIndex].data = ep-length;
			q[qIndex].length = length;
		}
		qIndex++;
	}
	*ep++ = 0;
	*ep++ = 0;

	// 
	
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
	}*/

void load1(void) {
	int total=0;
	Sim_reset(false);
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
			int t = Save_data[y][x].type;
			int sx=x+8, sy=y+8;
			switch (t) {
			when(0):;
				Dot_at[sy][sx] = Dot_EMPTY;
			when(Elem_BLOCK):;
				Block_at(sx,sy)->block = Block_BLOCK;
				Dot_at[sy][sx] = Dot_BLOCK;
			when(Elem_FIGHTER):;
				Object_create(sx,sy,0,0);
			when(Elem_WHEEL):;
				Wheel_create(sx,sy);
			when(Elem_BOX):;
				Object_create(sx,sy,Elem_BOX, Save_data[y][x].charge);
			when(Elem_PLAYER):;
				Object_create(sx,sy,Elem_PLAYER2, Save_data[y][x].charge);
			when(Elem_SAVE_BALL):;
				Ball_create(sx, sy, Save_data[y][x].charge);
			otherwise:
				total++;
				if (Menu_dotLimit<=0 && Dot_LIMITS[0]<total)
					Menu_dotLimit=1;
				if(Menu_dotLimit<=1 && Dot_LIMITS[1]<total)
					Menu_dotLimit=2;
				Dot* a = Dot_create(sx, sy, t);
				int charge = Save_data[y][x].charge;
				if (t == Elem_FAN) {
					a->vel = (Point){0.1f*(real)cos(charge*PI/32), 0.1f*-(real)sin(charge*PI/32)};
					Dot_at[sy][sx] = Dot_BGFAN;
				} else if (t == Elem_FIREWORKS)
					a->charge = charge;
			}
		}
	}
	Dot_shuffle();
}

/*void Save_Load_test(void* filename) {
	FILE* f = Platform_openRead(filename);
	if (f) {
		loadSaveFile(f);
		load1();
	}
	}*/

bool Save_onscreen(axis x, axis y) {
	return x>=8 && x<W+8 && y>=8 && y<H+8;
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

static char save_buffer[100000];

char* Save_string(SavePixel save[H][W]) {
	char data[W*H];
	char* d = data;
	for (int a=0; a<W*H; a++) {
		int type = save[0][a].type;
		if (type==Elem_FAN || type==Elem_FIREWORKS || type==Elem_BOX || type==Elem_SAVE_BALL) {
			*d++ = type;
			*d++ = save[0][a].charge;
		} else if (type==Elem_PLAYER) {
			*d++ = Elem_PLAYER2;
			*d++ = save[0][a].charge;
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
	char* fd = save_buffer;//malloc(2*dLen+4);
	char* f = fd;
	// write header
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
	// compress data
	struct {char* data; int length;} q[0x1000] = {0};
	int qNext=1;
	for (char* a=data; a<d;) {
		int r=0;
		int length=1;
		for (int y=1; y<qNext; y++) {
			if (q[y].length == length) {
				if (0==memcmp(q[y].data, a, length*sizeof(char))) {
					r = y;
					length++;
					if (a+length>=d)
						break;
				}
			}
		}
		*f++ = base64[r>>6];
		*f++ = base64[r&0b111111];
		*f++ = base64[a[length-1]];
		if (qNext<0x1000) {
			q[qNext].length = length;
			q[qNext].data = a;
			qNext++;
		}
		a+=length;
	}
	if (!f[-1]) {//idk
		f[-1] = base64[0];
	}
	*f = '\0'; //no inc
	// add checksum
	int cs = checksum(fd);
	*f++ = 'a'+(cs & 0b1111);
	*f++ = 'A'+(cs>>4 & 0b1111);
	*f++ = '0'+(cs>>8 & 0b111);
	*f++ = '\0';
	
	return fd;
}
