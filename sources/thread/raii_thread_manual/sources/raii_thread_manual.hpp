#ifndef _XTD_RAII_THREAD_MANUAL_HPP_
#define _XTD_RAII_THREAD_MANUAL_HPP_

#include <xtd/thread/raii_thread_base.hpp>

namespace xtd
{
    class raii_thread_manual
        :
            public raii_thread_base
    {
        public:
            inline explicit     raii_thread_manual ( std::function<void()> client_routine );
            inline virtual      ~raii_thread_manual ( void ) noexcept override;
            inline void         start ( void );
            inline void         stop ( void );
    };
}

#endif