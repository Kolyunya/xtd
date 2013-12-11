#ifndef _CHRONO_UTIL_HPP_
#define _CHRONO_UTIL_HPP_

#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>
#include <mutex>

namespace std
{

    namespace chrono
    {

        inline time_t           time_point_to_time_t ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        inline tm               time_point_to_tm ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        inline std::string      time_point_to_formatted_string ( const std::chrono::time_point<std::chrono::steady_clock>& time_point , const std::string& time_format = "[%Y/%m/%d-%H:%M:%S]" );

        inline std::string      time_point_to_formatted_string_mt ( const std::chrono::time_point<std::chrono::steady_clock>& time_point , const std::string& time_format = "[%Y/%m/%d-%H:%M:%S]" );

    }

}

// Include implementation file
#include "chrono_util.ipp"

#endif // _CHRONO_UTIL_HPP_