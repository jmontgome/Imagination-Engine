#ifndef INPUT_H
#define INPUT_H

#include <Windows.h>
#include <glfw/glfw3.h>

#include "./internal/types.h"

void Input_Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif