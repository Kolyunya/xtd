#ifndef _STD_PARAMETER_PACK_HOMOGENEITY_HPP_
#define _STD_PARAMETER_PACK_HOMOGENEITY_HPP_

#include <type_traits>

namespace std
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
                static const bool value = is_same<first_parameter_type,other_parameters_type>::value;
                using type = typename conditional<value,first_parameter_type,null_type>::type;
        };

        template < typename... parameters_types >
        struct is_heterogeneous
        {
            static const bool value = ! is_homogeneous<parameters_types...>::value;
        };

    }

}

#endif  //  _STD_PARAMETER_PACK_HOMOGENEITY_HPP_
