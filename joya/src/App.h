

#ifndef APP_H
#define APP_H

#include <memory>
#include <iostream>
#include "Core.h"
#include "Log.h"
#include "window.h"
#include "Events/Event.h"
#include "Layer.h"
#include "LayerStack.h"

namespace JY
{
    class App
    {
    private:
        std::unique_ptr<Window> m_win;
        bool m_Running = false;
        bool m_fullscreen;
        double m_mousex, m_mousey;
        Log *console;
        LayerStack m_LayerStack;

    public:
        App();
        virtual ~App();
        void Run();
        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        bool OnWindowResize(WindowResizeEvent &e);
        bool OnWindowClose(WindowCloseEvent &e);
        bool Quit();
    };

    // To be Defined in Client
    App *CreateApp();

} // namespace JY

#endif // !APP_H