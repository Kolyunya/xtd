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

#ifndef _XSTD_PARAMETER_PACK_ELEMENT_TYPE_HPP_
#define _XSTD_PARAMETER_PACK_ELEMENT_TYPE_HPP_

namespace xstd
{

    namespace pp
    {

        struct null_type
        {
            bool operator== ( const null_type ) const
            {
                return true;
            }
            bool operator!= ( const null_type ) const
            {
                return false;
            }
        };

        template < unsigned int parameter_id , typename... parameters_types >
        struct nth_type_helper
        {
            using type = null_type;
        };

        template < typename first_parameter_type , typename... other_parameters_types >
        struct nth_type_helper < 0 , first_parameter_type , other_parameters_types... >
        {
            using type = first_parameter_type;
        };

        template < unsigned int parameter_id , typename first_parameter_type , typename... other_parameters_types >
        struct nth_type_helper < parameter_id , first_parameter_type , other_parameters_types... >
        {
            using type = typename nth_type_helper<parameter_id-1,other_parameters_types...>::type;
        };

        template < unsigned int parameter_id , typename... parameters_types >
        struct nth_type
        {
            using type = typename nth_type_helper < parameter_id , parameters_types... >::type;
        };

        template < typename... parameters_types >
        struct first_type
        {
            using type = typename nth_type < 0 , parameters_types... >::type;
        };

        template < typename... parameters_types >
        struct last_type
        {
            using type = typename nth_type < sizeof...(parameters_types) - 1 , parameters_types... >::type;
        };

    }

}

#endif  //  _XSTD_PARAMETER_PACK_ELEMENT_TYPE_HPP_