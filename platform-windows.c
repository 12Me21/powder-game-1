#ifndef HDEPS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dwmapi.h>
#undef RGB
#endif
#include "common.h"
#include "input.h"
#include "save.h"
#include "vector.h"
#include "draw.h"
#include "platform.h"
#ifndef HDEPS
//extern int Platform_mouseX, Platform_mouseY;
//extern int Platform_mouseLeft, Platform_mouseRight, Platform_mouseMiddle;
//extern bool Platform_keys[256];

void Platform_frame(void);

// https://gist.github.com/niconii/4269d1f938ba56cac6cb44376468f7bb

HWND win;

long Platform_nanosec(void) {
	return GetTickCount()*1000000L;
}

// todo: make a wrapper function so this can be called from outside platform- files.
// call one function to create bitmaps (for windows this can just do nothing)
// and then another to render them
void gcopy(HDC hdc, void* grp, int sw, int sh, int dx, int dy, int sx, int sy, int w, int h) {
	StretchDIBits(
		hdc,
		dx,dy, w,h, //dest
		sy,sx, w,h, //source
		grp, &(BITMAPINFO){
			{
				sizeof(BITMAPINFOHEADER),
				sw, -sh,
				1, 32, BI_RGB, 0,
				0, 0, 0, 0
			},
			{{0, 0, 0, 0}}
		},
		DIB_RGB_COLORS,
		SRCCOPY
	);
}

void DrawPixels(HDC hdc) {
	gcopy(hdc, grp,WIDTH,HEIGHT, 0,0, 8,8, W,H);
	// draw menu
	gcopy(hdc, Menu_grp,W,MENU_HEIGHT, 0,H, 0,0, W,MENU_HEIGHT);
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

FILE* Platform_fopen(const void* name) {
	return _wfopen((const wchar_t*)name, L"r");
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASS wc = {
		.style = CS_HREDRAW | CS_VREDRAW,
		.lpszClassName = "Powder Game",
		.hInstance = hInstance,
		.hbrBackground = GetSysColorBrush(COLOR_3DFACE),
		.lpfnWndProc = WndProc,
		.hCursor = LoadCursor(0, IDC_ARROW),
	};
	RegisterClass(&wc);
	RECT rect = {
		.top = 0,
		.left = 0,
		.bottom = WINDOW_HEIGHT,
		.right = WINDOW_WIDTH,
	};
	DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	AdjustWindowRect(&rect, style, false);
	win = CreateWindow(wc.lpszClassName, "Powder Game", style, CW_USEDEFAULT, CW_USEDEFAULT, rect.right-rect.left, rect.bottom-rect.top, NULL, NULL, hInstance, NULL);

	int argc;
	wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	Platform_main(argc, (void**)argv);

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
		mouse.pos = (Point){p.x, p.y};
		
		SHORT b = GetAsyncKeyState(VK_LBUTTON);
		//Platform_mouseLeft = !!(b & 1<<15);
		b = GetAsyncKeyState(VK_RBUTTON);
		//Platform_mouseRight = !!(b & 1<<15);
		
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
#endif
