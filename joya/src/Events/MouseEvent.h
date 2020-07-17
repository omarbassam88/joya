#ifndef __MOUSEEVENT_H__
#define __MOUSEEVENT_H__

#include "Event.h"

namespace JY
{
    class MouseButtonPressed
    {
    private:
        /* data */
        
    public:
        MouseButtonPressed(/* args */);
        ~MouseButtonPressed();

        EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
    };
    

    
} // namespace JY


#endif // __MOUSEEVENT_H__