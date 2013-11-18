#ifndef _CHRONO_UTIL_HPP_
#define _CHRONO_UTIL_HPP_

#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>

namespace std
{

    namespace chrono
    {

        time_t          time_point_to_time_t ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        tm              time_point_to_tm ( const std::chrono::time_point<std::chrono::steady_clock>& time_point );

        std::string     time_point_to_formatted_string ( const std::chrono::time_point<std::chrono::steady_clock>& time_point , const std::string& time_format = "[%Y/%m/%d-%H:%M:%S]" );

    }

}

// Include implementation file
#include "chrono_util.ipp"

#endif // _CHRONO_UTIL_HPP_