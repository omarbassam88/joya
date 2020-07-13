#include "App.h"

namespace JY
{
    App::App()
    {


    }

    App::~App()
    {
    }

    void App::Run()
    {
        std::cout << "Running Class" << std::endl;
        JY::Log *console;
        console->Init();
        JY_INFO("App is Initialised successfully");
        m_win = std::make_unique<Window>(640, 480, "Hello JOYA APP");
        m_win->Start();
            m_win->Clear();
        while (!m_win->Closed())
        {
            m_win->Update();
            // JY_WARN("App is running");
        }
            m_win->Destroy();
    }
} // namespace JY