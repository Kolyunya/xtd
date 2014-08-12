#ifndef _XTD_FILE_UTILS_HPP_
#define _XTD_FILE_UTILS_HPP_

#include <stdexcept>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>

/**
 *  @brief A root namespace of the library.
 */
namespace xtd
{

    /**
     *  @brief A namespace containing tools for file system operations.
     */
    namespace file
    {

        bool get_exists ( const std::string& file_path );

        off_t get_size ( const std::string& file_path );

        off_t get_size ( int file_descriptor );

        std::string get_contents ( const std::string& file_path );

        void set_contents ( const std::string& file_path , const std::string& data );

        void append_contents ( const std::string& file_path , const std::string& data );

        void prepend_contents ( const std::string& file_path , const std::string& data );

        void truncate_contents ( const std::string& file_path );

        void check_exists ( const std::string& file_path );

    }

}

#endif