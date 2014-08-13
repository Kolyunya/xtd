namespace xtd
{

    namespace io
    {

        template <typename type>
        scout_singleton& operator<< ( scout_singleton& scout_singleton_instance , type object )
        {
            std::lock_guard<std::mutex> lock_guard(scout_singleton_instance.scout_mutex);
            std::cout << object;
            return scout_singleton_instance;
        }

    }

}