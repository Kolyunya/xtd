#ifndef _STD_PARAMETER_PACK_HPP_
#define _STD_PARAMETER_PACK_HPP_

#include <type_traits>

namespace std
{

    struct parameter_pack
    {

        // REGION HELPER_TYPES

            public:

                struct null_type
                {

                };

        // ENDREGION



        // REGION RETRIEVE_NTH_PARAMETER_TYPE

            private:

                template < int parameter_position , typename... parameters_types >
                struct type_of
                {
                    using type = null_type;
                };

                template < typename first_parameter_type , typename... other_parameters_types >
                struct type_of < 0 , first_parameter_type , other_parameters_types... >
                {
                    using type = first_parameter_type;
                };

                template < int parameter_position , typename first_parameter_type , typename... other_parameters_types >
                struct type_of < parameter_position , first_parameter_type , other_parameters_types... >
                {
                    using type = typename type_of<parameter_position-1,other_parameters_types...>::type;
                };

            public:

                template < int parameter_position , typename... parameters_types >
                struct type_of_nth
                {
                    using type = typename type_of < parameter_position , parameters_types... >::type;
                };

                template < typename... parameters_types >
                struct type_of_first
                {
                    using type = typename type_of_nth < 0 , parameters_types... >::type;
                };

                template < typename... parameters_types >
                struct type_of_last
                {
                    using type = typename type_of_nth < sizeof...(parameters_types) - 1 , parameters_types... >::type;
                };

        // ENDREGION



        // REGION RETRIEVE_NTH_PARAMETER_VALUE

            public:

        // ENDREGION



        // REGION DETECTION_OF_HOMO_AND_HETERO_GENEOUS_PARAMETER_PACKS

        public:

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

        // ENDREGION



        // REGION RETRIEVE_HOMOGENOUS_PARAMETER_PACK_TYPE

            public:

        // ENDREGION

    };

}

#include "parameter_pack.tpp"

#endif  //  _STD_PARAMETER_PACK_HPP_
