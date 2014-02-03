#ifndef _STD_PARAMETER_PACK_FOR_EACH_HPP_
#define _STD_PARAMETER_PACK_FOR_EACH_HPP_

namespace std
{

    namespace pp
    {

        template < typename parameter_processor , typename... parameters_types >
        void for_each ( parameters_types... parameters )
        {

        }

        template < typename parameter_processor , typename first_parameter_type , typename... other_parameters_types >
        void for_each ( first_parameter_type first_parameter , other_parameters_types... other_parameters )
        {
            parameter_processor::process(first_parameter);
            for_each<parameter_processor,other_parameters_types...>(other_parameters...);
        }

    }

}

#endif  //  _STD_PARAMETER_PACK_FOR_EACH_HPP_
