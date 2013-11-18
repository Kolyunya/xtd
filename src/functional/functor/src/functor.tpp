namespace std
{

            template <typename object_type , typename parameter_type>
            functor<object_type,parameter_type>::functor ( object_type* object_ptr , void(object_type::*method_ptr)(parameter_type*) )
                :
                    object_ptr ( object_ptr ),
                    method_ptr ( method_ptr )
    {

    }

            template <typename object_type , typename parameter_type>
    void    functor<object_type,parameter_type>::operator() ( void* parameter_void_ptr ) const
    {

        parameter_type* parameter_ptr = reinterpret_cast<parameter_type*>(parameter_void_ptr);
        ( this->object_ptr ->* this->method_ptr ) ( parameter_ptr );

    }

            template <typename object_type , typename parameter_type>
    void    functor<object_type,parameter_type>::invoke ( void* parameter_void_ptr ) const
    {

        parameter_type* parameter_ptr = reinterpret_cast<parameter_type*>(parameter_void_ptr);
        ( *this ) ( parameter_ptr );

    }

}