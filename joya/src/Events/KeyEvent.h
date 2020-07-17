#ifndef __KEYEVENT_H__
#define __KEYEVENT_H__

#include "Event.h"

namespace JY
{
    class KeyEvent : public Event
    {
    private:
        /* data */
    public:
        KeyEvent(/* args */);
        ~KeyEvent();
    };

    class KeyPressedEvent : public KeyEvent
    {
    private:
        /* data */
    public:
        KeyPressedEvent(/* args */);
        ~KeyPressedEvent();

        EVENT_CLASS_TYPE(KeyPressed)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    };

    class KeyReleasedEvent : public KeyEvent
    {
    private:
        /* data */
    public:
        KeyReleasedEvent(/* args */);
        ~KeyReleasedEvent();

        EVENT_CLASS_TYPE(KeyReleased)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    };

} // namespace JY

#endif // __KEYEVENT_H__