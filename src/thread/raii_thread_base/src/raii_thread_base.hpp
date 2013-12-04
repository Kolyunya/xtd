#ifndef _STD_RAII_THREAD_BASE_HPP_
#define _STD_RAII_THREAD_BASE_HPP_

#include <functional>
#include <thread>
#include <mutex>

namespace std
{
    class raii_thread_base
    {
        public:
            inline explicit             raii_thread_base ( std::function<void()> client_routine );
            inline virtual              ~raii_thread_base ( void ) noexcept;
        protected:
            inline void                 initializeRoutine ( void );
            inline void                 deinitializeRoutine ( void );
            inline static void          routine ( raii_thread_base* raii_thread_base_ptr );
            bool                        terminate_flag;
            std::mutex                  terminate_mutex;
            std::function<void()>       client_routine;
            std::thread                 thread;
        private:
            inline explicit             raii_thread_base ( const raii_thread_base& rhs ) = delete;
            inline raii_thread_base&    operator= ( const raii_thread_base& rhs ) = delete;
    };
}

#include "raii_thread_base.ipp"

#endif  //  _STD_RAII_THREAD_BASE_HPP_