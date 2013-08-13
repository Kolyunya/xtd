#include "FileLogger.hpp"



namespace o__O
{

			FileLogger::FileLogger ( const std::string& file , const bool addNewLine , const bool addTimeStamp ) noexcept
				:
					AbstractLogger	( addNewLine , addTimeStamp ),
					file			( file )
	{

	}

	void	FileLogger::logData ( const std::string& data ) const noexcept
	{

		FileUtil::appendFileContents(file,data);

	}
	
}