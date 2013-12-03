#ifndef _STD_RAII_THREAD_MANUAL_HPP_
#define _STD_RAII_THREAD_MANUAL_HPP_

#include <thread/raii_thread_base.hpp>

namespace std
{
    template <typename function_type , typename... arguments_type>
    class raii_thread_manual
        :
            public raii_thread_base<function_type,arguments_type...>
    {
        public:
            explicit                        raii_thread_manual ( function_type function , arguments_type... arguments );
            virtual                         ~raii_thread_manual ( void ) noexcept override;
            void                            launch ( void );
            void                            stop ( void );
        protected:
            std::function<function_type>    functor;
    };
}

#include "raii_thread_manual.ipp"

#endif  //  _STD_RAII_THREAD_MANUAL_HPP_