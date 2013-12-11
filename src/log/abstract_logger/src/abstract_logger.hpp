#ifndef _ABSTRACT_LOGGER_HPP_
#define _ABSTRACT_LOGGER_HPP_

#include <string.hpp>
#include <chrono.hpp>



namespace std
{

    class abstract_logger
    {

        public:

            inline explicit         abstract_logger ( bool add_new_line = true , bool add_time_stamp = true ) noexcept;

            inline void             log ( const string& data ) const noexcept;

            bool                    add_new_line;

            bool                    add_time_stamp;

        protected:

            virtual void            log_data ( const string& data ) const noexcept = 0;

            inline void             log_new_line ( void ) const noexcept;

            inline void             log_time_stamp ( void ) const noexcept;

            inline static string    make_time_stamp ( void ) noexcept;

    };

}

// Include implementation file
#include "abstract_logger.ipp"

#endif  // _ABSTRACT_LOGGER_HPP_