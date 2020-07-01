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
        logger->info("Logger is Initializing {}", "123");
        logger->info("This is Info Log {}", "456");
        logger->error("This is an Error Log");
        logger->trace("Trace Log");
        logger->warn("This is a Warning Log");
        logger->critical("This is a Critical Log");

    }

} // namespace JY
