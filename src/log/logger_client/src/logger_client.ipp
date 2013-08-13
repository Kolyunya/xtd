#include "LoggerClient.hpp"



namespace o__O
{

						LoggerClient::LoggerClient ( AbstractLogger* logger )
	{
	
		this->setLogger(logger);

	}
	
	AbstractLogger&		LoggerClient::getLoggerRef ( void )
	{
	
		return * this->logger;
	
	}
	
	AbstractLogger*		LoggerClient::getLoggerPtr ( void )
	{
	
		return this->logger;
	
	}
	
	void				LoggerClient::setLogger ( AbstractLogger* logger )
	{
	
		this->logger = logger;
	
	}
	
	void				LoggerClient::log ( const std::string& data ) const
	{
	
		if ( this->logger )
		{
		
			this->logger->log(data);
			
		}

	}
	
}