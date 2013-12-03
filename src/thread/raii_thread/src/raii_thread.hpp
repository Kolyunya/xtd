#ifndef _STD_RAII_THREAD_HPP_
#define _STD_RAII_THREAD_HPP_

#include <thread>
#include <mutex>

namespace std
{

    template <typename function_type , typename... arguments_type>
    class raii_thread
    {
        public:
            explicit        raii_thread ( function_type&& function , arguments_type&&... arguments );
            virtual         ~raii_thread ( void ) noexcept;
        protected:
            static void     routine ( raii_thread* raii_thread_ptr , function_type&& function , arguments_type&&... arguments );
            bool            terminate_flag;
            std::mutex      terminate_mutex;
            std::thread     thread;
    };
}

#include "raii_thread.ipp"

#endif  //  _STD_RAII_THREAD_HPP_