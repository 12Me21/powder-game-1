#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "input.h"
#include "save.h"
#include "vector.h"

extern Color grp[HEIGHT][WIDTH];

extern int Platform_mouseX, Platform_mouseY;
extern int Platform_mouseLeft, Platform_mouseRight, Platform_mouseMiddle;
extern bool Platform_keys[256];

void Platform_frame(void);


Display* D;
Window win;
XImage* ximage;

long Platform_millisec(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	return (long)ts.tv_sec * 1000L + ts.tv_nsec/1000000;
}

void Platform_redraw(void) {
	XPutImage(D, win, DefaultGC(D, 0), ximage, 8, 8, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

static void processEvent(void) {
	while (1) {
		static union {
			XEvent event;
			XMotionEvent motion;
			XKeyEvent key;
			XButtonEvent button;
		} ev;
		Bool t = XCheckWindowEvent(D, win, (long)-1, &ev.event);
		if (!t)
			return;
		switch (ev.event.type) {
		case Expose:
			Platform_redraw();
			break;
		case ButtonPress:;
		case ButtonRelease:;
			if (ev.button.button == Button1)
				Platform_mouseLeft = ev.event.type == ButtonPress;
			if (ev.button.button == Button3)
				Platform_mouseRight = ev.event.type == ButtonPress;;
			if (ev.button.button == Button2)
				Platform_mouseMiddle = ev.event.type == ButtonPress;;
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
}

int main(int argc, char** argv) {
	srand(time(NULL));///todo put this in windows
	D = XOpenDisplay(NULL);
	Visual* visual = DefaultVisual(D, 0);
	if (visual->class!=TrueColor) {
		fprintf(stderr, "Cannot handle non true color visual ...\n");
		exit(1);
	}

	// Create window
	win = XCreateSimpleWindow(D, RootWindow(D, 0), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 0, 0);
	XSelectInput(D, win, ButtonPressMask|ButtonReleaseMask|ExposureMask|KeyPressMask|KeyReleaseMask|PointerMotionMask);
	XMapWindow(D, win);

	// Lock window size
	XSizeHints* shints = XAllocSizeHints();
	shints->flags = PMinSize|PMaxSize;
	shints->min_width = shints->max_width = WINDOW_WIDTH;
	shints->min_height = shints->max_height = WINDOW_HEIGHT;
	XSetWMNormalHints(D, win, shints);
	XFree(shints);

	// Set icon
	Pixmap pixmap = 0;
	Pixmap mask = 0;
#include "icon.xpm"
	XpmCreatePixmapFromData(D, DefaultRootWindow(D), icon, &pixmap, &mask, 0);
	XWMHints* hints = XGetWMHints(D, win) ?: XAllocWMHints();
	hints->flags |= IconPixmapHint;
	hints->icon_pixmap = pixmap;
	XSetWMHints(D, win, hints);
	XFree(hints);

	// create image
	ximage = XCreateImage(D, visual, 24, ZPixmap, 0, (char*)grp, WIDTH, HEIGHT, 32, 0);
	
	// start
	Load_test();
	while (1) {
		Platform_frame();
		Platform_redraw();
		processEvent();
	}
}
