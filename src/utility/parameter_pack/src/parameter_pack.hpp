#ifndef _STD_PARAMETER_PACK_HPP_
#define _STD_PARAMETER_PACK_HPP_

#include <type_traits>

namespace std
{

    #pragma region RETRIEVE_NTH_PARAMETER_TYPE

        template < int parameter_position , typename... parameters_types >
        struct type_of
        {

        };

        template < typename first_parameter_type , typename... other_parameters_types >
        struct type_of < 0 , first_parameter_type , other_parameters_types... >
        {
            using type = first_parameter_type;
        };

        template < int parameter_position , typename first_parameter_type , typename... other_parameters_types >
        struct type_of < parameter_position , first_parameter_type , other_parameters_types... >
        {
            using type = typename type_of < parameter_position - 1 , other_parameters_types... >::type;
        };

        template < typename... parameters >
        struct type_of_first
        {
            using type = typename type_of < 0 , parameters... >::type;
        };

        template < typename... parameters >
        struct type_of_last
        {
            using type = typename type_of < sizeof...(parameters) - 1 , parameters... >::type;
        };

    #pragma endregion



    #pragma region RETRIEVE_NTH_PARAMETER_VALUE
    #pragma endregion



    #pragma region DETECTION_OF_HOMO_AND_HETERO_GENEOUS_PARAMETER_PACKS

        template < typename... parameters_types >
        auto parameter_pack_is_homogeneous ( void )
            ->
                typename std::enable_if<(sizeof...(parameters_types) < 2),bool>::type
        {
            return true;
        }

        template < typename first_parameter_type , typename second_parameter_type , typename... other_parameters_types >
        bool parameter_pack_is_homogeneous ( void )
        {

            std::size_t first_parameter_type_hash_code = typeid(first_parameter_type).hash_code();
            std::size_t second_parameter_type_hash_code = typeid(second_parameter_type).hash_code();
            bool first_and_second_parameters_types_hash_codes_are_equal = first_parameter_type_hash_code == second_parameter_type_hash_code;

            if ( first_and_second_parameters_types_hash_codes_are_equal == false )
            {
                return false;
            }

            std::size_t parameters_pack_size = sizeof...(other_parameters_types);
            if ( parameters_pack_size == 0 )
            {
                return true;
            }

            return parameter_pack_is_homogeneous<second_parameter_type,other_parameters_types...>();

        }

        template < typename... parameters_types >
        auto parameter_pack_is_heterogeneous ( void )
            ->
                typename std::enable_if<(sizeof...(parameters_types) < 2),bool>::type
        {
            return ! parameter_pack_is_homogeneous<parameters_types...>();
        }

        template < typename first_parameter_type , typename second_parameter_type , typename... other_parameters_types >
        bool parameter_pack_is_heterogeneous ( void )
        {
            return ! parameter_pack_is_homogeneous<first_parameter_type,second_parameter_type,other_parameters_types...>();
        }


    #pragma endregion

}

#include "parameter_pack.tpp"

#endif  //  _STD_PARAMETER_PACK_HPP_
