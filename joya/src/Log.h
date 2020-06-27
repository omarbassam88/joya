

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
        static std::shared_ptr<spdlog::logger> logger;


    public:
        Log(/* args */);
        ~Log();

         void Init();
    };


} // namespace JY

#endif // !LOG_H