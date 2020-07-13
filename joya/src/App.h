

#ifndef APP_H
#define APP_H

#include <memory>
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
        std::unique_ptr<Window> m_win;
        App();
        virtual ~App();
        void Run();
    };

    // To be Defined in Client
    App *CreateApp();

} // namespace JY

#endif // !APP_H