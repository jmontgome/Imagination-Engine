#include <glfw/glfw3.h>

#include "input.h"
#include "sys/system.h"

#if WINDOWS
#if _DEBUG
int main() {
#else
int WinMain() {
#endif
#elif LINUX
int main() {
#endif
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Imagination Engine", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, Input_Key_Callback);

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}