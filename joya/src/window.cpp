#include "window.h"
#include "Log.h"
#include <string>

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

    Window::~Window()
    {
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
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        JY_INFO("OpenGL : {}", glGetString(GL_VERSION));

        glfwSetWindowUserPointer(m_window, this);

        glfwSetKeyCallback(m_window, key_callback);
        glfwSetMouseButtonCallback(m_window, mouse_button_callback);
        glfwSetWindowSizeCallback(m_window, window_size_callback);
        glfwSetCursorPosCallback(m_window, cursor_position_callback);
        glfwSetWindowCloseCallback(m_window, close_window_callback);
        glfwSetScrollCallback(m_window, scroll_callback);
    }

    void Window::SetEventCallback(std::function<void(Event &)> callback)
    {
        EventCallbackFn = callback; // Links to App::OnEvent
    }

    void Window::Clear()
    {
        glClearColor(0.2, 0.3, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::Update()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //     /* Swap front and back buffers */
        glfwSwapBuffers(m_window);

        //     /* Poll for and process events */
        glfwPollEvents();
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

    void Window::ToggleFullScreen()
    {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();

        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        if (!m_fullscreen)
        {
            glfwSetWindowMonitor(m_window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            m_fullscreen = true;
        }
        else
        {
            glfwSetWindowMonitor(m_window, NULL, 500, 250, 800, 600, mode->refreshRate);
            m_fullscreen = false;
        }
    }

    // Window Events

    void Window::window_size_callback(GLFWwindow *window, int width, int height)
    {
        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));
        WindowResizeEvent e(width, height);
        instance.EventCallbackFn(e);
    }

    void Window::close_window_callback(GLFWwindow *window)
    {
        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));
        JY_ERROR("CLOSING WINDOW");
        WindowCloseEvent e;
        instance.EventCallbackFn(e);
    }

    // Keyboard Events

    void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {

        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));

        if (action == GLFW_PRESS)
        {
            switch (key)
            {
                // case GLFW_KEY_F11:
                //     ToggleFullScreen();
                //     break;
                // case GLFW_KEY_F:
                //     ToggleFullScreen();
                //     break;

            default:
                JY_INFO("UnAssigned key is pressed");
                break;
            }
        }
    }

    // Mouse Events

    void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));
        if (action == GLFW_PRESS)
        {
            switch (button)
            {
            case GLFW_MOUSE_BUTTON_LEFT:
                JY_INFO("LEFT MOUSE BUTTON");
                break;
            case GLFW_MOUSE_BUTTON_RIGHT:
                JY_INFO("RIGHT MOUSE BUTTON");
                break;
            case GLFW_MOUSE_BUTTON_MIDDLE:
                JY_INFO("MIDDLE MOUSE BUTTON");
                break;
            default:
                break;
            }
        }
    }

    void Window::cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
    {
        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));
        JY_INFO("x: {},y: {}", xpos, ypos);
    }

    void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
    {
        Window &instance = *(Window *)(glfwGetWindowUserPointer(window));
        JY_INFO("Scroll Ofsset {}", yoffset);
    }
} // namespace JY
