//
// X11 flavor
//

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "input.h"

extern Color grp[HEIGHT][WIDTH];

Display* D;
Window win;
XImage* ximage;

void Platform_init(void) {
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
}

void Platform_redraw(void) {
	XPutImage(D, win, DefaultGC(D, 0), ximage, 8, 8, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

extern int Platform_mouseX, Platform_mouseY;
extern bool Platform_keys[256];

static void processEvent(void) {
	static union {
		XEvent event;
		XMotionEvent motion;
		XKeyEvent key;
	} ev;
	XNextEvent(D, &ev.event);
	switch (ev.event.type) {
	case Expose:
		Platform_redraw();
		break;
	case ButtonPress:;
	case ButtonRelease:;
		puts("E");
		break;
	case MotionNotify:;
		Platform_mouseX = ev.motion.x;
		Platform_mouseY = ev.motion.y;
		break;
	case KeyPress:;
	case KeyRelease:;
		//int i;
		//for (i=0; ; i++) {
		KeySym key = XLookupKeysym(&ev.key, 0);
		if (!key) break;
		int code = -1;
		switch (key) {
		when(XK_space): code = ' ';
		when(XK_w): case XK_W: code = 'W';
		when(XK_a): case XK_A: code = 'A';
		when(XK_s): case XK_S: code = 'S';
		when(XK_d): case XK_D: code = 'D';
		when(XK_Up): code = 38;
		when(XK_Down): code = 40;
		when(XK_Left): code = 37;
		when(XK_Right): code = 39;
		when(XK_Return): code = 13;
		otherwise:;
			char* sym_name = XKeysymToString(key);
			printf("Got keysym: (%s)\n", sym_name);
		}
		if (code >= 0)
			Platform_keys[code] = ev.event.type == KeyPress;
		//}
	}
}

void Platform_frame(void);

void Platform_loop(void) {
	while (1) {
		Platform_frame();
		processEvent();
	}
}
