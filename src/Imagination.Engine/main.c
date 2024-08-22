#include "stdio.h"
#include "Windows.h"

#include "window.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevinstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg = { 0 };

	WCHAR className[] = L"Imagination Engine";
	WCHAR windowTitle[] = L"MyGame";

	HWND hwnd = CreateGameWindow(hInstance, nCmdShow, 200, 200, 800, 500, className, windowTitle);

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, hwnd, NULL, NULL, NULL)) 
		{
			DispatchMessage(&msg);
		}
	}

	return 0;
}