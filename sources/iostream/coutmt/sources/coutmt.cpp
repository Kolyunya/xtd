#include "coutmt.hpp"

namespace xstd
{

    template <typename Type>
    coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << object;
        return coutmt_singleton_instance;
    }

    coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios&(*function_ptr)(std::ios&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios_base& (*function_ptr)(std::ios_base&) )
    {
        std::lock_guard<std::mutex> lock_guard(coutmt_singleton_instance.coutmt_mutex);
        std::cout << function_ptr;
        return coutmt_singleton_instance;
    }

    coutmt_singleton& coutmt_singleton::get_instance ( void )
    {

        static std::unique_ptr<coutmt_singleton> coutmt_instance_unique_prt;

        if ( coutmt_instance_unique_prt == nullptr )
        {
            coutmt_instance_unique_prt.reset(new coutmt_singleton());
        }

        return *coutmt_instance_unique_prt;
    }

}