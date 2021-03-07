#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "input.h"
#include "save.h"
#include "draw.h"
#include "vector.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <X11/keysym.h>

void Platform_frame(void);
void Platform_main(int argc, char** argv);

Display* D;
Window win;
XImage* simImage;
XImage* menuImage;

long Platform_nanosec(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	return (long)ts.tv_sec * 1000000000L + ts.tv_nsec; // ONE MILLION
}

void redraw(void) {
	XPutImage(D, win, DefaultGC(D, 0), simImage, 0,0, 0,0, W,H);
	XPutImage(D, win, DefaultGC(D, 0), menuImage, 0,0, 0,H, W,MENU_HEIGHT);
}

Atom wmDeleteMessage;

static bool processEvent(void) {
	while (1) {
		static union {
			XEvent event;
			XMotionEvent motion;
			XKeyEvent key;
			XButtonEvent button;
			XClientMessageEvent clientMessage;
		} ev;
		Bool t = XCheckWindowEvent(D, win, ~0L, &ev.event);
		if (!t)
			return true;
		switch (ev.event.type) {
			//case ClientMessage:
			//			if ((Atom)ev.clientMessage.data.l[0] == wmDeleteMessage)
			//				return false;
			//			break;
		case Expose:
			redraw();
			break;
		case ButtonPress:;
		case ButtonRelease:;
			ButtonState* btn = NULL;
			if (ev.button.button == Button1)
				btn = &mouse.left;
			if (ev.button.button == Button2)
				btn = &mouse.middle;
			if (ev.button.button == Button3)
				btn = &mouse.right;
			if (btn) {
				btn->heldNow = ev.event.type==ButtonPress;
				if (ev.event.type==ButtonPress)
					btn->gotPress = true;
				else
					btn->gotRelease = true;
			}
			break;
		case MotionNotify:;
			mouse.pos = (Point){ev.motion.x, ev.motion.y};
			break;
		case KeyPress:;
		case KeyRelease:;
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
			if (code >= 0) {
				Keys[code].heldNow = ev.event.type == KeyPress;
				if (ev.event.type == KeyPress)
					Keys[code].gotPress = true;
				else
					Keys[code].gotRelease = true;
			}
		}
	}
}

int main(int argc, char** argv) {
	srand(time(NULL));///todo put this in windows
	D = XOpenDisplay(NULL);
	Visual* visual = DefaultVisual(D, 0);
	if (visual->class!=TrueColor) {
		fprintf(stderr, "Cannot handle non true color visual ...\n");
		XCloseDisplay(D);
		exit(1);
	}

	//XFontStruct* font = XLoadQueryFont(D, "serif")

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

	// this refers to center portion of grp (without the 8px edge regions)
	simImage = XCreateImage(D, visual, 24, ZPixmap, 0, (char*)&grp[8][8], W,H, 32, WIDTH*4);
	// menu
	menuImage = XCreateImage(D, visual, 24, ZPixmap, 0, (char*)Menu_grp, W,MENU_HEIGHT, 32, 0);

	//wmDeleteMessage = XInternAtom(D, "WM_DELETE_WINDOW", False);
	//XSetWMProtocols(D, win, &wmDeleteMessage, 1);
	
	// start
	Platform_main(argc, argv);
	Platform_frame();
	redraw();
	while (processEvent()) {
		Platform_frame();
		redraw();
	}
}

FILE* Platform_fopen(const void* name) {
	return fopen((const char*)name, "r");
}
