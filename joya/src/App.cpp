#include "App.h"
#include "window.h"

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
        Window *win= new Window();
        win->CreateWindow();
        while (true)
        {
            win->Update();
            JY_WARN("App is running");
            sleep(10);
            win->Destroy();
        }
    }
} // namespace JY