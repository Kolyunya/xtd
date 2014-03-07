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

#ifndef _XSTD_FILE_LOGGER_HPP_
#define _XSTD_FILE_LOGGER_HPP_

#include <fs.hpp>
#include <log/abstract_logger.hpp>

namespace std
{

    class file_logger
        :
            public abstract_logger
    {

        public:

            inline explicit         file_logger ( const std::string& file , bool add_new_line = true , bool add_time_stamp = true ) noexcept;

        protected:

            inline virtual void     log_data ( const std::string& data ) const noexcept override;

            std::string             file;

    };

}

// Include implementation file
#include "file_logger.ipp"

#endif  //  _XSTD_FILE_LOGGER_HPP_