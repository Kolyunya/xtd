namespace std
{

            raii_thread_manual::raii_thread_manual ( std::function<void()> client_routine )
                :
                    raii_thread_base(client_routine)
    {

    }

            raii_thread_manual::~raii_thread_manual ( void ) noexcept
    {

    }

    bool    raii_thread_manual::isActive ( void ) const
    {
        return this->thread.joinable();
    }

    void    raii_thread_manual::start ( void )
    {
        this->initializeRoutine();
    }

    void    raii_thread_manual::stop ( void )
    {
        this->deinitializeRoutine();
    }

}