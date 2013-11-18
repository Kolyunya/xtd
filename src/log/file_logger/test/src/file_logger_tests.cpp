#include <o__O/Test.hpp>
#include <o__O/FileLogger.hpp>



using namespace o__O;

int main ( void )
{

	TEST_TRUE
	(
	
		std::string logFile = "test/data/log";
		std::string logData = "Hello world!";
		FileUtil::removeFileContents(logFile);
	
		const AbstractLogger& logger = FileLogger(logFile,false,false);
		logger.log(logData);
		
		return
		(
			FileUtil::getFileContents(logFile) == logData
		);
	
	);
	
	return 	TEST_RUN() ? 0 : 1;

}