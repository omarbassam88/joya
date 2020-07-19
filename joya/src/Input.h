#ifndef __INPUT_H__
#define __INPUT_H__

#include "window.h"
#include "App.h"

namespace JY
{
    class Input
    {
    private:
        /* data */
    public:
        static bool IsKeyPressed(int key);
        static bool IsMouseButtonPressed(int key);
        static std::pair<float,float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
        // static Input* s_instance;

    };

    
    

    
} // namespace JY

#endif // __INPUT_H__