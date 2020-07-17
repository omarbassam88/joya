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

    enum EventCategory
    {
        None = 0,
        EventCategoryWindow,
        EventCategoryInput,
        EventCategoryKeyboard,
        EventCategoryMouse
    };

    class Event
    {
    private:
    public:
        bool Handled;

        ~Event() = default;
        virtual const char *GetName() const = 0;
        virtual EventType GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType GetStaticType() { return EventType::type; }                \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

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
        ~EventDispatcher() = default;
        template <typename T, typename F>
        bool Dispatch(const F &func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled = func(static_cast<T &>(m_Event));
                return true;
            }

            return false;
        }
    };

} // namespace JY

#endif // __EVENT_H__