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

                    abstract_logger::abstract_logger ( bool add_new_line , bool add_time_stamp ) noexcept
                        :
                            add_new_line(add_new_line),
                            add_time_stamp(add_time_stamp)
    {

    }

    void            abstract_logger::log ( const std::string& data ) const noexcept
    {

        this->log_time_stamp();
        this->log_data(data);
        this->log_new_line();

    }

    void            abstract_logger::log_new_line ( void ) const noexcept
    {

        if ( this->add_new_line )
        {

            this->log_data("\n");

        }

    }

    void            abstract_logger::log_time_stamp ( void ) const noexcept
    {

        if ( this->add_time_stamp )
        {

            this->log_data(abstract_logger::make_time_stamp() + " - ");

        }

    }

    std::string     abstract_logger::make_time_stamp ( void ) noexcept
    {

        std::chrono::time_point<std::chrono::steady_clock> time_current = std::chrono::steady_clock::now();
        std::string time_current_string = xstd::chrono::time_point_to_formatted_string(time_current);

        return time_current_string;

    }

}