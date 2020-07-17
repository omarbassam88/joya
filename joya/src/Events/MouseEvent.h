#ifndef __MOUSEEVENT_H__
#define __MOUSEEVENT_H__

#include "Event.h"

namespace JY
{
    class MouseMoveEvent : public Event
    {
    private:
        /* data */
    public:
        MouseMoveEvent(/* args */);
        ~MouseMoveEvent();

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseScrollEvent : public Event
    {
    private:
        /* data */
    public:
        MouseScrollEvent(/* args */);
        ~MouseScrollEvent();

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseButtonEvent : public Event
    {
    private:
        /* data */
    public:
        MouseButtonEvent(/* args */);
        ~MouseButtonEvent();
    };

    class MouseButtonPressed : public MouseButtonEvent
    {
    private:
        /* data */

    public:
        MouseButtonPressed(/* args */);
        ~MouseButtonPressed();

        EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

    class MouseButtonReleased : public MouseButtonEvent
    {
    private:
        /* data */

    public:
        MouseButtonReleased(/* args */);
        ~MouseButtonReleased();

        EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };

} // namespace JY

#endif // __MOUSEEVENT_H__