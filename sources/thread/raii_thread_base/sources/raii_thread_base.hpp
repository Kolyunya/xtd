#ifndef _XTD_RAII_THREAD_BASE_HPP_
#define _XTD_RAII_THREAD_BASE_HPP_

#include <functional>
#include <thread>
#include <mutex>

namespace xtd
{

    namespace thread
    {

        class raii_thread_base
        {
            public:
                explicit raii_thread_base ( std::function<void()> client_routine );
                virtual ~raii_thread_base ( void ) noexcept;
                bool get_is_initialized ( void ) const;
            protected:
                void initialize_routine ( void );
                void deinitialize_routine ( void );
                void check_is_initialized ( void ) const;
                void check_is_not_initialized ( void ) const;
                static void routine ( raii_thread_base* raii_thread_base_ptr );
                bool                        terminate_flag;
                std::function<void()> client_routine;
                std::thread thread;
                std::recursive_mutex mutex;
            private:
                explicit raii_thread_base ( const raii_thread_base& rhs ) = delete;
                raii_thread_base& operator= ( const raii_thread_base& rhs ) = delete;
        };

    }

}

#endif