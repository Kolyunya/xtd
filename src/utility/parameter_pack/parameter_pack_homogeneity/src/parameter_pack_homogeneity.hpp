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

#ifndef _XSTD_PARAMETER_PACK_HOMOGENEITY_HPP_
#define _XSTD_PARAMETER_PACK_HOMOGENEITY_HPP_

#include <type_traits>

namespace xstd
{

    namespace pp
    {

        template < typename... parameters_types >
        struct is_homogeneous
        {
            static const bool value = true;
            using type = null_type;
        };

        template < typename parameter_type >
        struct is_homogeneous < parameter_type >
        {
            static const bool value = true;
            using type = parameter_type;
        };

        template < typename first_parameter_type , typename... other_parameters_types >
        struct is_homogeneous < first_parameter_type , other_parameters_types... >
        {
            private:
                using other_parameters_type = typename is_homogeneous<other_parameters_types...>::type;
            public:
                static const bool value = std::is_same<first_parameter_type,other_parameters_type>::value;
                using type = typename std::conditional<value,first_parameter_type,null_type>::type;
        };

        template < typename... parameters_types >
        struct is_heterogeneous
        {
            static const bool value = ! is_homogeneous<parameters_types...>::value;
        };

    }

}

#endif  //  _XSTD_PARAMETER_PACK_HOMOGENEITY_HPP_
