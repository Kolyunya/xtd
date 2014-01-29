#ifndef _FILE_UTIL_HPP_
#define _FILE_UTIL_HPP_

#include <stdexcept>        // std::runtime_error
#include <fstream>          // std::ofstream
                            // std::ifstream
#include <sys/types.h>      // off_t
#include <sys/stat.h>       // stat

namespace std
{

    namespace fs
    {

        inline bool         get_file_exists ( const string& file_path );

        inline off_t        get_file_size ( const string& file_path );

        inline off_t        get_file_size ( int file_descriptor );

        inline string       get_file_contents ( const string& file_path );

        inline void         set_file_contents ( const string& file_path , const string& data );

        inline void         append_file_contents ( const string& file_path , const string& data );

        inline void         prepend_file_contents ( const string& file_path , const string& data );

        inline void         truncate_file_contents ( const string& file_path );

        inline void         check_file_exists ( const string& file_path );

    }

}

// Include implementation file
#include "file_util.ipp"

#endif // _FILE_UTIL_HPP_
