#include "Log.h"

namespace JY
{
    std::shared_ptr<spdlog::logger> Log::logger;

    Log::Log(/* args */)
    {
    }

    Log::~Log()
    {
    }

    void Log::Init()
    {
        std::cout << "Initializing Log" << std::endl;
        spdlog::set_pattern("%T %^[%l]%$  %v");

        logger = spdlog::stdout_color_mt("JOYA");
        logger->info("Logger is Initialized {}", "123");
    }

} // namespace JY
