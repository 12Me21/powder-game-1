#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <dwmapi.h>
#undef RGB
#endif
#include "common.h"
#include "input.h"
#include "save.h"
#include "vector.h"

extern Color grp[HEIGHT][WIDTH];

extern int Platform_mouseX, Platform_mouseY;
extern int Platform_mouseLeft, Platform_mouseRight, Platform_mouseMiddle;
extern bool Platform_keys[256];

void Platform_frame(void);

#ifdef _WIN32
// https://gist.github.com/niconii/4269d1f938ba56cac6cb44376468f7bb

HWND win;

long Platform_millisec(void) {
	return GetTickCount();
}

void DrawPixels(HDC hdc) {
	static const BITMAPINFO bmi = {
		{
			sizeof(BITMAPINFOHEADER),
			WIDTH, -HEIGHT,
			1, 32, BI_RGB, 0,
			0, 0, 0, 0
		},
		{{0, 0, 0, 0}}
	};
	StretchDIBits(
		hdc,
		0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
		8, 0, WINDOW_WIDTH, WINDOW_HEIGHT, //idk why this isn't 8,8
		grp, &bmi,
		DIB_RGB_COLORS,
		SRCCOPY
	);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
	case WM_PAINT:;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		DrawPixels(hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASSW wc = {
		.style = CS_HREDRAW | CS_VREDRAW,
		.lpszClassName = L"Pixels",
		.hInstance = hInstance,
		.hbrBackground = GetSysColorBrush(COLOR_3DFACE),
		.lpfnWndProc = WndProc,
		.hCursor = LoadCursor(0, IDC_ARROW),
	};
	RegisterClassW(&wc);
	RECT rect = {
		.top=0,
		.left=0,
		.bottom=WINDOW_HEIGHT,
		.right=WINDOW_WIDTH,
	};
	DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	AdjustWindowRect(&rect, style, false);
	win = CreateWindowW(wc.lpszClassName, L"Pixels", style, CW_USEDEFAULT, CW_USEDEFAULT, rect.right-rect.left, rect.bottom-rect.top, NULL, NULL, hInstance, NULL);
	
	Load_test();

	HDC hdc = GetDC(win);
	float delta = 0;
	while(1) {
		DWORD dwStart = timeGetTime();
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) {
			if (msg.message == WM_QUIT)
				goto exit;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		POINT p;
		GetCursorPos(&p);
		ScreenToClient(win, &p);
		Platform_mouseX = p.x;
		Platform_mouseY = p.y;
		SHORT b = GetAsyncKeyState(VK_LBUTTON);
		Platform_mouseLeft = !!(b & 1<<15);
		b = GetAsyncKeyState(VK_RBUTTON);
		Platform_mouseRight = !!(b & 1<<15);
		
		Platform_frame();
		
		DrawPixels(hdc);

		//DwmFlush();
		/*delta = timeGetTime() - dwStart;
		int amt = delta-1000.0/60;
		//printf("%ld\n", timeGetTime() - dwStart);
		if (amt>0) {
			Sleep(amt);
			//delta-=amt;
			}*/
	}
 exit:
	return msg.wParam;
}

#else
//
// X11 flavor
//
//https://www.linuxquestions.org/questions/programming-9/how-to-draw-color-images-with-xlib-339366/
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <X11/keysym.h>
#include "common.h"
#include "input.h"

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

#endif
