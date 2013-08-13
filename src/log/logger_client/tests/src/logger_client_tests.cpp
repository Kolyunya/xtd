#include <o__O/Test.hpp>
#include <o__O/ConsoleLogger.hpp>
#include <o__O/LoggerClient.hpp>



using namespace o__O;

int main ( void )
{
	
	TEST::TRUE([]()
	{
	
		LoggerClient loggerClient;
		
		return 1;
	
	});
	
	TEST::TRUE([]()
	{
	
		LoggerClient loggerClient;
		loggerClient.log("Hello world!");
		
		return 1;
	
	});
	
	TEST::TRUE([]()
	{
	
		ConsoleLogger logger;
		LoggerClient loggerClient(&logger);
		loggerClient.getLoggerRef().addNewLine = false;
		loggerClient.getLoggerRef().addTimeStamp = false;
		
		loggerClient.log("");
		
		return 1;
	
	});
	
	return 	TEST_RUN() ? 0 : 1;

}