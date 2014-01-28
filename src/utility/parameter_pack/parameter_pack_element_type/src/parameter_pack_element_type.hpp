#ifndef _STD_PARAMETER_PACK_ELEMENT_TYPE_HPP_
#define _STD_PARAMETER_PACK_ELEMENT_TYPE_HPP_

namespace std
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

#endif  //  _STD_PARAMETER_PACK_ELEMENT_TYPE_HPP_
