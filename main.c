//https://www.linuxquestions.org/questions/programming-9/how-to-draw-color-images-with-xlib-339366/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <X11/Xlib.h>

#include "common.h"
#include "input.h"
#include "draw.h"
#include "menu.h"
#include "part.h"
#include "save.h"
#include "bg.h"
#include "entity.h"

extern bool Menu_numberMenu;

// we are assuming that colors are represented in a normal format etc.
Color grp[HEIGHT][WIDTH] = {0};
Display* D;
Window win;
XImage* ximage;

void redraw() {
	XPutImage(D, win, DefaultGC(D, 0), ximage, 8, 8, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void render() {
	Menu_render();
	Bg_render();
	Part_render();
	Entity_render();
	Draw_rectangle(Pen_x,Pen_y,1,1,grp[Pen_y][Pen_x]^0xFFFFFF);
}

void frame() {
	Input_update();
	render();
	redraw();
}

void setPixel(int x, int y, int color) {
	grp[y][x] = color;
}

void processEvent(void) {
	XEvent ev;
	XNextEvent(D, &ev);
	switch (ev.type) {
	case Expose:
		redraw();
		break;
	case ButtonPress:;
	case ButtonRelease:;
		puts("E");
	case MotionNotify:;
		break;
	case KeyPress:;
	case KeyRelease:;
		KeySym key = XLookupKeysym((XKeyEvent*)&ev, 0);
		char* sym_name = XKeysymToString(key);
		printf("Got keysym: (%s)\n", sym_name);
	}
	frame();
}

int main(int argc, char** argv) {
	D = XOpenDisplay(NULL);
	Visual* visual = DefaultVisual(D, 0);
	win = XCreateSimpleWindow(D, RootWindow(D, 0), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 0, 0);
	if (visual->class!=TrueColor) {
		fprintf(stderr, "Cannot handle non true color visual ...\n");
		exit(1);
	}
	ximage = XCreateImage(D, visual, 24, ZPixmap, 0, (char*)grp, WIDTH, HEIGHT, 32, 0);
	XSelectInput(D, win, ButtonPressMask|ButtonReleaseMask|ExposureMask|KeyPressMask|KeyReleaseMask|PointerMotionMask);
	XMapWindow(D, win);
	Draw_init();
	Load_test();
	render();
	while (1)
		processEvent();
}
