#ifndef _XTD_RAII_THREAD_HPP_
#define _XTD_RAII_THREAD_HPP_

#include <xtd/thread/raii_thread_base.hpp>

namespace xtd
{
    class raii_thread
        :
            public raii_thread_base
    {
        public:
            explicit     raii_thread ( std::function<void()> client_routine );
            virtual      ~raii_thread ( void ) noexcept override;
    };
}

#endif