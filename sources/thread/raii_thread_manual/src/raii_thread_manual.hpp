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

#ifndef _XSTD_RAII_THREAD_MANUAL_HPP_
#define _XSTD_RAII_THREAD_MANUAL_HPP_

#include <thread/raii_thread_base.hpp>

namespace xstd
{
    class raii_thread_manual
        :
            public raii_thread_base
    {
        public:
            inline explicit     raii_thread_manual ( std::function<void()> client_routine );
            inline virtual      ~raii_thread_manual ( void ) noexcept override;
            inline void         start ( void );
            inline void         stop ( void );
    };
}

#include "raii_thread_manual.ipp"

#endif  //  _XSTD_RAII_THREAD_MANUAL_HPP_