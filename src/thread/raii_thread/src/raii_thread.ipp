namespace std
{

    template <typename function_type , typename... arguments_type>
    raii_thread<function_type,arguments_type...>::raii_thread ( function_type* function_ptr , arguments_type... arguments )
        :
            raii_thread_base<function_type,arguments_type...>(function_ptr,arguments...)
    {
        this->initializeRoutine();
    }

    template <typename function_type , typename... arguments_type>
    raii_thread<function_type,arguments_type...>::~raii_thread ( void ) noexcept
    {

    }

}