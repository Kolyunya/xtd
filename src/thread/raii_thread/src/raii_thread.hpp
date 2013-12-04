#ifndef _STD_RAII_THREAD_HPP_
#define _STD_RAII_THREAD_HPP_

#include <thread/raii_thread_base.hpp>

namespace std
{
    class raii_thread
        :
            public raii_thread_base
    {
        public:
            inline explicit     raii_thread ( std::function<void()> client_routine );
            inline virtual      ~raii_thread ( void ) noexcept override;
    };
}

#include "raii_thread.ipp"

#endif  //  _STD_RAII_THREAD_HPP_