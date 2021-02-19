//https://www.linuxquestions.org/questions/programming-9/how-to-draw-color-images-with-xlib-339366/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <X11/Xlib.h>

#define WINDOW_WIDTH 416
#define WINDOW_HEIGHT 464

typedef uint32_t Color;

// we are assuming that colors are represented in a normal format etc.
Color grp[WINDOW_HEIGHT][WINDOW_WIDTH] = {0};
Display* D;
Window win;
XImage* ximage;

void redraw() {
	XPutImage(D, win, DefaultGC(D, 0), ximage, 0, 0, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
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
		int i;
		for (i=0;i<10000;i++) {
			setPixel(rand()%WINDOW_WIDTH,rand()%WINDOW_HEIGHT,0xFFFF0080);
		}
		redraw();
		//exit(0);
	}
}

int main(int argc, char** argv) {
	D = XOpenDisplay(NULL);
	Visual* visual = DefaultVisual(D, 0);
	win = XCreateSimpleWindow(D, RootWindow(D, 0), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 0, 0);
	if (visual->class!=TrueColor) {
		fprintf(stderr, "Cannot handle non true color visual ...\n");
		exit(1);
	}
	ximage = XCreateImage(D, visual, 24, ZPixmap, 0, (char*)grp, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0);
	XSelectInput(D, win, ButtonPressMask|ExposureMask);
	XMapWindow(D, win);
	while (1) {
		
		processEvent();
	}
}
