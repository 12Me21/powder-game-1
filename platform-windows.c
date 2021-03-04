#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dwmapi.h>
#undef RGB
#include "common.h"
#include "input.h"
#include "save.h"
#include "vector.h"
#include "draw.h"

extern int Platform_mouseX, Platform_mouseY;
extern int Platform_mouseLeft, Platform_mouseRight, Platform_mouseMiddle;
extern bool Platform_keys[256];

void Platform_frame(void);

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
		0, 0, W, H,
		8, 8, W, H,
		grp, &bmi,
		DIB_RGB_COLORS,
		SRCCOPY
	);
	// draw menu
	static const BITMAPINFO bmi2 = {
		{
			sizeof(BITMAPINFOHEADER),
			W, -MENU_HEIGHT,
			1, 32, BI_RGB, 0,
			0, 0, 0, 0
		},
		{{0, 0, 0, 0}}
	};
	StretchDIBits(
		hdc,
		0, H, W, MENU_HEIGHT,
		0, 0, W, MENU_HEIGHT,
		Menu_grp, &bmi2,
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
	
	Save_Load_test();

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
