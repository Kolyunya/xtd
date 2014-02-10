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

    }

    bool    raii_thread_base::get_is_initialized ( void ) const
    {
        return ( this->thread.joinable() == true );
    }

    void    raii_thread_base::initialize_routine ( void )
    {
        std::lock_guard<std::recursive_mutex> lock(this->mutex);
        this->check_is_not_initialized();
        this->terminate_flag = false;
        this->thread = std::thread(raii_thread_base::routine,this);
    }

    void    raii_thread_base::deinitialize_routine ( void )
    {
        std::unique_lock<std::recursive_mutex> lock(this->mutex);
        this->check_is_initialized();
        this->terminate_flag = true;
        lock.unlock();

        //  Join the "thread" only if this function is not executed from it
        //  Omitting the condition will lead to a freeze if this function is executed from the "thread"
        if ( this_thread::get_id() != this->thread.get_id() )
        {
            this->thread.join();
        }

        //  Thread must be joined or detached before termination
        else
        {
            this->thread.detach();
        }

    }

    void    raii_thread_base::check_is_initialized ( void ) const
    {
        if ( this->get_is_initialized() == false )
        {
            throw std::runtime_error("Thread is not initialized");
        }
    }

    void    raii_thread_base::check_is_not_initialized ( void ) const
    {
        if ( this->get_is_initialized() == true )
        {
            throw std::runtime_error("Thread is already initialized");
        }
    }

    void    raii_thread_base::routine ( raii_thread_base* raii_thread_base_ptr )
    {
        while ( true )
        {
            try
            {
                //	Check if the thread is supposed to be terminated
                std::unique_lock<std::recursive_mutex> terminate_unique_lock(raii_thread_base_ptr->mutex,std::defer_lock);
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
