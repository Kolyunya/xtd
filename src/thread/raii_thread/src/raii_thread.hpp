#ifndef _STD_RAII_THREAD_HPP_
#define _STD_RAII_THREAD_HPP_

#include <thread/raii_thread_base.hpp>

namespace std
{
    template <typename function_type , typename... arguments_type>
    class raii_thread
        :
            public raii_thread_base<function_type,arguments_type...>
    {
        public:
            explicit    raii_thread ( function_type function , arguments_type... arguments );
            virtual     ~raii_thread ( void ) noexcept override;
    };
}

#include "raii_thread.ipp"

#endif  //  _STD_RAII_THREAD_HPP_