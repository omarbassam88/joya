

#ifndef APP_H
#define APP_H



#include <iostream>
#include "Core.h"
#include "Log.h"
#include "window.h"

namespace JY
{
    class App
    {
    private:

    public:
        Window *win;
        App();
        virtual ~App();
        void Run();
    };



    // To be Defined in Client 
    App* CreateApp();

} // namespace JY

#endif // !APP_H