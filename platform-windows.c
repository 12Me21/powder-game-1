#ifndef HDEPS
#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#undef RGB
#endif
#include <stdio.h>
#include <stdlib.h>

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
WNDCLASS wc;
HDC hdc;
HINSTANCE hInstance2;

long Platform_nanosec(void) {
	return GetTickCount()*1000000L;
}

void Platform_createWindow(axis width, axis height, char* title) {
	RECT rect = {
		.top = 0,
		.left = 0,
		.bottom = height,
		.right = width,
	};
	DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	AdjustWindowRect(&rect, style, false);
	win = CreateWindow(wc.lpszClassName, title, style, CW_USEDEFAULT, CW_USEDEFAULT, rect.right-rect.left, rect.bottom-rect.top, NULL, NULL, hInstance2, NULL);
	hdc = GetDC(win);
}

void Platform_drawBitmap(Platform_Bitmap bitmap, int dx, int dy, int srcx, int srcy, int w, int h) {
	StretchDIBits(
		hdc,
		dx,dy, w,h, //dest
		srcy,srcx, w,h, //source
		bitmap.data, &(BITMAPINFO){
			{
				sizeof(BITMAPINFOHEADER),
				bitmap.width, -bitmap.height,
				1, 32, BI_RGB, 0,
				0, 0, 0, 0
			},
			{{0, 0, 0, 0}}
		},
		DIB_RGB_COLORS,
		SRCCOPY
	);
}

Platform_Bitmap Platform_createBitmap(Color* data, int width, int height) {
	return (Platform_Bitmap){
		width,
		height,
		data,
	};
}

FILE* Platform_openWrite(void* name) {
	return fopen((char*)name, "w+");
}

FILE* Platform_openRead(void* name) {
	return fopen((char*)name, "r");
}

void* Platform_selectFile(int mode) {
	static char name[PATH_MAX];
	OPENFILENAME ofn = (OPENFILENAME){
		.lStructSize = sizeof(OPENFILENAME),
		.hwndOwner = win,
		.lpstrFile = name,
		.nMaxFile = PATH_MAX,
		.lpstrFilter = "All\0*.*\0Text\0*.TXT\0",
		.nFilterIndex = 1,
		.lpstrFileTitle = NULL,
		.lpstrInitialDir = NULL,
		.lpstrDefExt = "txt",
		.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,
	};
	if (GetSaveFileName(&ofn)==TRUE) {
		return ofn.lpstrFile;
	}
	return NULL;
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
		hdc = BeginPaint(hwnd, &ps); //return value ignored
		Platform_redraw();
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
	hInstance2 = hInstance;
	wc = (WNDCLASS){
		.style = CS_HREDRAW | CS_VREDRAW,
		.lpszClassName = "Powder Game",
		.hInstance = hInstance,
		.hbrBackground = GetSysColorBrush(COLOR_3DFACE),
		.lpfnWndProc = WndProc,
		.hCursor = LoadCursor(0, IDC_ARROW),
	};
	RegisterClass(&wc);

	int argc;
	wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	Platform_main(argc, (void**)argv);

	MSG msg;
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
		Platform_redraw();
		
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
