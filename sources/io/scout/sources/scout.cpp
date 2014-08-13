#include "scout.hpp"

namespace xtd
{

    namespace io
    {

        scout_singleton& operator<< ( scout_singleton& scout_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) )
        {
            std::lock_guard<std::mutex> lock_guard(scout_singleton_instance.scout_mutex);
            std::cout << function_ptr;
            return scout_singleton_instance;
        }

        scout_singleton& operator<< ( scout_singleton& scout_singleton_instance ,  std::ios&(*function_ptr)(std::ios&) )
        {
            std::lock_guard<std::mutex> lock_guard(scout_singleton_instance.scout_mutex);
            std::cout << function_ptr;
            return scout_singleton_instance;
        }

        scout_singleton& operator<< ( scout_singleton& scout_singleton_instance ,  std::ios_base& (*function_ptr)(std::ios_base&) )
        {
            std::lock_guard<std::mutex> lock_guard(scout_singleton_instance.scout_mutex);
            std::cout << function_ptr;
            return scout_singleton_instance;
        }

        scout_singleton& scout_singleton::get_instance ( void )
        {

            static std::unique_ptr<scout_singleton> scout_instance_unique_prt;

            if ( scout_instance_unique_prt == nullptr )
            {
                scout_instance_unique_prt.reset(new scout_singleton());
            }

            return *scout_instance_unique_prt;
        }

    }

}