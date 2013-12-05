namespace std
{

    coutmt_singleton&       coutmt_singleton::get_instance ( void )
    {
        if ( coutmt_singleton::instance_ptr == nullptr )
        {
            coutmt_singleton::instance_ptr = new coutmt_singleton();
        }
        return *coutmt_singleton::instance_ptr;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance , const char* string )
    {
        std::lock_guard<std::mutex> lockGuard(coutmt_singleton_instance.mutex);
        std::cout << string;
        return coutmt_singleton_instance;
    }

                            coutmt_singleton::~coutmt_singleton ( void ) noexcept
    {
        try
        {
            if ( coutmt_singleton::instance_ptr != nullptr )
            {
                delete coutmt_singleton::instance_ptr;
            }
        }
        catch ( ... )
        {

        }
    }

    coutmt_singleton*       coutmt_singleton::instance_ptr = nullptr;

}