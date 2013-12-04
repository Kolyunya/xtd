namespace std
{

            raii_thread_base::raii_thread_base ( std::function<void()> client_routine )
                :
                    terminate_flag(false),
                    client_routine(client_routine)
    {

    }

            raii_thread_base::~raii_thread_base ( void ) noexcept
    {
        this->deinitializeRoutine();
    }

    void    raii_thread_base::initializeRoutine ( void )
    {
        this->thread = std::thread(raii_thread_base::routine,this);
    }

    void    raii_thread_base::deinitializeRoutine ( void )
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

    void    raii_thread_base::routine ( raii_thread_base* raii_thread_base_ptr )
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
                (raii_thread_base_ptr->client_routine)();

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