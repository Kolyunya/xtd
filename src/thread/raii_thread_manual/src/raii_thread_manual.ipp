namespace std
{

            template <typename function_type , typename... arguments_type>
            raii_thread_manual<function_type,arguments_type...>::raii_thread_manual ( function_type function , arguments_type... arguments )
                :
                    raii_thread_base<function_type,arguments_type...>(function,arguments...)
    {

    }

            template <typename function_type , typename... arguments_type>
            raii_thread_manual<function_type,arguments_type...>::~raii_thread_manual ( void ) noexcept
    {

    }

            template <typename function_type , typename... arguments_type>
    void    raii_thread_manual<function_type,arguments_type...>::launch ( void )
    {
        this->initializeRoutine();
    }

            template <typename function_type , typename... arguments_type>
    void    raii_thread_manual<function_type,arguments_type...>::stop ( void )
    {
        this->deinitializeRoutine();
    }

}