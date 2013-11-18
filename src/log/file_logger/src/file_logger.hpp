#ifndef _FILE_LOGGER_HPP_
#define _FILE_LOGGER_HPP_

#include <logger/abstract_logger.hpp>
#include <fs.hpp>



namespace std
{

    class file_logger
        :
            public abstract_logger
    {
    
        public:
    
                            file_logger ( const std::string& file , bool addNewLine = true , bool addTimeStamp = true ) noexcept;
    
        protected:
        
            virtual void    log_data ( const std::string& data ) const noexcept override;
            
            std::string     file;
            
    };

}

// Include implementation file
#include "file_logger.ipp"

#endif    // _FILE_LOGGER_HPP_