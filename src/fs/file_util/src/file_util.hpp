#ifndef _FILE_UTIL_HPP_
#define _FILE_UTIL_HPP_

#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <string>

namespace std
{

	namespace fs
	{

		inline bool				get_file_exists ( const std::string& file );
		
		inline off_t			get_file_size ( int fileDescriptor );
		
		inline off_t			get_file_size ( const std::string& filePath );
		
		inline std::string		get_file_contents ( const std::string& file );
		
		inline void				set_file_contents ( const std::string& file , const std::string& data );
		
		inline void				prepend_file_contents ( const std::string& file , const std::string& data );

		inline void				append_file_contents ( const std::string& file , const std::string& data );
		
		inline void				truncate_file_contents ( const std::string& file );
		
		inline void				check_file_exists ( const std::string& file );
	
	}
	
}

#include "file_util.ipp"

#endif // _FILE_UTIL_HPP_