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

#ifndef _XSTD_ABSTRACT_LOGGER_HPP_
#define _XSTD_ABSTRACT_LOGGER_HPP_

#include <string.hpp>
#include <chrono.hpp>

namespace xstd
{

    class abstract_logger
    {

        public:

            inline explicit         abstract_logger ( bool add_new_line = true , bool add_time_stamp = true ) noexcept;

            inline void             log ( const std::string& data ) const noexcept;

            bool                    add_new_line;

            bool                    add_time_stamp;

        protected:

            virtual void            log_data ( const string& data ) const noexcept = 0;

            inline void             log_new_line ( void ) const noexcept;

            inline void             log_time_stamp ( void ) const noexcept;

            inline static string    make_time_stamp ( void ) noexcept;

    };

}

// Include implementation file
#include "abstract_logger.ipp"

#endif  // _XSTD_ABSTRACT_LOGGER_HPP_