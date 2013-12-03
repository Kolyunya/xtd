#ifndef _STD_RAII_THREAD_BASE_HPP_
#define _STD_RAII_THREAD_BASE_HPP_

#include <functional>
#include <thread>
#include <mutex>

namespace std
{
    template <typename function_type , typename... arguments_type>
    class raii_thread_base
    {
        public:
            explicit                        raii_thread_base ( function_type function , arguments_type... arguments );
            virtual                         ~raii_thread_base ( void ) noexcept;
        protected:
            void                            initializeRoutine ( void );
            void                            deinitializeRoutine ( void );
            static void                     routine ( raii_thread_base* raii_thread_base_ptr );
            bool                            terminate_flag;
            std::mutex                      terminate_mutex;
            std::function<void()>           functor;
            std::thread                     thread;
        private:
            explicit                        raii_thread_base ( const raii_thread_base& rhs ) = delete;
            raii_thread_base&               operator= ( const raii_thread_base& rhs ) = delete;
    };
}

#include "raii_thread_base.ipp"

#endif  //  _STD_RAII_THREAD_BASE_HPP_