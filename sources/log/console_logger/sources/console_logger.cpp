#include "console_logger.hpp"

namespace xtd
{

    namespace log
    {

        console_logger::console_logger ( bool add_new_line , bool add_time_stamp ) noexcept
            :
                abstract_logger(add_new_line,add_time_stamp)
        {

        }

        void console_logger::log_data ( const std::string& data ) const noexcept
        {

            xtd::io::scout << data;

        }

    }

}