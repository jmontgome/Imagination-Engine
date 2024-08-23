#include <iostream>
#include <GLFW/glfw3.h>

#include "input.cpp"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) 
    {
        key_down(key);
    }
    else if (action == GLFW_RELEASE) 
    {
        key_up(key);
    }
    else if (action == GLFW_REPEAT) 
    {
        key_hold(key);
    }
    else
    {
        std::cout << "Action :" << action << "\r\n";
    }
    
    //if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    //    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    const char WindowTitle[] = "Imagination Engine";

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, WindowTitle, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}