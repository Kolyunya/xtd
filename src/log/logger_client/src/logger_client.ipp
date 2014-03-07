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

namespace xstd
{

                        logger_client::logger_client ( abstract_logger* logger_ptr )
    {

        this->set_logger(logger_ptr);

    }

    abstract_logger&    logger_client::get_logger_ref ( void )
    {

        return * this->logger_ptr;

    }

    abstract_logger*    logger_client::get_logger_ptr ( void )
    {

        return this->logger_ptr;

    }

    void                logger_client::set_logger ( abstract_logger* logger_ptr )
    {

        this->logger_ptr = logger_ptr;

    }

    void                logger_client::log ( const std::string& data ) const
    {

        if ( this->logger_ptr )
        {

            this->logger_ptr->log(data);

        }

    }

}