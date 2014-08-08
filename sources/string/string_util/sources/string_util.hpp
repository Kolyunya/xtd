//  XTD - extension of the C++ standard library
//  Copyright (C) 2013-2014 Oleynikov Nikolay
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

#ifndef _XTD_STRING_UTIL_HPP_
#define _XTD_STRING_UTIL_HPP_

#include <stdexcept>
#include <algorithm>
#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>

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
         *  @param [in] source_string A string representation of a number.
         *  @param [in] number_base A base of a number.
         *  @returns A numeric representation of a number.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which exceeds the range of the type.
         *  @details Converts a number represented by a `source_string` to a `signed long long int`.
         *           Treats a `source_string` as a numeral with a base of `number_base`.
         *  @note This function is a wrapper of a [strtoll](http://en.cppreference.com/w/cpp/string/byte/strtoll) function
         *        and accepts exact same source string formats.
         */
        inline signed long long int to_long_long ( const std::string& source_string , signed int number_base = 0 );

        /**
         *  @brief Converts a number from string to numeric representation.
         *  @param [in] source_string A string representation of a number.
         *  @param [in] number_base A base of a number.
         *  @returns A numeric representation of a number.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which exceeds the range of the type.
         *  @details Converts a number represented by a `source_string` to a `signed long int`.
         *           Treats a `source_string` as a numeral with a base of `number_base`.
         *  @note This function is a wrapper of a [strtol](http://en.cppreference.com/w/cpp/string/byte/strtol) function
         *        and accepts exact same source string formats.
         */
        inline signed long int to_long ( const std::string& source_string , signed int number_base = 0 );

        /**
         *  @brief Converts a number from string to numeric representation.
         *  @param [in] source_string A string representation of a number.
         *  @param [in] number_base A base of a number.
         *  @returns A numeric representation of a number.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which exceeds the range of the type.
         *  @details Converts a number represented by a `source_string` to a `signed int`.
         *           Treats a `source_string` as a numeral with a base of `number_base`.
         *  @note This function is a wrapper of a [strtol](http://en.cppreference.com/w/cpp/string/byte/strtol) function
         *        and accepts exact same source string formats.
         */
        inline signed int to_int ( const std::string& source_string , signed int number_base = 0 );

        /**
         *  @brief Converts a number from string to numeric representation.
         *  @param [in] source_string A string representation of a number.
         *  @returns A numeric representation of a number.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which exceeds the range of the type.
         *  @details Converts a number represented by a `source_string` to a `double`.
         *  @note This function is a wrapper of a [strtod](http://en.cppreference.com/w/cpp/string/byte/strtod) function
         *        and accepts exact same source string formats.
         */
        inline double to_double ( const std::string& source_string );

        /**
         *  @brief Converts a number from string to numeric representation.
         *  @param [in] source_string A string representation of a number.
         *  @returns A numeric representation of a number.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if `source_string` does not represent a valid_number.
         *                             Also thrown if `source_string` represents a number which exceeds the range of the type.
         *  @details Converts a number represented by a `source_string` to a `double`.
         *  @note This function is a wrapper of a [strtof](http://en.cppreference.com/w/cpp/string/byte/strtof) function
         *        and accepts exact same source string formats.
         */
        inline float to_float ( const std::string& source_string );

        /**
         *  @brief Converts a number from numeric to string representation.
         *  @param [in] source_number A numeric representation of a number.
         *  @returns A string representation of a number.
         *  @details Converts a number represented by a `source_number` to a `std::string`.
         */
        template <typename type>
        std::string from ( type source );

        /**
         *  @brief Converts a number from numeric to string representation.
         *  @param [in] source_number A numeric representation of a number.
         *  @returns A string representation of a number.
         *  @details Converts a number represented by a `source_number` to a `std::string`.
         */
        inline std::string from ( signed int source_number );

        /**
         *  @brief Converts a number from numeric to string representation.
         *  @param [in] source_number A numeric representation of a number.
         *  @returns A string representation of a number.
         *  @details Converts a number represented by a `source_number` to a `std::string`.
         */
        inline std::string from ( unsigned int source_number );

        /**
         *  @brief Converts a number from numeric to string representation.
         *  @param [in] source_number A numeric representation of a number.
         *  @returns A string representation of a number.
         *  @details Converts a number represented by a `source_number` to a `std::string`.
         */
        inline std::string from ( float source_number );

        inline std::string reverse ( const std::string& source_string );

        inline strings split ( const std::string& source_string , const std::string& delimiter );

        inline strings split ( const std::string& source_string , char delimiter );

        inline strings split ( const char* source_string_ptr , const char* delimiter_ptr );

        inline std::string replace ( const std::string& source_string , const std::string& search_for , const std::string& replace_with );

        inline std::string replace ( const std::string& source_string , char search_for , char replace_with );

        inline std::string replace ( const char* source_string_ptr , const char* search_for_ptr , const char* replace_with_ptr );

        inline bool is_numeric ( const std::string& source_string );

        inline bool is_integer ( const std::string& source_string );

        inline bool is_fractional ( const std::string& source_string );

    }

}

//  Include an implementation file
#include "string_util.ipp"

#endif  //  _XTD_STRING_UTIL_HPP_
