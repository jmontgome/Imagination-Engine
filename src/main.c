#include <Windows.h>

#include "global.h"
#include "window.h"
#include "input.h"
#include "graph.h"

const LPCWSTR W_CLASS_NAME = L"Imagination Engine";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	Input_CheckKeys(msg, wParam);
	switch (msg) {
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)
{	
	u8 isRunning = 1;
	MSG msg;

	HWND* hwnd = Window_Init(hInstance, nCmdShow, W_CLASS_NAME);
	if (!hwnd) {
		return 1;
	}

	while (isRunning == 1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Graph_Main();
		Input_Main();
	}

	return msg.wParam;
}