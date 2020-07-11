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
        const char *m_Title;
        int m_Width;
        int m_Height;
        bool m_fullscreen = false;
        bool m_closed;

    public:
        Window(int wWidth = 1280, int wHeight = 720, const char *wName = "JOYA");
        ~Window() = default;
        void Start();
        void Clear();
        void Update();
        void Destroy();
        bool Closed();
        inline int GetWidth() { return m_Width; }
        inline int GetHeight() { return m_Height; }
        inline std::string GetTitle() { return m_Title; }
    };
    void ToggleFullScreen(GLFWwindow *window, int key, int scancode, int action, int mods);

} // namespace JY

#endif // !WINDOW_H