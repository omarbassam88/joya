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
        win = new Window();
        win->CreateWindow(640, 480, "Hello JOYA APP");
        while (true)
        {
            win->Update();
            JY_WARN("App is running");

            break;
        }
            win->Destroy();
    }
} // namespace JY