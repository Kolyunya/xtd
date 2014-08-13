namespace xtd
{

    namespace functional
    {

        template <typename object_type , typename... arguments_type>
        functor<object_type,arguments_type...>::functor ( object_type* object_ptr , void(object_type::*method_ptr)(arguments_type...) )
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

        template <typename object_type , typename... arguments_type>
        void functor<object_type,arguments_type...>::operator() ( arguments_type... arguments ) const
        {
            this->invoke(arguments...);
        }

        template <typename object_type , typename... arguments_type>
        void functor<object_type,arguments_type...>::invoke ( arguments_type... arguments ) const
        {
            ((this->object_ptr)->*(this->method_ptr))(arguments...);
        }

    }

}