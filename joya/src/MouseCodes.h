#ifndef __MOUSECODES_H__
#define __MOUSECODES_H__

#include <iostream>

namespace Hazel
{
    typedef enum class MouseCode : uint16_t
    {
        // From glfw3.h
        Button0 = 0,
        Button1 = 1,
        Button2 = 2,
        Button3 = 3,
        Button4 = 4,
        Button5 = 5,
        Button6 = 6,
        Button7 = 7,

        ButtonLast = Button7,
        ButtonLeft = Button0,
        ButtonRight = Button1,
        ButtonMiddle = Button2
    } Mouse;

    inline std::ostream &operator<<(std::ostream &os, MouseCode mouseCode)
    {
        os << static_cast<int32_t>(mouseCode);
        return os;
    }
} // namespace Hazel

#define JY_MOUSE_BUTTON_0       JY::Mouse::Button0
#define JY_MOUSE_BUTTON_1       JY::Mouse::Button1
#define JY_MOUSE_BUTTON_2       JY::Mouse::Button2
#define JY_MOUSE_BUTTON_3       JY::Mouse::Button3
#define JY_MOUSE_BUTTON_4       JY::Mouse::Button4
#define JY_MOUSE_BUTTON_5       JY::Mouse::Button5
#define JY_MOUSE_BUTTON_6       JY::Mouse::Button6
#define JY_MOUSE_BUTTON_7       JY::Mouse::Button7
#define JY_MOUSE_BUTTON_LAST    JY::Mouse::ButtonLast
#define JY_MOUSE_BUTTON_LEFT    JY::Mouse::ButtonLeft
#define JY_MOUSE_BUTTON_RIGHT   JY::Mouse::ButtonRight
#define JY_MOUSE_BUTTON_MIDDLE  JY::Mouse::ButtonMiddle

#endif // __MOUSECODES_H__