#include <Windows.h>

#include "global.h"
#include "game/player.h"

#define DRAW_PIXEL(hdc, point) Rectangle(hdc, point.X, GetScreenHeight() - point.Y, GetScreenWidth() - point.X + 1, point.Y + 1)

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5

HWND* Window;
HDC Screen;

u16 ScreenWidth;
u16 ScreenHeight;

u16 GetScreenWidth() {
	return ScreenWidth;
}
u16 GetScreenHeight() {
	return ScreenHeight;
}

void Graph_DrawWorld() {

}
void Graph_DrawEntities() {

}
void Graph_DrawPlayer() {
	Rectangle(Screen,
		(ScreenWidth / 2) + Player_GetX(),
		(ScreenHeight / 2) - Player_GetY(),
		(ScreenWidth / 2) + Player_GetX() + PLAYER_WIDTH,
		(ScreenHeight / 2) - Player_GetY() + PLAYER_HEIGHT);
}

void Graph_Init(HWND* hwnd) {
	RECT screenDim;
	Window = hwnd;
	if (GetWindowRect(Window, &screenDim)) {
		ScreenWidth = screenDim.right - screenDim.left;
		ScreenHeight = screenDim.bottom - screenDim.top;
	}
}
void Graph_Main() {
	RECT screenDim;
	Screen = GetWindowDC(Window);

	if (Screen) {
		Graph_DrawPlayer();
		ReleaseDC(Window, Screen);
	}

	Screen = NULL;
}