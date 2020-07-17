#ifndef __WINDOWEVENT_H__
#define __WINDOWEVENT_H__

#include "Event.h"

namespace JY
{
    class WindowCloseEvent : public Event
    {
    private:
        /* data */

    public:
        WindowCloseEvent(/* args */) = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    };

    class WindowResizeEvent : public Event
    {
    private:
        /* data */
        int m_Width, m_Height;

    public:
        WindowResizeEvent(int width, int height)
            : m_Width(width), m_Height(height)
        {
        }
        int GetWidth() { return m_Width; }
        int GetHeight() { return m_Height; }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    };

} // namespace JY

#endif // __WINDOWEVENT_H__