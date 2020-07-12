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
        double m_mousex, m_mousey;
        static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        static void window_size_callback(GLFWwindow *window, int width, int height);
        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

    public:
        Window(int wWidth = 1280, int wHeight = 720, const char *wName = "JOYA");
        ~Window() = default;
        void Start();
        void Clear();
        void Update();
        void Destroy();
        bool Closed();
        void ToggleFullScreen();
        inline int GetWidth() { return m_Width; }
        inline int GetHeight() { return m_Height; }
        inline std::string GetTitle() { return m_Title; }
    };
} // namespace JY

#endif // !WINDOW_H