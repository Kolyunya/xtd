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

#ifndef _XSTD_RANDOM_HPP_
#define _XSTD_RANDOM_HPP_

#include <stdexcept>    // std::range_error
#include <cstdlib>      // std::rand
#include <ctime>        // std::time

namespace xstd
{

    namespace random
    {

        inline void     randomize ( void );

        inline int      get_int ( int minimum , int maximum );

        inline bool     coin_flip ( float win_rate_percent = 50 );

    }

}

// Include implementation file
#include "random.ipp"

#endif  //  _XSTD_RANDOM_HPP_