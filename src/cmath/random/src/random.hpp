#ifndef _RANDOM_HPP_
#define _RANDOM_HPP_

#include <cstdlib>
#include <stdexcept>

namespace std
{

	namespace random
	{
	
		static int		get_int ( const int minimum , const int maximum );
		
		static bool		coin_flip ( float win_rate_percent = 50 );
	
	}
	
}

#include "random.ipp"

#endif	// _RANDOM_HPP_