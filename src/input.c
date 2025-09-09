#include <stdio.h>
#include <GLFW/glfw3.h>

#include "sys/system.h"
#include "./internal/types.h"
#include "./internal/clock.h"
#include "game/player.h"
#include "input.h"

void Input_Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		KeysActive[key] = 1;
	}
	if (action == GLFW_RELEASE) {
		KeysActive[key] = 0;
	}
}