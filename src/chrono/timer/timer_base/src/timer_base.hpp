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

#ifndef _XSTD_TIMER_BASE_HPP_
#define _XSTD_TIMER_BASE_HPP_

#include <vector>

namespace xstd
{

    namespace chrono
    {

        class timer_base
        {

            public:

                virtual         ~timer_base ( void ) noexcept = default;

                virtual void    tick ( void ) = 0;

        };

        using timers_vector = std::vector<timer_base*>;

        using timers_vector_citr = timers_vector::const_iterator;

        using timers_vector_itr = timers_vector::iterator;

    }

}

#endif  //  _XSTD_TIMER_BASE_HPP_