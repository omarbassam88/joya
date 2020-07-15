

#ifndef APP_H
#define APP_H

#include <memory>
#include <iostream>
#include "Core.h"
#include "Log.h"
#include "window.h"
#include "Events/Event.h"

namespace JY
{
    class App
    {
    private:
    bool m_Running= false;
    bool m_fullscreen;
    bool m_closed;
    double m_mousex,m_mousey;
    public:
        std::unique_ptr<Window> m_win;
        App();
        virtual ~App();
        void Run();
        void OnEvent(Event &e);
        void Quit();




    };

    // To be Defined in Client
    App *CreateApp();

} // namespace JY

#endif // !APP_H