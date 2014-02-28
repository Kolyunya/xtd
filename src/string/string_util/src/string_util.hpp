#ifndef _STRING_UTIL_HPP_
#define _STRING_UTIL_HPP_

#include <stdexcept>    // std::runtime_error
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <sstream>      // std::string
                        // std::stringstream
#include <climits>      // LONG_MIN
                        // LONG_MAX
#include <cstdlib>      // std::strtol
                        // std::strtof

namespace std
{

    using strings = vector<string>;

    inline long int     string_to_long_int ( const string& source_string , int number_base = 10 );

    inline int          string_to_int ( const string& source_string , int number_base = 10 );

    inline double       string_to_double ( const string& source_string );

    inline float        string_to_float ( const string& source_string );

    inline string       number_to_string ( int source_number );

    inline string       number_to_string ( unsigned int source_number );

    inline string       number_to_string ( float source_number );

    inline string       string_reverse ( const string& source_string );

    inline strings      string_split ( const string& source_string , const string& delimiter );

    inline strings      string_split ( const string& source_string , char delimiter );

    inline strings      string_split ( const char* source_string_ptr , const char* delimiter_ptr );

    inline string       string_replace ( const string& source_string , const string& search_for , const string& replace_with );

    inline string       string_replace ( const string& source_string , char search_for , char replace_with );

    inline string       string_replace ( const char* source_string_ptr , const char* search_for_ptr , const char* replace_with_ptr );

    inline bool         string_is_numeric ( const string& source_string );

    inline bool         string_is_integer ( const string& source_string );

    inline bool         string_is_fractional ( const string& source_string );

}

// Include implementation file
#include "string_util.ipp"

#endif  // _STRING_UTIL_HPP_
