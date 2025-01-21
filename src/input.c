#include <Windows.h>

#include "global.h"
#include "input.h"
#include "clock.h"
#include "game/player.h"

InputState Input_State;

void Input_CheckKeys(UINT msg, WPARAM wParam) {
	u128 tick = Clock_GetTick();
	if (msg == WM_KEYDOWN) {
		if (Input_State.KeysActive[wParam].KeyCode == 0) {
			KeyActive active = {
				.KeyCode = (u8)wParam,
				.TimeActivated = tick,
				.DoubleTap = 0
			};
			if (Input_State.KeysReleased[wParam].KeyCode != 0) {
				if ((tick - Input_State.KeysReleased[wParam].TimeReleased) < DOUBLE_TAP_WINDOW) {
					active.DoubleTap = 1;
				}
			}
			Input_State.KeysActive[wParam] = active;
			Input_State.KeysReleased[wParam].KeyCode = 0;
		}
	}
	else if (msg == WM_KEYUP) {
		if (Input_State.KeysActive[wParam].KeyCode != 0) {
			KeyRelease release = {
				.KeyCode = (u8)wParam,
				.TimeReleased = tick
			};
			if (Input_State.KeysActive[wParam].KeyCode != 0) {
				release.TimeActivated = Input_State.KeysActive[wParam].TimeActivated;
			}
			Input_State.KeysReleased[wParam] = release;
			Input_State.KeysActive[wParam].KeyCode = 0;
		}
	}
}
void Input_Process() {
	for (int i = 0; i < 256; i++) {
		if (Input_State.KeysActive[i].KeyCode != 0) {
			if (Input_State.KeysActive[i].KeyCode == 0x41) {
				Player_MoveLeft();
			}
			else if (Input_State.KeysActive[i].KeyCode == 0x44) {
				Player_MoveRight();
			}
			else if (Input_State.KeysActive[i].KeyCode == 0x53) {
				Player_MoveDown();
			}
			else if (Input_State.KeysActive[i].KeyCode == 0x57) {
				Player_MoveUp();
			}
		}
	}
}

void Input_Main() {
	Input_Process();
}