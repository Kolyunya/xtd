#ifndef _STD_PARAMETER_PACK_FOR_EACH_HPP_
#define _STD_PARAMETER_PACK_FOR_EACH_HPP_

namespace std
{

    namespace pp
    {

        template < typename type >
        using parameter_processor = void(*)(type);

        template < void(*processor)(int) , typename... parameters_types >
        void for_each ( parameters_types... parameters )
        {

        }

        template < void(*processor)(int) , typename first_parameter_type , typename... other_parameters_types >
        void for_each ( first_parameter_type first_parameter , other_parameters_types... other_parameters )
        {
            processor(first_parameter);
            for_each<other_parameters_types...>(processor,other_parameters...);
        }

    }

}

#endif  //  _STD_PARAMETER_PACK_FOR_EACH_HPP_