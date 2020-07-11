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
        m_win = new Window(640, 480, "Hello JOYA APP");
        m_win->Start();
        while (!m_win->Closed())
        {
            m_win->Clear();
            m_win->Update();
            // JY_WARN("App is running");

            
        }
            m_win->Destroy();
    }
} // namespace JY