namespace xtd
{

    namespace io
    {

        template <typename object_type , typename parameter_type>
        functor<object_type,parameter_type>::functor ( object_type* object_ptr , void(object_type::*method_ptr)(parameter_type*) )
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

        template <typename object_type , typename parameter_type>
        void functor<object_type,parameter_type>::operator() ( void* parameter_void_ptr ) const
        {
            this->invoke(arguments...);
        }

        template <typename object_type , typename parameter_type>
        void functor<object_type,parameter_type>::invoke ( void* parameter_void_ptr ) const
        {
            ((this->object_ptr)->*(this->method_ptr))(arguments...);
        }

    }

}