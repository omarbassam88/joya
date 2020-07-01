

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


#define JY_TRACE(x)     JY::Log::logger->trace(x)
#define JY_INFO(x)      JY::Log::logger->info(x)
#define JY_WARN(x)      JY::Log::logger->warn(x)
#define JY_ERROR(x)     JY::Log::logger->error(x)
#define JY_CRITICAL(x)  JY::Log::logger->critical(x)



#endif // !LOG_H