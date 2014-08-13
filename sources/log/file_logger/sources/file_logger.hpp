#ifndef _XTD_FILE_LOGGER_HPP_
#define _XTD_FILE_LOGGER_HPP_

#include <xtd/file.hpp>
#include <xtd/log/abstract_logger.hpp>

namespace xtd
{

    namespace log
    {

        class file_logger
            :
                public abstract_logger
        {

            public:

                explicit file_logger ( const std::string& file , bool add_new_line = true , bool add_time_stamp = true ) noexcept;

            protected:

                virtual void log_data ( const std::string& data ) const noexcept override;

                std::string file;

        };

    }

}

#endif