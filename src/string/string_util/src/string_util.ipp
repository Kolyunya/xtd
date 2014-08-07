//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

namespace xtd
{

    namespace str
    {

        long int        string_to_long_int ( const std::string& source_string , int number_base )
        {

            // Function "strtol" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtol" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            long int number = strtol(source_string.data(),&first_character_after_number,number_base);

            if ( number == 0 )
            {

                char* first_character_of_string = &const_cast<char&>(source_string[0]);

                if ( first_character_after_number == first_character_of_string )
                {

                    throw std::runtime_error("String to number conversion failed.");

                }

            }

            else if ( number == LONG_MAX || number == LONG_MIN )
            {

                throw std::runtime_error("String to number conversion failed. Number exceeds type limits.");

            }

            return number;

        }

        int             string_to_int ( const std::string& source_string , int number_base )
        {

            long int number = string_to_long_int(source_string,number_base);

            if ( number < INT_MIN || number > INT_MAX )
            {

                throw std::runtime_error("String to number conversion failed. Number exceeds type limits.");

            }

            return number;

        }

        double          string_to_double ( const std::string& source_string )
        {

            // Function "strtod" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtod" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            double number = strtod(source_string.data(),&first_character_after_number);

            if ( number == 0 )
            {

                char* first_character_of_string = &const_cast<char&>(source_string[0]);

                if ( first_character_after_number == first_character_of_string )
                {

                    throw std::runtime_error("String to number conversion failed.");

                }

            }

            else if ( number == LONG_MAX || number == LONG_MIN )
            {

                throw std::runtime_error("String to number conversion failed. Number exceeds type limits.");

            }

            return number;

        }

        float           string_to_float ( const std::string& source_string )
        {

            // Function "strtof" will set this pointer to point to the first character after the numeric part of the original string.
            // This pointer will be used in the case when "std::strtof" will returns "0".
            // If this pointer will point to the first character of the original std::string this will mean that the std::string does not start
            // with a numeral and no conversion has been performed.
            // If this pointer will not point to the first character of the original std::string this will mean that the original string
            // does start with a numeral equal to "0" and the conersion was performed successfully.
            char* first_character_after_number = nullptr;

            float number = strtof(source_string.data(),&first_character_after_number);

            if ( number == 0 )
            {

                char* first_character_of_string = &const_cast<char&>(source_string[0]);

                if ( first_character_after_number == first_character_of_string )
                {

                    throw std::runtime_error("String to number conversion failed. Unknown error.");

                }

            }

            else if ( number == LONG_MAX || number == LONG_MIN )
            {

                throw std::runtime_error("String to number conversion failed. Number exceeds type limits.");

            }

            return number;

        }

        std::string     number_to_string ( int source_number )
        {

            std::stringstream string_stream;
            string_stream << source_number;

            return string_stream.str();
        }

        std::string     number_to_string ( unsigned int source_number )
        {

            return number_to_string(static_cast<int>(source_number));

        }

        std::string     number_to_string ( float source_number )
        {

            std::stringstream string_stream;
            string_stream << source_number;

            return string_stream.str();

        }

        std::string     string_reverse ( const std::string& source_string )
        {

            return std::string(source_string.rbegin(),source_string.rend());

        }

        strings         string_split ( const std::string& source_string , const std::string& delimiter )
        {

            // Create a result vector
            strings result;

            // Calculate the size of the delimiter
            size_t delimiter_size = delimiter.size();

            if ( delimiter_size == 0 )
            {
                for_each
                (
                    source_string.begin(),
                    source_string.end(),
                    [&result]
                    ( char character)
                    {
                        std::string characterString = std::string(1,character);
                        result.push_back(characterString);
                    }
                );
                return result;
            }

            // Calculate the size of the input string
            std::string string_copy = source_string;
            size_t string_size = string_copy.size();

            // Don not process empty strings
            if ( string_size > 0 )
            {

                // Search the position of the first delimiter.
                int first_delimiter_position = string_copy.find_first_of(delimiter);

                // No delimiters are in the string
                if ( first_delimiter_position == -1 )
                {

                    // The result is the whole string
                    result.push_back(string_copy);

                }

                // There is a delimiter in the string
                else
                {

                    // If the std::string does not start with a delimiter
                    if ( first_delimiter_position > 0 )
                    {

                        std::string first_element = string_copy.substr(0,first_delimiter_position);
                        result.push_back ( first_element );

                    }

                    // Cut off the first fragment and the first delimiter and call the `string_split`
                    // function again with `input` std::string containing the rest of the string
                    std::string string_tail = string_copy.substr(first_delimiter_position+delimiter_size,string_size-first_delimiter_position-delimiter_size);
                    strings strings_tail = string_split(string_tail,delimiter);

                    // Add tail strings to result
                    result.insert(result.end(),strings_tail.begin(),strings_tail.end());

                }

            }

            return result;

        }

        strings         string_split ( const std::string& source_string , char delimiter )
        {
            std::string delimiter_string = std::string(1,delimiter);
            return string_split(source_string,delimiter_string);
        }

        strings         string_split ( const char* source_string_ptr , const char* delimiter_ptr )
        {
            std::string source_string = std::string(source_string_ptr);
            std::string delimiter_string = std::string(delimiter_ptr);
            return string_split(source_string,delimiter_string);
        }

        std::string     string_replace ( const std::string& source_string , const std::string& search_for , const std::string& replace_with )
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

        std::string     string_replace ( const std::string& source_string , const char search_for , const char replace_with )
        {
            std::string search_for_string = std::string(1,search_for);
            std::string replace_with_string = std::string(1,replace_with);
            return string_replace(source_string,search_for_string,replace_with_string);
        }

        std::string     string_replace ( const char* source_string_ptr , const char* search_for_ptr , const char* replace_with_ptr )
        {
            std::string source_string = std::string(source_string_ptr);
            std::string search_for_string = std::string(search_for_ptr);
            std::string replace_with_string = std::string(replace_with_ptr);
            return string_replace(source_string,search_for_string,replace_with_string);
        }

        bool            string_is_numeric ( const std::string& source_string )
        {

            // Empty std::string is not a number
            if ( source_string.empty() )
            {

                return false;

            }

            // std::string containing characters which are not numerals is not a number
            bool dot_is_already_used = false;
            auto string_itr = source_string.begin();
            for ( ; string_itr < source_string.end() ; string_itr++ )
            {

                // Numeric character
                if ( isdigit(*string_itr) )
                {

                    continue;

                }

                // '-' as the first character of the string
                if ( string_itr == source_string.begin() && *string_itr == '-' )
                {

                    continue;

                }

                // The first usage of a decimal dot
                if ( ! dot_is_already_used && ( *string_itr == '.' || *string_itr == ',' ) )
                {

                    dot_is_already_used = true;
                    continue;

                }

                return false;

            }

            return true;

        }

        bool            string_is_integer ( const std::string& source_string )
        {
            bool source_string_is_numeric = string_is_numeric(source_string);
            bool source_string_is_not_numeric = ! source_string_is_numeric;
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

        bool            string_is_fractional ( const std::string& source_string )
        {
            bool source_string_is_numeric = string_is_numeric(source_string);
            bool source_string_is_not_numeric = ! source_string_is_numeric;
            if ( source_string_is_not_numeric )
            {
                return false;
            }
            bool source_string_is_integer = string_is_integer(source_string);
            bool source_string_is_not_integer = ! source_string_is_integer;
            if ( source_string_is_not_integer )
            {
                return false;
            }
            return true;
        }

    }

}