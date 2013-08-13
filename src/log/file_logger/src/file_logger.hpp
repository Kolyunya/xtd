#ifndef _FILE_LOGGER_HPP_
#define _FILE_LOGGER_HPP_

#include <o__O/AbstractLogger.hpp>
#include <o__O/FileUtil.hpp>



namespace o__O
{

	class FileLogger
		:
			public AbstractLogger
	{
	
		public:
	
							FileLogger ( const std::string& file , const bool addNewLine = true , const bool addTimeStamp = true ) noexcept;
	
		protected:
		
			virtual void	logData ( const std::string& data ) const noexcept override;
			
			std::string		file;
			
	};

}

#endif	// _FILE_LOGGER_HPP_