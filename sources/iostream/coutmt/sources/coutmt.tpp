namespace xtd
{

    namespace io
    {

        template <typename type>
        coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , type object )
        {
            std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
            std::cout << object;
            return coutmt_singleton_instance;
        }

    }

}