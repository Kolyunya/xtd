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

/**
 *  @file string_util.hpp
 */

#ifndef _XSTD_STRING_UTIL_HPP_
#define _XSTD_STRING_UTIL_HPP_

#include <stdexcept>    // std::runtime_error
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <sstream>      // std::string
                        // std::stringstream
#include <climits>      // LONG_MIN
                        // LONG_MAX
#include <cstdlib>      // std::strtol
                        // std::strtof

/**
 *  @namespace xtd
 *  @brief A root namespace of the library.
 */
namespace xtd
{

    /**
     *  @namespace str
     *  @brief A namespace containing tools for operations which strings.
     */
    namespace str
    {

        /**
         *  @typedef
         *  @brief A collection of strings.
         */
        using strings = std::vector<std::string>;

        /**
         *  @brief Converts a number from string to numeric representation.
         *
         *  @param [in] source_string A string representation of a number.
         *  @param [in] number_base A base of a number.
         *  @returns A numeric representation of a number.
         *  @no_throw_guarantee Strong.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which is out of range of `long int`.
         *
         *  @details Converts a number represented by a `source_string` to a `long int`.
         *           Treats a `source_string` as a numeral with a base of `number_base`.
         */
        inline signed long int      string_to_long_int ( const std::string& source_string , int number_base = 10 );

        /**
         *  @brief Converts a number from string to numeric representation.
         *
         *  @param [in] source_string A string representation of a number.
         *  @param [in] number_base A base of a number.
         *  @returns A numeric representation of a number.
         *  @no_throw_guarantee Strong.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which is out of range of `long int`.
         *
         *  @details Converts a number represented by a `source_string` to a `long int`.
         *           Treats a `source_string` as a numeral with a base of `number_base`.
         */
        inline signed int           string_to_int ( const std::string& source_string , int number_base = 10 );

        inline double               string_to_double ( const std::string& source_string );

        inline float                string_to_float ( const std::string& source_string );

        inline std::string          number_to_string ( int source_number );

        inline std::string          number_to_string ( unsigned int source_number );

        inline std::string          number_to_string ( float source_number );

        inline std::string          string_reverse ( const std::string& source_string );

        inline strings              string_split ( const std::string& source_string , const std::string& delimiter );

        inline strings              string_split ( const std::string& source_string , char delimiter );

        inline strings              string_split ( const char* source_string_ptr , const char* delimiter_ptr );

        inline std::string          string_replace ( const std::string& source_string , const std::string& search_for , const std::string& replace_with );

        inline std::string          string_replace ( const std::string& source_string , char search_for , char replace_with );

        inline std::string          string_replace ( const char* source_string_ptr , const char* search_for_ptr , const char* replace_with_ptr );

        inline bool                 string_is_numeric ( const std::string& source_string );

        inline bool                 string_is_integer ( const std::string& source_string );

        inline bool                 string_is_fractional ( const std::string& source_string );

    }

}

// Include implementation file
#include "string_util.ipp"

#endif  // _XSTD_STRING_UTIL_HPP_
