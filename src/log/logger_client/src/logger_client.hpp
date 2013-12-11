#ifndef _LOGGER_CLIENT_HPP_
#define _LOGGER_CLIENT_HPP_

#include <log/abstract_logger.hpp>



namespace std
{

    class logger_client
    {

        public:

            inline explicit             logger_client ( abstract_logger* logger_ptr = nullptr );

            inline abstract_logger&     get_logger_ref ( void );

            inline abstract_logger*     get_logger_ptr ( void );

            inline void                 set_logger ( abstract_logger* logger_ptr = nullptr );

            inline void                 log ( const std::string& data ) const;

        protected:

            abstract_logger*            logger_ptr;

    };

}

// Include implementation file
#include "logger_client.ipp"

#endif // _LOGGER_CLIENT_HPP_