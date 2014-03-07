//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

#ifndef _XSTD_CHRONO_UTIL_HPP_
#define _XSTD_CHRONO_UTIL_HPP_

#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>
#include <mutex>

namespace xstd
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

#endif // _XSTD_CHRONO_UTIL_HPP_