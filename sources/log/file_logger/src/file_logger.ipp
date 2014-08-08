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

            file_logger::file_logger ( const std::string& file , bool add_new_line , bool add_time_stamp ) noexcept
                :
                    abstract_logger(add_new_line,add_time_stamp),
                    file(file)
    {

    }

    void    file_logger::log_data ( const std::string& data ) const noexcept
    {

        fs::append_file_contents(file,data);

    }

}