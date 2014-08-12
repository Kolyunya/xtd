#include "string_utils.hpp"

namespace xtd
{

    namespace string
    {

        signed long long int to_long_long ( const std::string& source_string , signed int number_base )
        {

            //  Function "strtoll" will set this pointer to point to the first character after the numeric part of the original string.
            //  This pointer will be used in the case when "std::strtoll" will returns "0".
            //  If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            //  with a numeral and no conversion has been performed.
            //  If this pointer will not point to the first character of the original std::string this will mean that the original string
            //  does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            signed long long int number = std::strtoll(source_string.data(),&first_character_after_number,number_base);

            //  Either error occured or the the result number is "0".
            //  Use "first_character_after_number" to distinguish between those cases.
            if ( number == 0 )
            {
                char* first_character_of_string = const_cast<char*>(source_string.data());
                if ( first_character_after_number == first_character_of_string )
                {
                    throw std::runtime_error(error_string_to_number_conversion_failed);
                }
            }

            //  The number either exceeds or equals the limits of "signed long int".
            //  It is not possible do distinguish those cases because "errno" may be set to "ERANGE" earlyer.
            else if
            (
                number == std::numeric_limits<signed long long int>::max()
                    ||
                number == std::numeric_limits<signed long long int>::min()
            )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        signed long int to_long ( const std::string& source_string , signed int number_base )
        {

            //  Function "strtol" will set this pointer to point to the first character after the numeric part of the original string.
            //  This pointer will be used in the case when "std::strtol" will returns "0".
            //  If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            //  with a numeral and no conversion has been performed.
            //  If this pointer will not point to the first character of the original std::string this will mean that the original string
            //  does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            signed long int number = std::strtol(source_string.data(),&first_character_after_number,number_base);

            //  Either error occured or the the result number is "0".
            //  Use "first_character_after_number" to distinguish between those cases.
            if ( number == 0 )
            {
                char* first_character_of_string = const_cast<char*>(source_string.data());
                if ( first_character_after_number == first_character_of_string )
                {
                    throw std::runtime_error(error_string_to_number_conversion_failed);
                }
            }

            //  The number either exceeds or equals the limits of "signed long int".
            //  It is not possible do distinguish those cases because "errno" may be set to "ERANGE" earlyer.
            else if
            (
                number == std::numeric_limits<signed long int>::max()
                    ||
                number == std::numeric_limits<signed long int>::min()
            )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        signed int to_int ( const std::string& source_string , signed int number_base )
        {

            //  Try to convert the string to "signed long int"
            signed long int number = to_long(source_string,number_base);

            //  Check if the number exceeds the limits of "signed int"
            if
            (
                number == std::numeric_limits<signed int>::max()
                    ||
                number == std::numeric_limits<signed int>::min()
            )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        long double to_long_double ( const std::string& source_string )
        {

            // Function "strtold" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtold" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            long double number = std::strtold(source_string.data(),&first_character_after_number);

            //  Either error occured or the the result number is "0".
            //  Use "first_character_after_number" to distinguish between those cases.
            if ( number == 0 )
            {
                char* first_character_of_string = const_cast<char*>(source_string.data());
                if ( first_character_after_number == first_character_of_string )
                {
                    throw std::runtime_error(error_string_to_number_conversion_failed);
                }
            }

            //  The number exceeds type limits.
            else if ( number == HUGE_VAL || number == -HUGE_VAL )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        double to_double ( const std::string& source_string )
        {

            // Function "strtod" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtod" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            double number = std::strtod(source_string.data(),&first_character_after_number);

            //  Either error occured or the the result number is "0".
            //  Use "first_character_after_number" to distinguish between those cases.
            if ( number == 0 )
            {
                char* first_character_of_string = const_cast<char*>(source_string.data());
                if ( first_character_after_number == first_character_of_string )
                {
                    throw std::runtime_error(error_string_to_number_conversion_failed);
                }
            }

            //  The number exceeds type limits.
            else if ( number == HUGE_VAL || number == -HUGE_VAL )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        float to_float ( const std::string& source_string )
        {

            // Function "strtof" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtof" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            float number = std::strtof(source_string.data(),&first_character_after_number);

            //  Either error occured or the the result number is "0".
            //  Use "first_character_after_number" to distinguish between those cases.
            if ( number == 0 )
            {
                char* first_character_of_string = const_cast<char*>(source_string.data());
                if ( first_character_after_number == first_character_of_string )
                {
                    throw std::runtime_error(error_string_to_number_conversion_failed);
                }
            }

            //  The number exceeds type limits.
            else if ( number == HUGE_VAL || number == -HUGE_VAL )
            {
                throw std::runtime_error(error_number_exceeds_type_limits);
            }

            return number;

        }

        std::string reverse ( const std::string& source_string )
        {
            std::string::const_reverse_iterator reversed_begin_itr = source_string.crbegin();
            std::string::const_reverse_iterator reversed_end_itr = source_string.crend();
            const std::string result_string(reversed_begin_itr,reversed_end_itr);
            return result_string;
        }

        strings split ( const std::string& source_string , const std::string& delimiter )
        {

            //  Create a result vector.
            strings result;

            //  Calculate the size of the delimiter.
            std::size_t delimiter_size = delimiter.size();

            //  If the delimiter is an empty string - split the source string to characters.
            if ( delimiter_size == 0 )
            {
                std::for_each
                (
                    source_string.begin(),
                    source_string.end(),
                    [ &result ]
                    ( char character)
                    {
                        std::string character_string = std::string(1,character);
                        result.push_back(character_string);
                    }
                );
                return result;
            }

            //  Calculate the size of the input string.
            std::string string_copy = source_string;
            std::size_t string_size = string_copy.size();

            //  Don not process empty strings.
            if ( string_size > 0 )
            {

                //  Search the position of the first delimiter.
                std::size_t first_delimiter_position = string_copy.find_first_of(delimiter);

                //  There are no delimiters in the source string.
                if ( first_delimiter_position == std::string::npos )
                {
                    //  The result is the whole string itself.
                    result.push_back(string_copy);
                }

                //  There is a delimiter in the string.
                else
                {

                    //  If the std::string does not start with a delimiter.
                    if ( first_delimiter_position > 0 )
                    {

                        std::string first_element = string_copy.substr(0,first_delimiter_position);
                        result.push_back ( first_element );

                    }

                    //  Cut off the first fragment and the first delimiter and call the `split`
                    //  function again with `input` std::string containing the rest of the string.
                    std::string string_tail = string_copy.substr(first_delimiter_position+delimiter_size,string_size-first_delimiter_position-delimiter_size);
                    strings string_reminder_split = split(string_tail,delimiter);

                    //  Add tail strings to result.
                    result.insert(result.end(),string_reminder_split.begin(),string_reminder_split.end());

                }

            }

            return result;

        }

        strings split ( const std::string& source_string , char delimiter )
        {
            std::string delimiter_string = std::string(1,delimiter);
            strings result_strings = split(source_string,delimiter_string);
            return result_strings;
        }

        std::string replace ( const std::string& source_string , const std::string& search_for , const std::string& replace_with )
        {

            size_t search_for_size = search_for.size();
            std::string substring;
            std::string resulting_string = source_string;
            size_t resulting_string_character_id = 0;
            size_t resulting_string_size = resulting_string.size();

            while ( resulting_string_character_id < resulting_string_size )
            {
                substring = resulting_string.substr(resulting_string_character_id,search_for_size);
                if ( substring == search_for )
                {
                    resulting_string.replace(resulting_string_character_id,search_for_size,replace_with);
                    resulting_string_character_id = 0;
                }
                resulting_string_character_id++;
            }

            return resulting_string;

        }

        std::string replace ( const std::string& source_string , const char search_for , const char replace_with )
        {
            std::string search_for_string = std::string(1,search_for);
            std::string replace_with_string = std::string(1,replace_with);
            return replace(source_string,search_for_string,replace_with_string);
        }

        bool is_numeric ( const std::string& source_string )
        {

            //  Empty std::string is not a number
            if ( source_string.empty() )
            {
                return false;
            }

            //  std::string containing characters which are not numerals is not a number
            bool dot_is_already_used = false;
            auto string_itr = source_string.begin();
            for ( ; string_itr < source_string.end() ; string_itr++ )
            {

                //  Numeric character
                if ( isdigit(*string_itr) )
                {
                    continue;
                }

                //  '-' as the first character of the string
                if ( string_itr == source_string.begin() && *string_itr == '-' )
                {
                    continue;
                }

                //  The first usage of a decimal dot
                if ( ! dot_is_already_used && ( *string_itr == '.' || *string_itr == ',' ) )
                {
                    dot_is_already_used = true;
                    continue;
                }

                return false;

            }

            return true;

        }

        bool is_integer ( const std::string& source_string )
        {
            bool source_is_numeric = is_numeric(source_string);
            bool source_string_is_not_numeric = ! source_is_numeric;
            if ( source_string_is_not_numeric )
            {
                return false;
            }
            bool source_string_contains_dot = source_string.find('.') != source_string.npos;
            bool source_string_contains_comma = source_string.find(',') != source_string.npos;
            bool source_string_contains_dot_or_comma = source_string_contains_dot || source_string_contains_comma;
            if ( source_string_contains_dot_or_comma )
            {
                return false;
            }
            return true;
        }

        bool is_fractional ( const std::string& source_string )
        {
            bool source_is_numeric = is_numeric(source_string);
            bool source_string_is_not_numeric = ! source_is_numeric;
            if ( source_string_is_not_numeric )
            {
                return false;
            }
            bool source_is_integer = is_integer(source_string);
            bool source_string_is_not_integer = ! source_is_integer;
            if ( source_string_is_not_integer )
            {
                return false;
            }
            return true;
        }

    }

}