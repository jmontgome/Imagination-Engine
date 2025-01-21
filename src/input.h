#ifndef INPUT_H
#define INPUT_H

#include <Windows.h>

#include "global.h"

#define DOUBLE_TAP_WINDOW 500

typedef struct KeyActive {
	u8 KeyCode;
	u8 DoubleTap;
	u128 TimeActivated;
} KeyActive;
typedef struct KeyRelease {
	u8 KeyCode;
	u128 TimeActivated;
	u128 TimeReleased;
} KeyRelease;
typedef struct InputState {
	KeyActive KeysActive[256];
	KeyRelease KeysReleased[256];
} InputState;

void Input_CheckKeys(UINT msg, WPARAM wParam);
void Input_Process();

void Input_Main();

#endif