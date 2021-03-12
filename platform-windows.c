#ifndef HDEPS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#undef RGB
#endif
#include "common.h"
#include "input.h"
#include "save.h"
#include "vector.h"
#include "render/draw.h"
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

void Platform_saveAs(char* text) {
	OPENFILENAME ofn = {
		.lStructSize = sizeof(OPENFILENAME),
		.hwndOwner = win,
		.lpstrFile = (char[PATH_MAX]){0},
		.nMaxFile = PATH_MAX,
		.lpstrFilter = "All\0*.*\0Text\0*.TXT\0",
		.nFilterIndex = 1,
		.lpstrFileTitle = NULL,
		.lpstrInitialDir = NULL,
		.lpstrDefExt = "txt",
		.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,
	};
	if (GetSaveFileName(&ofn)==TRUE) {
		FILE* n = fopen(ofn.lpstrFile, "w+");
		fputs(text, n);
		fclose(n);
	}
}

void DrawPixels(HDC hdc) {
	gcopy(hdc, grp,WIDTH,HEIGHT, 0,0, 8,8, W,H);
	// draw menu
	gcopy(hdc, Menu_grp,W,MENU_HEIGHT, 0,H, 0,0, W,MENU_HEIGHT);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	void keyPress(int num, bool state) {
		int code = -1;
		switch(num) {
		when('W'): case 'w': code = 'W';
		when('A'): case 'a': code = 'A';
		when('S'): case 's': code = 'S';
		when('D'): case 'd': code = 'D';
		when(VK_LEFT):; code = 37;
		when(VK_UP):; code = 38;
		when(VK_RIGHT):; code = 39;
		when(VK_DOWN):; code = 40;
		when(VK_RETURN):; code = '\r';
		when(' '):; code = ' ';
		}
		if (code>=0) {
			Keys[code].heldNow = state;
			if (state)
				Keys[code].gotPress = true;
			else
				Keys[code].gotRelease = true;	
		}
	}
	
	void mouseButton(int num, bool state) {
		ButtonState* btn = &mouse.buttons[num];
		btn->heldNow = state;
		if (state)
			btn->gotPress = true;
		else
			btn->gotRelease = true;	
	}
	
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
	case WM_MOUSEMOVE:;
		mouse.pos = (Point){GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
		break;
	case WM_LBUTTONDOWN:;
		mouseButton(0, true);
		break;
	case WM_LBUTTONUP:;
		mouseButton(0, false);
		break;
	case WM_RBUTTONDOWN:;
		mouseButton(2, true);
		break;
	case WM_RBUTTONUP:;
		mouseButton(2, false);	
		break;
	case WM_KEYDOWN:;
		keyPress(wParam, true);
		break;
	case WM_KEYUP:;
		keyPress(wParam, false);
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
