#include <Windows.h>

#include "global.h"
#include "input.h"
#include "clock.h"

InputState Input_State;

void Input_CheckKeys(UINT msg, WPARAM wParam) {
	u128 tick = Clock_GetTick();
	if (msg == WM_KEYDOWN) {
		KeyActive active = {
			.KeyCode = (u8)wParam,
			.TimeActivated = tick,
			.DoubleTap = 0
		};
		if (Input_State.KeysReleased[wParam]) {
			if ((tick - Input_State.KeysReleased[wParam]->TimeReleased) < DOUBLE_TAP_WINDOW) {
				active.DoubleTap = 1;
			}
		}
		Input_State.KeysActive[wParam] = &active;
	}
	else if (msg == WM_KEYUP) {
		KeyRelease release = {
			.KeyCode = (u8)wParam,
			.TimeReleased = tick
		};
		if (Input_State.KeysActive[wParam]) {
			release.TimeActivated = Input_State.KeysActive[wParam]->TimeActivated;
		}
		Input_State.KeysReleased[wParam] = &release;
		Input_State.KeysActive[wParam] = NULL;
	}
}
void Input_Process() {

}

void Input_Main() {
	Input_Process();
}