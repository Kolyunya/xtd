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
            inline bool                 get_is_initialized ( void ) const;
        protected:
            inline void                 initialize_routine ( void );
            inline void                 deinitialize_routine ( void );
            inline void                 check_is_initialized ( void ) const;
            inline void                 check_is_not_initialized ( void ) const;
            inline static void          routine ( raii_thread_base* raii_thread_base_ptr );
            bool                        terminate_flag;
            std::function<void()>       client_routine;
            std::thread                 thread;
            std::recursive_mutex        mutex;
        private:
            inline explicit             raii_thread_base ( const raii_thread_base& rhs ) = delete;
            inline raii_thread_base&    operator= ( const raii_thread_base& rhs ) = delete;
    };
}

#include "raii_thread_base.ipp"

#endif  //  _STD_RAII_THREAD_BASE_HPP_
