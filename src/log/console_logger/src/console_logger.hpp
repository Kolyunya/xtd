#ifndef _CONSOLE_LOGGER_HPP_
#define _CONSOLE_LOGGER_HPP_

#include <iostream>
#include <o__O/AbstractLogger.hpp>



namespace o__O
{

    class ConsoleLogger
        :
            public AbstractLogger
    {

        public:

            explicit        ConsoleLogger ( const bool addNewLine = true , const bool addTimeStamp = true ) noexcept;

        protected:

            virtual void    logData ( const std::string& data ) const noexcept override;

    };

}

// Include implementation file
#endif  // _CONSOLE_LOGGER_HPP_