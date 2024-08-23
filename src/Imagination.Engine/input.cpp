#ifndef INPUT
#define INPUT

#include <iostream>
#include <GLFW/glfw3.h>

static void key_down(int key) 
{
	std::cout << "Key Down: " << key << "\n";
	if (key == GLFW_KEY_ESCAPE) {

	}
}

static void key_up(int key) 
{
	std::cout << "Key Up: " << key << "\n";
}

static void key_hold(int key) {
	std::cout << "Holding Key: " << key << "\n";
}

#endif