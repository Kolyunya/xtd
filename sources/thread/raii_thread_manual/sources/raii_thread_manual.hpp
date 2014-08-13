#ifndef _XTD_RAII_THREAD_MANUAL_HPP_
#define _XTD_RAII_THREAD_MANUAL_HPP_

#include <xtd/thread/raii_thread_base.hpp>

namespace xtd
{

    namespace thread
    {

        class raii_thread_manual
            :
                public raii_thread_base
        {
            public:
                explicit raii_thread_manual ( std::function<void()> client_routine );
                virtual ~raii_thread_manual ( void ) noexcept override;
                void start ( void );
                void stop ( void );
        };

    }

}

#endif