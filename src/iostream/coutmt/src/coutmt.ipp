namespace std
{

                            template <typename Type>
    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object )
    {
        lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        cout << object;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) )
    {
        lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  ios&(*function_ptr)(ios&) )
    {
        lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       operator<< ( coutmt_singleton& coutmt_singleton_instance ,  ios_base& (*function_ptr)(ios_base&) )
    {
        lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton&       coutmt_singleton::get_instance ( void )
    {
        if ( coutmt_singleton::instance_ptr == nullptr )
        {
            coutmt_singleton::instance_ptr = new coutmt_singleton();
        }
        return *coutmt_singleton::instance_ptr;
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