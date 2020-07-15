#ifndef __EVENT_H__
#define __EVENT_H__

namespace JY
{
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    class Event
    {
    private:
    public:
        virtual ~Event() = default;
    };

    class EventDispatcher
    {
    private:
        /* data */
        Event &m_Event;

    public:
        EventDispatcher(Event &event)
            : m_Event(event)
        {
        }
        ~EventDispatcher();
    };

} // namespace JY

#endif // __EVENT_H__