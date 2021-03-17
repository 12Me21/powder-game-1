#pragma once
#include <stdio.h>
#include "common.h"

long Platform_nanosec(void);
void Platform_main(int argc, void** argv);

FILE* Platform_openWrite(void* name);
FILE* Platform_openRead(void* name);
void* Platform_selectFile(int mode);

typedef struct Platform_Bitmap {
	axis width;
	axis height;
	void* data;
} Platform_Bitmap;

typedef struct Platform_Window {
	long data;
} Platform_Window;

void Platform_createWindow(axis width, axis height, char* title);

Platform_Bitmap Platform_createBitmap(Color* data, axis width, axis height);
void Platform_drawBitmap(Platform_Bitmap bitmap, int dx, int dy, int srcx, int srcy, int w, int h);

void Platform_redraw(void);
