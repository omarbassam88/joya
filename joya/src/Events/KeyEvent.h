#ifndef __KEYEVENT_H__
#define __KEYEVENT_H__

#include "Event.h"
#include "../KeyCodes.h"

namespace JY
{
    class KeyEvent : public Event
    {
    private:
        /* data */
        KeyCode m_Key;

    public:
        KeyEvent(KeyCode key) : m_Key(key) {}
        ~KeyEvent() = default;

        KeyCode GetKey() { return m_Key; }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    };

    class KeyPressedEvent : public KeyEvent
    {
    private:
        /* data */
        int m_RepeatCount;

    public:
        KeyPressedEvent(KeyCode key, int count) : KeyEvent(key), m_RepeatCount(count) {}
        ~KeyPressedEvent() = default;

        int GetRepeatCount() { return m_RepeatCount; }

        EVENT_CLASS_TYPE(KeyPressed)
    };

    class KeyReleasedEvent : public KeyEvent
    {
    private:
        /* data */
    public:
        KeyReleasedEvent(KeyCode key) : KeyEvent(key) {}
        ~KeyReleasedEvent() = default;

        EVENT_CLASS_TYPE(KeyReleased)
    };

} // namespace JY

#endif // __KEYEVENT_H__