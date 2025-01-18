#include <Windows.h>

#include "global.h"
#include "window.h"
#include "input.h"
#include "graph.h"
#include "clock.h"
#include "game/play.h"

const LPCWSTR W_CLASS_NAME = L"Imagination Engine";

u8 IsRunning = 1;

int WINAPI WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)
{	
	MSG msg;

	HWND* hwnd = Window_Init(hInstance, nCmdShow, W_CLASS_NAME);
	if (!hwnd) {
		return 1;
	}

	Play_Init();
	Graph_Init(hwnd);

	while (IsRunning == 1) {
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Graph_Main();
		Input_Main();
		Clock_Main();
	}

	return msg.wParam;
}