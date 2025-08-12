#include <GLFW/glfw3.h>

#include "././internal/types.h"

double Clock_GetSeconds() {
	return glfwGetTime();
}
u128 Clock_GetTickInWholeSeconds() {
	return (u128)glfwGetTime();
}

void Clock_Main() {
	
}