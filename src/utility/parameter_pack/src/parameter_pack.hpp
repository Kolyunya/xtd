#ifndef _STD_PARAMETER_PACK_HPP_
#define _STD_PARAMETER_PACK_HPP_

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



    #pragma region DETECTION_OF_HOMOGENEOUS_PARAMETER_PACKS

        template < typename... parameters >
        bool is_homogeneous_parameter_pack ( void )
        {
            return true;
        }

    #pragma endregion

}

#include "parameter_pack.tpp"

#endif  //  _STD_PARAMETER_PACK_HPP_