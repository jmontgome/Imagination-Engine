#include "Windows.h"

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int x, int y, int width, int height, WCHAR className[], WCHAR windowTitle[])
{
	WNDCLASSEX wc = { };

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = DefWindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = className;

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		className,
		windowTitle,
		wc.style,
		x, y, width, height,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	return hwnd;
}