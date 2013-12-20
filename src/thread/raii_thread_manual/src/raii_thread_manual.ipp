namespace std
{

            raii_thread_manual::raii_thread_manual ( std::function<void()> client_routine )
                :
                    raii_thread_base(client_routine)
    {

    }

            raii_thread_manual::~raii_thread_manual ( void ) noexcept
    {
        try
        {
            if ( this->get_is_initialized() == true )
            {
                this->stop();
            }
        }
        catch ( ... )
        {

        }
    }

    void    raii_thread_manual::start ( void )
    {
        this->initialize_routine();
    }

    void    raii_thread_manual::stop ( void )
    {
        this->deinitialize_routine();
    }

}