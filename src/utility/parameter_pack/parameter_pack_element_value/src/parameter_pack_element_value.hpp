#ifndef _STD_PARAMETER_PACK_ELEMENT_VALUE_HPP_
#define _STD_PARAMETER_PACK_ELEMENT_VALUE_HPP_

#include <stdexcept>

namespace std
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
        static auto nth_value ( first_parameter_type&& first_parameter , other_parameters_types&&... other_parameters )
            ->
                typename enable_if
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
            return forward
            <
                first_parameter_type
            >
            (
                first_parameter
            );
        }

        template < unsigned int parameter_id , typename first_parameter_type , typename... other_parameters_types >
        static auto nth_value ( first_parameter_type&& first_parameter , other_parameters_types&&... other_parameters )
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

#endif  //  _STD_PARAMETER_PACK_ELEMENT_VALUE_HPP_
