namespace std
{

            template <typename function_type , typename... arguments_type>
            raii_thread<function_type,arguments_type...>::raii_thread ( function_type&& function , arguments_type&&... arguments )
                :
                    terminate_flag(false),
                    thread(std::thread(raii_thread::routine,this,function,arguments...))
    {

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

            template <typename function_type , typename... arguments_type>
    void    raii_thread<function_type,arguments_type...>::routine ( raii_thread* raii_thread_ptr , function_type&& function , arguments_type&&... arguments )
    {
        while ( true )
        {
            try
            {
                //	Check if the thread is supposed to be terminated
                std::unique_lock<std::mutex> terminate_unique_lock(raii_thread_ptr->terminate_mutex,std::defer_lock);
                terminate_unique_lock.try_lock();
                if ( raii_thread_ptr->terminate_flag )
                {
                    return;
                }

                //	Run client code
                (std::bind(function,arguments...))();

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