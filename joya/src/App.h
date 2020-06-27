

#ifndef APP_H
#define APP_H



#include <iostream>
#include "Core.h"

namespace JY
{
    class App
    {
    private:
    public:
        App();
        virtual ~App();
        void Run();
    };



    // To be Defined in Client 
    App* CreateApp();

} // namespace JY

#endif // !APP_H