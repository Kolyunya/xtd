#ifndef _STRING_UTIL_HPP_
#define _STRING_UTIL_HPP_

#include <stdexcept>	//	std::runtime_error
#include <vector>		//	std::vector
#include <sstream>		//	std::string
						//	std::stringstream
#include <climits>		//	LONG_MIN
						//	LONG_MAX
#include <cstdlib>		//	std::strtol
						//	std::strtof

namespace std
{

	typedef vector<string> strings;

	long int	string_to_long_int ( const string& string_ref , int number_base = 10 );
	
	int			string_to_int ( const string& string_ref , int number_base = 10 );
	
	double		string_to_double ( const string& string_ref );

	float		string_to_float ( const string& string_ref );
	
	string		number_to_string ( const int number );
	
	string		number_to_string ( const unsigned int number );
	
	string		number_to_string ( const float number );
	
	string		string_reverse ( const string& string_ref );
	
	strings		string_split ( const string& string_ref , char delimiter );

	string		string_replace ( const string& string_ref , const char search_for , const char replace_with );
	
	bool		string_is_numeric ( const string& string_ref );

	bool		string_is_integer ( const string& string_ref );

}

#include "string_util.ipp"

#endif	// _STRING_UTIL_HPP_