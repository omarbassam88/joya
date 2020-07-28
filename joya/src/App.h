

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
#include "UILayer.h"
#include "Input.h"
#include "Render/Shader.h"

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
        UILayer *m_UILayer;
        Shader *m_shader;

    public:
        App();
        virtual ~App();
        void Run();
        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        Window &GetWindow() { return *m_win; }
        bool OnWindowResize(WindowResizeEvent &e);
        bool OnWindowClose(WindowCloseEvent &e);
        bool Quit();

        static App *s_Instance;
    };

    // To be Defined in Client
    App *CreateApp();

} // namespace JY

#endif // !APP_H