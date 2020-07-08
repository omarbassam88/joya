#include "window.h"
#include "Log.h"

namespace JY
{
    Window::Window()
    {
        JY_INFO("Window is Initializing");
    }

    void Window::CreateWindow()
    {
        glfwInit();
        GLFWwindow *window = glfwCreateWindow(1280, 720, "Hello, JOYA", NULL, NULL);

        if (!window)
        {
            glfwTerminate();
            JY_CRITICAL("Window Could not be Created");
        }
        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            // glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void Window::Destroy()
    {
        // glfwDestroyWindow(window);
    }
} // namespace JY
