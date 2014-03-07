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

#ifndef _XSTD_COUTMT_HPP_
#define _XSTD_COUTMT_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <mutex>

namespace xstd
{
    class coutmt_singleton
        :
            public std::ostream
    {
        public:
                                                template <typename Type>
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios&(*function_ptr)(std::ios&) );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios_base& (*function_ptr)(std::ios_base&) );
            static inline coutmt_singleton&     get_instance ( void );
        private:
            inline explicit                     coutmt_singleton ( void ) = default;
            std::mutex                          coutmt_mutex;
            bool                                instance_initialized;
    };

    static coutmt_singleton& coutmt = coutmt_singleton::get_instance();
}

#include "coutmt.ipp"

#endif  //  _XSTD_COUTMT_HPP_