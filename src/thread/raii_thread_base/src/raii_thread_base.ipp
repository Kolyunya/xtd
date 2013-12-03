namespace std
{

            template <typename function_type , typename... arguments_type>
            raii_thread_base<function_type,arguments_type...>::raii_thread_base ( function_type function , arguments_type... arguments )
                :
                    terminate_flag(false),
                    functor(std::bind(function,arguments...))
    {

    }

            template <typename function_type , typename... arguments_type>
            raii_thread_base<function_type,arguments_type...>::~raii_thread_base ( void ) noexcept
    {

    }

            template <typename function_type , typename... arguments_type>
    void    raii_thread_base<function_type,arguments_type...>::routine ( raii_thread_base* raii_thread_base_ptr )
    {
        while ( true )
        {
            try
            {
                //	Check if the thread is supposed to be terminated
                std::unique_lock<std::mutex> terminate_unique_lock(raii_thread_base_ptr->terminate_mutex,std::defer_lock);
                terminate_unique_lock.try_lock();
                if ( raii_thread_base_ptr->terminate_flag )
                {
                    return;
                }

                //	Run client code
                //(raii_thread_base_ptr->functor)();

                //	Yield to other threads
                std::this_thread::yield();
            }
            catch ( ... )
            {
                //	Ignore errors
            }
        }

    }

}