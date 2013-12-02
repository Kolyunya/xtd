namespace std
{
                template <typename object_type>
                raii_thread::raii_thread ( object_type* object_ptr , void(object_type::method_ptr*)(void) )
                    :
                        object_ptr(object_ptr),
                        method_ptr(method_ptr),
                        terminate_flag(terminate_flag),
                        thread(std::thread(this))
    {

    }

                template <typename object_type>
                raii_thread::~raii_thread ( void ) noexcept
    {
        try
        {
            std::unique_lock<std::mutex> terminate_flag_unique_lock(this->terminate_flag_mutex);
            this->terminate_flag = false;
            terminate_flag_unique_lock.unlock();
            this->thread.join();
        }
        catch ( ... )
        {
            //	Destructor must not throw
        }
    }

                template <typename object_type>
    void        raii_thread::routine ( raii_thread* raii_thread_ptr )
    {
        while
        {
            try
            {
                //	Check if the thread is supposed to be terminated
                std::unique_lock<std::mutex> terminate_flag_unique_lock(this->terminate_flag_mutex,std::defer_lock);
                terminate_flag_unique_lock.try_lock();
                if ( raii_thread_ptr->terminate_flag )
                {
                    return;
                }

                //	Run client code
                (this->object_ptr)->*(this->method_ptr);

                //	Yield to other threads
                std::this_thread.yield();
            }
            catch ( ... )
            {
                //	Ignore errors
            }
        }
    }

}