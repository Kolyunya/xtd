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

#ifndef _XSTD_MEMORY_UTIL_HPP_
#define _XSTD_MEMORY_UTIL_HPP_

#include <stdexcept>    // std::runtime_error

namespace xstd
{

                            template <typename Type>
    inline static void      validate_pointer ( Type* pointer );

}

// Include implementation file
#include "memory_util.tpp"

#endif  // _XSTD_MEMORY_UTIL_HPP_