#include <Windows.h>

#include "global.h"
#include "game/player.h"

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5

HWND* Window;

void Graph_DrawWorld() {

}
void Graph_DrawEntities() {

}
void Graph_DrawPlayer() {
	RECT windowDim;
	HDC screen = GetDC(*Window);
	u16 screenWidth = 0;
	u16 screenHeight = 0;

	if (GetWindowRect(*Window, &windowDim)) {
		screenWidth = windowDim.right - windowDim.left;
		screenHeight = windowDim.bottom - windowDim.top;

		Rectangle(screen,
			(screenWidth / 2) + Player_GetX(),
			(screenHeight / 2) + Player_GetY(),
			(screenWidth / 2) + Player_GetX() + PLAYER_WIDTH,
			(screenHeight / 2) + Player_GetY() + PLAYER_HEIGHT);
	}
}

void Graph_Init(HWND* hwnd) {
	Window = hwnd;
}
void Graph_Main() {
	Graph_DrawPlayer();
}