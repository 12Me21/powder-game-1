/*#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "input.h"
#include "platform.h"
#include "save.h"
#include "render/draw.h"
#include "vector.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <X11/keysym.h>

void Platform_frame(void);

Display* D;
Visual* visual;
Window win;

long Platform_nanosec(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	return (long)ts.tv_sec * 1000000000L + ts.tv_nsec; // ONE MILLION
}

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
		case Expose:
			Platform_redraw();
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
			when(XK_Return): code = '\r';
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

void Platform_createWindow(axis width, axis height, char* title) {
	win = XCreateSimpleWindow(D, RootWindow(D, 0), 0, 0, width, height, 1, 0, 0);
	XSelectInput(D, win, ButtonPressMask|ButtonReleaseMask|ExposureMask|KeyPressMask|KeyReleaseMask|PointerMotionMask);
	XMapWindow(D, win);

	// Lock window size
	XSizeHints* shints = XAllocSizeHints();
	shints->flags = PMinSize|PMaxSize;
	shints->min_width = shints->max_width = width;
	shints->min_height = shints->max_height = height;
	XSetWMNormalHints(D, win, shints);
	XFree(shints);

	XTextProperty t = {0};
	XStringListToTextProperty(&title, 1, &t); // heheh
	XSetWMName(D, win, &t);

	// Set icon (TODO)
	Pixmap pixmap = 0;
	Pixmap mask = 0;
#include "icon.xpm"
	XpmCreatePixmapFromData(D, DefaultRootWindow(D), icon, &pixmap, &mask, 0);
	XWMHints* hints = XGetWMHints(D, win) ?: XAllocWMHints();
	hints->flags |= IconPixmapHint;
	hints->icon_pixmap = pixmap;
	XSetWMHints(D, win, hints);
	XFree(hints);
}

int main(int argc, char** argv) {
	D = XOpenDisplay(NULL);
	visual = DefaultVisual(D, 0);
	if (visual->class!=TrueColor) {
		fprintf(stderr, "Cannot handle non true color visual ...\n");
		XCloseDisplay(D);
		exit(1);
	}
	
	// start
	Platform_main(argc, (void**)argv);
	while (processEvent()) {
		Platform_frame();
		Platform_redraw();
	}
}

void Platform_drawBitmap(Platform_Bitmap bitmap, int dx, int dy, int srcx, int srcy, int w, int h) {
	XPutImage(D, win, DefaultGC(D, 0), bitmap.data, srcx,srcy, dx,dy, w,h);
}

Platform_Bitmap Platform_createBitmap(Color* data, int width, int height) {
	return (Platform_Bitmap){
		width,
		height,
		XCreateImage(D, visual, 24, ZPixmap, 0, (char*)data, width,height, 8, 0),
	};
}

FILE* Platform_openWrite(void* name) {
	return fopen((char*)name, "w+");
}

FILE* Platform_openRead(void* name) {
	return fopen((char*)name, "r");
}

// this is absolutely fucked,
void* Platform_selectFile(int mode) {
	int pipefds[2];
	pipe(pipefds);
	if (fork()==0) {
		dup2(pipefds[1], 1);
		int status = execlp("zenity", "", "--file-selection", mode ? "--save" : NULL, NULL);
		write(pipefds[1], "", 1);
		close(pipefds[1]);
		_exit(0);
	}
	static char buf[1000];
	ssize_t n = read(pipefds[0], buf, 1000);
	if (n>=0) {
		buf[n] = '\0';
		return buf;
	}
	return NULL;
}
*/
