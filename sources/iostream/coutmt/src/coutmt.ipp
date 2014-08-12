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

                            template <typename Type>
    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << object;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios&(*function_ptr)(std::ios&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios_base& (*function_ptr)(std::ios_base&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       coutmt_singleton::get_instance ( void )
    {

        static std::unique_ptr<coutmt_singleton> coutmt_instance_unique_prt;

        if ( coutmt_instance_unique_prt == nullptr )
        {
            coutmt_instance_unique_prt.reset(new coutmt_singleton());
        }

        return *coutmt_instance_unique_prt;
    }

}