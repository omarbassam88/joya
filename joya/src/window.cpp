#include "window.h"
#include "Log.h"

namespace JY
{
    Window::Window(int Width, int Height, const char *Title)
        : m_Width(Width),
          m_Height(Height),
          m_Title(Title),
          m_closed(false)
    {
        JY_INFO("Window is Initializing with Width: {}, Height: {} and Title: {}", m_Width, m_Height, m_Title);
    }

    void Window::Start()
    {

        if (!glfwInit())
        {
            JY_CRITICAL("GLFW Could not be initialized");
        }

        // Creating the window with the data from the class members
        m_window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

        if (!m_window)
        {
            glfwTerminate();
            JY_CRITICAL("Window Could not be Created");
        }
        /* Make the m_window's context current */
        glfwMakeContextCurrent(m_window);

        glfwSetKeyCallback(m_window, ToggleFullScreen);
    }

    void Window::Clear()
    {
        glClearColor(0.2, 0.3, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::Update()
    {
        //     /* Swap front and back buffers */
        glfwSwapBuffers(m_window);

        //     /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(m_window))
        {

            m_closed = true;
        }
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        JY_INFO("Window is now destroyed");
    }

    bool Window::Closed()
    {
        return m_closed;
    }

    void ToggleFullScreen(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        bool fullscreen;
        int width;
        int height;
        glfwGetWindowSize(window, &width, &height);
        if (width == 1920)
        {
            fullscreen = true;
        }
        else
        {
            fullscreen = false;
        }

        if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
        {

            if (!fullscreen)
            {
                glfwSetWindowSize(window, 1920, 1080);
                JY_WARN("FULLSCREEN");
                fullscreen = true;
            }
            else
            {
                glfwSetWindowSize(window, 640, 480);
                JY_WARN("NOT FULLSCREEN");
                fullscreen = false;
            }
        }
    }

} // namespace JY
