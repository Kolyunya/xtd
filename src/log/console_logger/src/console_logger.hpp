#ifndef _CONSOLE_LOGGER_HPP_
#define _CONSOLE_LOGGER_HPP_

#include <iostream>
#include <log/abstract_logger.hpp>



namespace std
{

    class console_logger
        :
            public abstract_logger
    {

        public:

            inline explicit         console_logger ( bool add_new_line = true , bool add_time_stamp = true ) noexcept;

        protected:

            inline virtual void     log_data ( const std::string& data ) const noexcept override;

    };

}

// Include implementation file
#include "console_logger.ipp"

#endif  // _CONSOLE_LOGGER_HPP_