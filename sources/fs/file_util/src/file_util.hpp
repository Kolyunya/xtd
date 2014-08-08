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

#ifndef _XSTD_FILE_UTIL_HPP_
#define _XSTD_FILE_UTIL_HPP_

#include <stdexcept>        // std::runtime_error
#include <fstream>          // std::ofstream
                            // std::ifstream
#include <sys/types.h>      // off_t
#include <sys/stat.h>       // stat

namespace xstd
{

    namespace fs
    {

        inline bool             get_file_exists ( const std::string& file_path );

        inline off_t            get_file_size ( const std::string& file_path );

        inline off_t            get_file_size ( int file_descriptor );

        inline std::string      get_file_contents ( const std::string& file_path );

        inline void             set_file_contents ( const std::string& file_path , const std::string& data );

        inline void             append_file_contents ( const std::string& file_path , const std::string& data );

        inline void             prepend_file_contents ( const std::string& file_path , const std::string& data );

        inline void             truncate_file_contents ( const std::string& file_path );

        inline void             check_file_exists ( const std::string& file_path );

    }

}

// Include implementation file
#include "file_util.ipp"

#endif // _XSTD_FILE_UTIL_HPP_