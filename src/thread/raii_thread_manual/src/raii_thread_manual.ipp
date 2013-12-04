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

    void    raii_thread_manual::launch ( void )
    {
        this->initializeRoutine();
    }

    void    raii_thread_manual::stop ( void )
    {
        this->deinitializeRoutine();
    }

}