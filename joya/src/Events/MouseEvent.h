#ifndef __MOUSEEVENT_H__
#define __MOUSEEVENT_H__

#include "Event.h"

namespace JY
{
    class MouseMoveEvent : public Event
    {
    private:
        /* data */
        double m_X, m_Y;

    public:
        MouseMoveEvent(double x, double y) : m_X(x), m_Y(y) {}
        ~MouseMoveEvent() = default;

        double GetX() { return m_X; }
        double GetY() { return m_Y; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseScrollEvent : public Event
    {
    private:
        /* data */
        double m_XOffset, m_YOffset;

    public:
        MouseScrollEvent(double xoffset, double yoffset) : m_XOffset(xoffset), m_YOffset(yoffset) {}
        ~MouseScrollEvent();

        double GetXOffset() { return m_XOffset; }
        double GetYOffset() { return m_YOffset; }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseButtonEvent : public Event
    {
    protected:
        /* data */
        int m_Button;

    public:
        MouseButtonEvent(int ButtonCode) : m_Button(ButtonCode) {}
        ~MouseButtonEvent() = default;

        int GetButton() { return m_Button; }
    };

    class MouseButtonPressed : public MouseButtonEvent
    {
    private:
        /* data */
    public:
        MouseButtonPressed(int ButtonCode) : MouseButtonEvent(ButtonCode) {}
        ~MouseButtonPressed() = default;

        EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseButtonReleased : public MouseButtonEvent
    {
    private:
        /* data */
    public:
        MouseButtonReleased(int ButtonCode) : MouseButtonEvent(ButtonCode) {}
        ~MouseButtonReleased() = default;

        EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

} // namespace JY

#endif // __MOUSEEVENT_H__