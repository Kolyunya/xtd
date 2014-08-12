#ifndef _XTD_ABSTRACT_FUNCTOR_HPP_
#define _XTD_ABSTRACT_FUNCTOR_HPP_

namespace xtd
{

    namespace fn
    {

        template <typename... arguments_type>
        class abstract_functor
        {
            public:
                virtual ~abstract_functor ( void ) = default;
                virtual void operator() ( arguments_type... arguments ) const = 0;
                virtual void invoke ( arguments_type... arguments ) const = 0;
        };

    }

}

#endif