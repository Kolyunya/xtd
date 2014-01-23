#ifndef _STD_PARAMETER_PACK_HPP_
#define _STD_PARAMETER_PACK_HPP_

#include <stdexcept>
#include <type_traits>

namespace std
{

    struct parameter_pack
    {



        // REGION HELPER_TYPES

            public:

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

        // ENDREGION



        // REGION RETRIEVE_NTH_PARAMETER_TYPE

            private:

                template < int parameter_id , typename... parameters_types >
                struct nth_type_helper
                {
                    using type = null_type;
                };

                template < typename first_parameter_type , typename... other_parameters_types >
                struct nth_type_helper < 0 , first_parameter_type , other_parameters_types... >
                {
                    using type = first_parameter_type;
                };

                template < int parameter_id , typename first_parameter_type , typename... other_parameters_types >
                struct nth_type_helper < parameter_id , first_parameter_type , other_parameters_types... >
                {
                    using type = typename nth_type_helper<parameter_id-1,other_parameters_types...>::type;
                };

            public:

                template < int parameter_id , typename... parameters_types >
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

        // ENDREGION



        // REGION RETRIEVE_NTH_PARAMETER_VALUE

            public:

                template < int parameter_id >
                static auto nth_value ( void )
                    ->
                        null_type
                {
                    throw runtime_error("Empty parameter pack");
                }

                template < int parameter_id , typename parameter_type , typename... other_parameters_types >
                static auto nth_value ( parameter_type parameter , other_parameters_types... other_parameters )
                    ->
                        typename enable_if
                        <
                            ( parameter_id == 0 ),
                            decltype(std::forward<parameter_type>(parameter))
                            //parameter_type
                        >
                        ::type
                {
                    return forward<parameter_type>(parameter);
                    //return parameter;
                }

                template < int parameter_id , typename parameter_type , typename... other_parameters_types >
                static auto nth_value ( parameter_type parameter , other_parameters_types... other_parameters )
                    ->
                        typename enable_if
                        <
                            ( parameter_id > 0 ),
                            typename nth_type<parameter_id-1,other_parameters_types...>::type
                        >
                        ::type
                {
                    return nth_value<parameter_id-1,other_parameters_types...>(other_parameters...);
                }

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
                        static const bool value = is_same<first_parameter_type,other_parameters_type>::value;
                        using type = typename conditional<value,first_parameter_type,null_type>::type;
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
