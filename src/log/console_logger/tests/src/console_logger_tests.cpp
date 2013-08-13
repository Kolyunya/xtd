#include <o__O/Test.hpp>
#include <o__O/ConsoleLogger.hpp>



using namespace o__O;

int main ( void )
{

	TEST_TRUE
	(
	
		const AbstractLogger& logger = ConsoleLogger(false,false);
		logger.log("");
		
		return true;
	
	);
	
	return 	TEST_RUN() ? 0 : 1;

}