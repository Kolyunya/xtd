namespace std
{

    raii_thread::raii_thread ( std::function<void()> client_routine )
        :
            raii_thread_base(client_routine)
    {
        this->initializeRoutine();
    }

    raii_thread::~raii_thread ( void ) noexcept
    {

    }

}