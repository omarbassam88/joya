#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"
#include <string>

namespace JY
{
    class Window
    {
    private:
        /* data */
        GLFWwindow *m_window;
        const char *Name;
        int Width;
        int Height;
        bool m_fullscreen = false;

    public:
        Window(/* args */);
        ~Window() = default;
        void CreateWindow(int wWidth = 1280, int wHeight = 720, const char *wName = "JOYA");
        void Update();
        void Destroy();
    };

} // namespace JY

#endif // !WINDOW_H