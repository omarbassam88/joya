#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"


namespace JY
{
    class Window
    {
    private:
        /* data */
        // GLFWwindow *window;
        

    public:
        Window(/* args */);
        ~Window();
        void CreateWindow();
        void Destroy();
    };

} // namespace JY

#endif // !WINDOW_H