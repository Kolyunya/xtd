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

#ifndef _XSTD_LOGGER_CLIENT_HPP_
#define _XSTD_LOGGER_CLIENT_HPP_

#include <log/abstract_logger.hpp>

namespace xstd
{

    class logger_client
    {

        public:

            inline explicit             logger_client ( abstract_logger* logger_ptr = nullptr );

            inline abstract_logger&     get_logger_ref ( void );

            inline abstract_logger*     get_logger_ptr ( void );

            inline void                 set_logger ( abstract_logger* logger_ptr = nullptr );

            inline void                 log ( const std::string& data ) const;

        protected:

            abstract_logger*            logger_ptr;

    };

}

// Include implementation file
#include "logger_client.ipp"

#endif // _XSTD_LOGGER_CLIENT_HPP_