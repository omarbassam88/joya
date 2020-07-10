#include "window.h"
#include "Log.h"

namespace JY
{
    Window::Window()
    {
        JY_INFO("Window is Initializing");
    }

    void Window::CreateWindow(int wWidth , int wHeight , const char* wName )
    {

        Width = wWidth;
        Height = wHeight;
        Name = wName;
        glfwInit();
        std::cout << m_window << std::endl;
        m_window = glfwCreateWindow(Width, Height, Name, NULL, NULL);
        // m_window = win;
        std::cout << m_window << std::endl;
        

        if (!m_window)
        {
            glfwTerminate();
            JY_CRITICAL("Window Could not be Created");
        }
        /* Make the m_window's context current */
        glfwMakeContextCurrent(m_window);

       
    }

    void Window::Update()
    {
         /* Loop until the user closes the m_window */
        while (!glfwWindowShouldClose(m_window))
        {
            /* Render here */
            // glClear(GL_COLOR_BUFFER_BIT);


        //     /* Swap front and back buffers */
            glfwSwapBuffers(m_window);

        //     /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(m_window);
        JY_INFO("Window is now destroyed");
    }
} // namespace JY
