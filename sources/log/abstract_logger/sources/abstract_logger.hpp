#ifndef _XTD_ABSTRACT_LOGGER_HPP_
#define _XTD_ABSTRACT_LOGGER_HPP_

#include <xtd/string.hpp>
#include <xtd/chrono.hpp>

namespace xtd
{

    namespace log
    {

        class abstract_logger
        {

            public:

                explicit abstract_logger ( bool add_new_line = true , bool add_time_stamp = true ) noexcept;

                void log ( const std::string& data ) const noexcept;

                bool add_new_line;

                bool add_time_stamp;

            protected:

                virtual void log_data ( const std::string& data ) const noexcept = 0;

                void log_new_line ( void ) const noexcept;

                void log_time_stamp ( void ) const noexcept;

                static std::string make_time_stamp ( void ) noexcept;

        };

    }

}

#endif