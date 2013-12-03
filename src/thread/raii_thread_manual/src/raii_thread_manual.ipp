namespace std
{

            template <typename function_type , typename... arguments_type>
            raii_thread_manual<function_type,arguments_type...>::raii_thread_manual ( function_type function , arguments_type... arguments )
                :
                    functor(std::bind(function,arguments...))
    {

    }

            template <typename function_type , typename... arguments_type>
            raii_thread_manual<function_type,arguments_type...>::~raii_thread_manual ( void ) noexcept
    {
        try
        {
            this->stop();
        }
        catch ( ... )
        {
            //	Destructor must not throw
        }
    }

            template <typename function_type , typename... arguments_type>
    void    raii_thread_manual<function_type,arguments_type...>::launch ( void )
    {


    }

            template <typename function_type , typename... arguments_type>
    void    raii_thread_manual<function_type,arguments_type...>::stop ( void )
    {


    }

}