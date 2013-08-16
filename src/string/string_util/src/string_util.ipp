namespace std
{

	long int	string_to_long_int ( const string& source_string , int number_base )
	{
	
		//	@description		Converts "source_string" to a "long int" treeting "source_string" as a numeral with the base equal to "number_base".
		//	@throw_guarantee	Strong no-throw guarantee.
		//	@throws				std::runtime_error - If "source_string" does not represent a valid_number.
		//	@throws				std::runtime_error - If "source_string" represents a number which is out of range of "long int".
		
		
		
		//  Function "strtol" will set this pointer to point to the first character after the numeric part of the original string.
		//	This pointer will be used in the case when "std::strtol" will returns "0".
		//	If this pointer will point to the first character of the original string this will mean that the string does not start
		//	with a numeral and no conversion has been performed.
		//	If this pointer will not point to the first character of the original string this will mean that the original string
		//	does start with a numeral equal to "0" and the conersion was performed successfully.
		char* first_character_after_number = nullptr;
		
		long int number = strtol(source_string.data(),&first_character_after_number,number_base);
		
		if ( number == 0 )
		{
		
			char* first_character_of_string = &const_cast<char&>(source_string[0]);
			
			if ( first_character_after_number == first_character_of_string )
			{
				
				throw runtime_error("String to number conversion failed.");
				
			}
			
		}
		
		else if ( number == LONG_MAX || number == LONG_MIN )
		{
			
			throw runtime_error("String to number conversion failed. Number exceeds type limits.");
			
		}
		
		return number;

	}
	
	int			string_to_int ( const string& source_string , int number_base )
	{
	
		long int number = string_to_long_int(source_string,number_base);
		
		if ( number < INT_MIN || number > INT_MAX )
		{
		
			throw runtime_error("String to number conversion failed. Number exceeds type limits.");
		
		}
	
		return number;
	
	}

	double		string_to_double ( const string& source_string )
	{
	
		//  Function "strtod" will set this pointer to point to the first character after the numeric part of the original string.
		//	This pointer will be used in the case when "std::strtod" will returns "0".
		//	If this pointer will point to the first character of the original string this will mean that the string does not start
		//	with a numeral and no conversion has been performed.
		//	If this pointer will not point to the first character of the original string this will mean that the original string
		//	does start with a numeral equal to "0" and the conersion was performed successfully.
		char* first_character_after_number = nullptr;
		
		double number = strtod(source_string.data(),&first_character_after_number);
		
		if ( number == 0 )
		{

			char* first_character_of_string = &const_cast<char&>(source_string[0]);
			
			if ( first_character_after_number == first_character_of_string )
			{
				
				throw runtime_error("String to number conversion failed.");
				
			}
			
		}
		
		else if ( number == LONG_MAX || number == LONG_MIN )
		{
			
			throw runtime_error("String to number conversion failed. Number exceeds type limits.");
			
		}
		
		return number;
	
	}

	float		string_to_float ( const string& source_string )
	{
	
		//  Function "strtof" will set this pointer to point to the first character after the numeric part of the original string.
		//	This pointer will be used in the case when "std::strtof" will returns "0".
		//	If this pointer will point to the first character of the original string this will mean that the string does not start
		//	with a numeral and no conversion has been performed.
		//	If this pointer will not point to the first character of the original string this will mean that the original string
		//	does start with a numeral equal to "0" and the conersion was performed successfully.
		char* first_character_after_number = nullptr;
		
		float number = strtof(source_string.data(),&first_character_after_number);
		
		if ( number == 0 )
		{

			char* first_character_of_string = &const_cast<char&>(source_string[0]);
			
			if ( first_character_after_number == first_character_of_string )
			{
				
				throw runtime_error("String to number conversion failed. Unknown error.");
				
			}
			
		}
		
		else if ( number == LONG_MAX || number == LONG_MIN )
		{
			
			throw runtime_error("String to number conversion failed. Number exceeds type limits.");
			
		}
		
		return number;

	}
	
	string		number_to_string ( const int source_number )
	{

		stringstream string_stream;
		string_stream << source_number;
		
		return string_stream.str();
	}
	
	string		number_to_string ( const unsigned int source_number )
	{
		
		return number_to_string(static_cast<int>(source_number));
		
	}
	
	string		number_to_string ( const float source_number )
	{

		stringstream string_stream;
		string_stream << source_number;
		
		return string_stream.str();

	}
	
	strings		string_split ( const string& source_string , char delimiter )
	{

		//  Create a result vector
		strings result;
		
		//  Calculate te size of the input string
		string string_copy = source_string;
		int string_size = string_copy.size();

		//  Don not process empty strings
		if ( string_size > 0 )
		{
			
			// searching for the position of the first delimiter.
			int first_delimiter_position = string_copy.find_first_of(delimiter);
			
			//  No delimiters are in the string
			if ( first_delimiter_position == -1 )
			{
				
				//  The result is the whole string
				result.push_back(string_copy);
				
			}

			//  The only delimiter is the last and not the only character in the string
			else if ( first_delimiter_position == string_size - 1 && string_size > 1 )
			{
				
				//  The result is the string without the last character
				string_copy.resize(first_delimiter_position);
				result.push_back(string_copy);

			}

			//  Delimiter is in the center of the string
			else
			{
				
				//  If the first character of the input is NOT a `delimiter` - add the first fragment to the output
				if ( first_delimiter_position > 0 )
				{
					
					string firstFragment = string_copy.substr(0,first_delimiter_position);
					result.push_back ( firstFragment );
					
				}
				
				//	Then we cut off the first fragment and the first delimiter and call the `string_split`
				//	function again with `input` string containing the rest of the string
				string string_tail = string_copy.substr(first_delimiter_position+1,string_size-first_delimiter_position-1);
				strings strings_tail = string_split(string_tail,delimiter);
				
				//	Add tail strings to result
				result.insert(result.end(),strings_tail.begin(),strings_tail.end());
				
			}
			
		}
		
		return result;

	}
	
	string		string_reverse ( const string& source_string )
	{
		
		return string(source_string.rbegin(),source_string.rend());
		
	}
	
	string		string_replace ( const string& source_string , const char search_for , const char replace_with )
	{

		string string_copy = source_string;

		for ( auto string_itr = string_copy.begin() ; string_itr != string_copy.end() ; string_itr ++ )
		{
		
			if ( *string_itr == search_for )
			{
			
				*string_itr = replace_with;
				
			}
		
		}
		
		return string_copy;

	}
	
	bool		string_is_numeric ( const string& source_string )
	{

		//	Empty string is not a number
		if ( source_string.empty() )
		{
		
			return false;
			
		}
		
		//	string containing characters which are not numerals is not a number
		bool dot_is_already_used = false;
		auto string_itr = source_string.begin();
		for ( ; string_itr < source_string.end() ; string_itr++ )
		{
		
			//	Numeric character
			if ( isdigit(*string_itr) )
			{
			
				continue;
				
			}
			
			//	'-' as the first character of the string
			if ( string_itr == source_string.begin() && *string_itr == '-' )
			{
			
				continue;
				
			}
			
			//	The first usage of a decimal dot
			if ( ! dot_is_already_used && ( *string_itr == '.' || *string_itr == ',' ) )
			{
			
				dot_is_already_used = true;
				continue;
			
			}
			
			return false;
			
		}
		
		return true;

	}

}