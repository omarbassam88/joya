#include "App.h"

namespace JY
{

    App *App::s_Instance = nullptr;

    App::App()
    {
        s_Instance = this;
        console->Init();
        m_win = std::make_unique<Window>(1280, 720, "Hello JOYA APP");
        m_win->Start();
        m_win->SetEventCallback(std::bind(&App::OnEvent, this, std::placeholders::_1));
        m_win->Clear();
        m_Running = true;
        ui = new UILayer();
        JY_INFO("{}", ui->GetName());
        PushOverlay(ui);

        JY_INFO("App is Initialised successfully");
    }

    App::~App()
    {
    }

    void App::Run()
    {
        while (m_Running)
        {
            m_win->Update();
            ui->OnUpdate();
        }
        m_win->Destroy();
    }

    void App::OnEvent(Event &e)
    {

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowResizeEvent>(std::bind(&App::OnWindowResize, this, std::placeholders::_1));
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&App::OnWindowClose, this, std::placeholders::_1));
    }

    void App::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void App::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    bool App::Quit()
    {
        m_Running = false;
        return true;
    }

    bool App::OnWindowResize(WindowResizeEvent &e)
    {

        JY_WARN("Width: {}, Hieght: {}", e.GetWidth(), e.GetHeight());
        return true;
    }

    bool App::OnWindowClose(WindowCloseEvent &e)
    {
        Quit();
        return true;
    }

} // namespace JY