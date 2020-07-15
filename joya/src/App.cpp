#include "App.h"

namespace JY
{
    App::App()
    {

        JY::Log *console;
        console->Init();
        JY_INFO("App is Initialised successfully");
        m_win = std::make_unique<Window>(1280, 720, "Hello JOYA APP");
        m_win->Start();
        m_win->SetEventCallback(std::bind(&App::OnEvent, this, std::placeholders::_1));
        m_win->Clear();
        m_Running = true;
    }

    App::~App()
    {
    }

    void App::Run()
    {

        while (m_Running)
        {
            m_win->Update();
            // JY_WARN("App is running");
        }
        m_win->Destroy();
    }

    void App::OnEvent(Event &e)
    {

        JY_WARN("EVENT IS TRIGGERED");
        Quit();
    }

    void App::Quit()
    {
        m_Running = false;
    }

} // namespace JY