#ifndef _FILE_LOGGER_HPP_
#define _FILE_LOGGER_HPP_

#include <fs.hpp>
#include <log/abstract_logger.hpp>



namespace std
{

    class file_logger
        :
            public abstract_logger
    {

        public:

            inline explicit         file_logger ( const std::string& file , bool add_new_line = true , bool add_time_stamp = true ) noexcept;

        protected:

            inline virtual void     log_data ( const std::string& data ) const noexcept override;

            std::string             file;

    };

}

// Include implementation file
#include "file_logger.ipp"

#endif    // _FILE_LOGGER_HPP_