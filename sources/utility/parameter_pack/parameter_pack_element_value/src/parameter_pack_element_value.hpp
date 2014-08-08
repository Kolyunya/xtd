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

#ifndef _XSTD_PARAMETER_PACK_ELEMENT_VALUE_HPP_
#define _XSTD_PARAMETER_PACK_ELEMENT_VALUE_HPP_

#include <stdexcept>

namespace xstd
{

    namespace pp
    {

        template < unsigned int parameter_id >
        static auto nth_value ( void )
            ->
                null_type
        {
            throw std::out_of_range("Empty parameter pack");
        }

        template < unsigned int parameter_id , typename first_parameter_type , typename... other_parameters_types >
        static auto nth_value ( first_parameter_type&& first_parameter , other_parameters_types&&... /* other_parameters */ )
            ->
                typename std::enable_if
                <
                    ( parameter_id == 0 ),
                    decltype
                    (
                        std::forward
                        <
                            first_parameter_type
                        >
                        (
                            first_parameter
                        )
                    )
                >
                ::type
        {
            return std::forward
            <
                first_parameter_type
            >
            (
                first_parameter
            );
        }

        template < unsigned int parameter_id , typename first_parameter_type , typename... other_parameters_types >
        static auto nth_value ( first_parameter_type&& /* first_parameter */ , other_parameters_types&&... other_parameters )
            ->
                typename std::enable_if
                <
                    ( parameter_id > 0 ),
                    decltype
                    (
                        std::forward
                        <
                            typename nth_type
                            <
                                parameter_id,
                                first_parameter_type,
                                other_parameters_types...
                            >::type
                        >
                        (
                            std::declval
                            <
                                typename nth_type
                                <
                                    parameter_id,
                                    first_parameter_type,
                                    other_parameters_types...
                                >::type
                            >()
                        )
                    )
                >::type
        {
            return std::forward
            <
                typename nth_type
                <
                    parameter_id,
                    first_parameter_type,
                    other_parameters_types...
                >::type
            >
            (
                nth_value
                <
                    parameter_id-1
                >
                (
                    (
                        std::forward
                        <
                            other_parameters_types
                        >
                        (
                            other_parameters
                        )
                    )
                    ...
                )
            );
        }

        template < typename... parameters_types >
        static auto first_value ( parameters_types&&... parameters )
            ->
                decltype
                (
                    std::forward
                    <
                        typename nth_type
                        <
                            0,
                            parameters_types...
                        >::type
                    >
                    (
                        std::declval
                        <
                            typename nth_type
                            <
                                0,
                                parameters_types...
                            >::type
                        >()
                    )
                )
        {
            return std::forward
            <
                typename nth_type
                <
                    0,
                    parameters_types...
                >::type
            >
            (
                nth_value
                <
                    0
                >
                (
                    (
                        std::forward
                        <
                            parameters_types
                        >
                        (
                            parameters
                        )
                    )
                    ...
                )
            );
        }

        template < typename... parameters_types >
        static auto last_value ( parameters_types&&... parameters )
            ->
                decltype
                (
                    std::forward
                    <
                        typename nth_type
                        <
                            ( sizeof...(parameters) - 1 ),
                            parameters_types...
                        >::type
                    >
                    (
                        std::declval
                        <
                            typename nth_type
                            <
                                ( sizeof...(parameters) - 1 ),
                                parameters_types...
                            >::type
                        >()
                    )
                )
        {
            return std::forward
            <
                typename nth_type
                <
                    ( sizeof...(parameters) - 1 ),
                    parameters_types...
                >::type
            >
            (
                nth_value
                <
                    ( sizeof...(parameters) - 1 )
                >
                (
                    (
                        std::forward
                        <
                            parameters_types
                        >
                        (
                            parameters
                        )
                    )
                    ...
                )
            );
        }

    }

}

#endif  //  _XSTD_PARAMETER_PACK_ELEMENT_VALUE_HPP_