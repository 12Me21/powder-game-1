#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdlib.h>
#include <X11/Xlib-xcb.h>

Display *dis;
int screen;
Window win;
GC gc;

void init_x() {
	/* get the colors black and white (see section for details) */
	unsigned long black,white;

	/* use the information from the environment variable DISPLAY 
	   to create the X connection:
	*/ 
	dis=XOpenDisplay((char *)0);
	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen); /* get color black */
	white=WhitePixel(dis, screen);  /* get color white */

	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0, 200, 300, 5, white, black);

	/* here is where some properties of the window can be set.
	   The third and fourth items indicate the name which appears
	   at the top of the window and the name of the minimized window
	   respectively.
	*/
	XSetStandardProperties(dis,win,"My Window","HI!",None,NULL,0,NULL);

	// this routine determines which types of input are allowed in
	// the input.  see the appropriate section for details...
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);

	/* create the Graphics Context */
	gc=XCreateGC(dis, win, 0,0);        
 
	// here is another routine to set the foreground and background
	// colors _currently_ in use in the window.
	XSetForeground(dis,gc,white);

	/* clear the window and bring it on top of the other windows */
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

void close_x() {
	// it is good programming practice to return system resources to the 
	// system...
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);
	exit(1);
}

void redraw(void) {
	XDrawRectangle(dis, win, gc, 10, 10, 100, 100);
}

int main(void) {
	init_x();
	xcb_connection_t* n = XGetXCBConnection(dis);
	XEvent event;
	char* string = "test123";
	while (1) {
		XNextEvent(dis, &event);
	XDrawLine(dis, win, gc, 10, 10,190,190); //from-to
	XDrawLine(dis, win, gc, 10,190,190, 10); //from-to
	}
	return 0;
}
