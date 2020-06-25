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

    App::App()
    {
    }

    App::~App()
    {
    }

    // To be Defined in Client 
    App* CreateApp();

} // namespace JY
