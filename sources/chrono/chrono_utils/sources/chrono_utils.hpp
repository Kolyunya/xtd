#ifndef _XTD_CHRONO_UTILS_HPP_
#define _XTD_CHRONO_UTILS_HPP_

#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>
#include <mutex>

namespace xtd
{

    namespace chrono
    {

        time_t time_point_to_time_t ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        tm time_point_to_tm ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        std::string time_point_to_formatted_string ( const std::chrono::time_point<std::chrono::steady_clock>& time_point , const std::string& time_format = "[%Y/%m/%d-%H:%M:%S]" );

        std::string time_point_to_formatted_string_mt ( const std::chrono::time_point<std::chrono::steady_clock>& time_point , const std::string& time_format = "[%Y/%m/%d-%H:%M:%S]" );

    }

}

#endif