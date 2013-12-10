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
            explicit        functor ( object_type* objectPtr , void(object_type::*methodPtr)(arguments_type...) )
            {
                if
                (
                    objectPtr == nullptr
                        ||
                    methodPtr == nullptr
                )
                {
                    throw -1;
                }
                this->objectPtr = objectPtr;
                this->methodPtr = methodPtr;
            }
            virtual         ~functor ( void ) noexcept override = default;
            virtual void    operator() ( arguments_type... arguments ) const override final
            {
                this->invoke(arguments...);
            }
            virtual void    invoke ( arguments_type... arguments ) const override final
            {
                ((this->objectPtr)->*(this->methodPtr))(arguments...);
            }
            void            (object_type::*methodPtr)(arguments_type...);
            object_type*    objectPtr;
    };
}

// Include implementation file
//#include "functor.tpp"

#endif  // _STD_FUNCTOR_HPP_