#ifndef _LOGGER_CLIENT_HPP_
#define _LOGGER_CLIENT_HPP_

#include <o__O/AbstractLogger.hpp>



namespace o__O
{

	class LoggerClient
	{
	
		public:
	
								LoggerClient ( AbstractLogger* logger = nullptr );
								
			AbstractLogger&		getLoggerRef ( void );
			
			AbstractLogger*		getLoggerPtr ( void );

			void				setLogger ( AbstractLogger* logger = nullptr );

			void				log ( const std::string& data ) const;
	
		protected:
			
			AbstractLogger*		logger;
			
	};

}

#endif	// _LOGGER_CLIENT_HPP_