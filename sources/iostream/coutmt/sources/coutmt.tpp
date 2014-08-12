namespace xstd
{

    template <typename Type>
    coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << object;
        return coutmt_singleton_instance;
    }

}