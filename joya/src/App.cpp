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
    }
} // namespace JY