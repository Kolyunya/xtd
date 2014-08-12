#ifndef _XTD_FUNCTOR_HPP_
#define _XTD_FUNCTOR_HPP_

#include <xtd/functional/abstract_functor.hpp>

namespace xtd
{

    namespace io
    {

        template <typename object_type , typename... arguments_type>
        class functor
            :
                public abstract_functor<arguments_type...>
        {

            public:

                explicit functor ( object_type* object_ptr , void(object_type::*method_ptr)(arguments_type...) );

                virtual ~functor ( void ) noexcept override = default;

                virtual void operator() ( arguments_type... arguments ) const override final;

                virtual void invoke ( arguments_type... arguments ) const override final;

                void (object_type::*method_ptr)(arguments_type...);

                object_type* object_ptr;

        };

    }

}

//  Include definions of templates
#include "functor.tpp"

#endif