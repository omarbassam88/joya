

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> 

namespace JY
{

    class Log
    {
    private:
        /* data */


    public:
        static std::shared_ptr<spdlog::logger> logger;
        Log(/* args */);
        ~Log();

         void Init();

    };


} // namespace JY


#define JY_TRACE(...)     JY::Log::logger->trace(__VA_ARGS__)
#define JY_INFO(...)      JY::Log::logger->info(__VA_ARGS__)
#define JY_WARN(...)      JY::Log::logger->warn(__VA_ARGS__)
#define JY_ERROR(...)     JY::Log::logger->error(__VA_ARGS__)
#define JY_CRITICAL(...)  JY::Log::logger->critical(__VA_ARGS__)



#endif // !LOG_H