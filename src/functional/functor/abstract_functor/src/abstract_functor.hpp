#ifndef _STD_ABSTRACT_FUNCTOR_HPP_
#define _STD_ABSTRACT_FUNCTOR_HPP_

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
}

#endif  //  _STD_ABSTRACT_FUNCTOR_HPP_