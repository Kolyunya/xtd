#include "ConsoleLogger.hpp"



namespace o__O
{

			ConsoleLogger::ConsoleLogger ( const bool addNewLine , const bool addTimeStamp ) noexcept
				:
					AbstractLogger(addNewLine,addTimeStamp)
	{

	}

	void	ConsoleLogger::logData ( const std::string& data ) const noexcept
	{

		std::cout << data;

	}

}