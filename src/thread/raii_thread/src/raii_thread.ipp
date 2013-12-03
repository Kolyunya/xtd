namespace std
{

    template <typename function_type , typename... arguments_type>
    raii_thread<function_type,arguments_type...>::raii_thread ( function_type function , arguments_type... arguments )
        :
            raii_thread_base<function_type,arguments_type...>(function,arguments...)
    {
        this->thread = std::thread(raii_thread_base<function_type,arguments_type...>::routine,this);
    }

    template <typename function_type , typename... arguments_type>
    raii_thread<function_type,arguments_type...>::~raii_thread ( void ) noexcept
    {
        try
        {
            std::unique_lock<std::mutex> terminate_unique_lock(this->terminate_mutex);
            this->terminate_flag = true;
            terminate_unique_lock.unlock();
            this->thread.join();
        }
        catch ( ... )
        {
            //	Destructor must not throw
        }
    }

}