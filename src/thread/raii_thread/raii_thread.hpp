#ifndef _STD_RAII_THREAD_HPP_
#define _STD_RAII_THREAD_HPP_

#include <thread>

namespace std
{
    template <typename object_type>
    class raii_thread
    {
        public:
            explicit        raii_thread ( object_type* object_ptr , void(object_type::method_ptr*)(object_type*) );
            virtual         ~raii_thread ( void ) noexcept;
        protected:
            void            routine ( raii_thread* raii_thread_ptr );
            object_type*    object_ptr;
            void            (object_type::method_ptr)(void);
            bool            terminate_flag;
            std::mutex      terminate_flag_mutex;
            std::thread     thread;
    };
}

#include "raii_thread.ipp"

#endif  //  _STD_RAII_THREAD_HPP_