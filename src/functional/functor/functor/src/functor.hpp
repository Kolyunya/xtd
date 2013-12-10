#ifndef _STD_FUNCTOR_HPP_
#define _STD_FUNCTOR_HPP_

//#include <functional/abstract_functor.hpp>

namespace std
{

    template <typename... arguments_type>
    class abstract_functor
    {
        public:
            virtual         ~abstract_functor ( void ) = default;
            virtual void    operator() ( arguments_type... arguments ) const = 0;
            virtual void    invoke ( arguments_type... arguments ) const = 0;
    };

    template <typename object_type , typename... arguments_type>
    class functor
        :
            public abstract_functor<arguments_type...>
    {
        public:
            explicit        functor ( object_type* object_ptr , void(object_type::*method_ptr)(arguments_type...) )
            {
                if
                (
                    object_ptr == nullptr
                        ||
                    method_ptr == nullptr
                )
                {
                    throw -1;
                }
                this->object_ptr = object_ptr;
                this->method_ptr = method_ptr;
            }
            virtual         ~functor ( void ) noexcept override = default;
            virtual void    operator() ( arguments_type... arguments ) const override final
            {
                this->invoke(arguments...);
            }
            virtual void    invoke ( arguments_type... arguments ) const override final
            {
                ((this->object_ptr)->*(this->method_ptr))(arguments...);
            }
            void            (object_type::*method_ptr)(arguments_type...);
            object_type*    object_ptr;
    };
}

// Include implementation file
//#include "functor.tpp"

#endif  // _STD_FUNCTOR_HPP_