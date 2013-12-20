namespace std
{

            raii_thread_manual::raii_thread_manual ( std::function<void()> client_routine )
                :
                    raii_thread_base(client_routine)
    {
        std::cout << "raii_thread_manual::raii_thread_manual" <<std::endl;

    }

            raii_thread_manual::~raii_thread_manual ( void ) noexcept
    {
        std::cout << "raii_thread_manual::~raii_thread_manual" <<std::endl;
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
        std::cout << "raii_thread_manual::start" << std::endl;
        this->initialize_routine();
    }

    void    raii_thread_manual::stop ( void )
    {
        std::cout << "raii_thread_manual::stop" << std::endl;
        this->deinitialize_routine();
    }

}