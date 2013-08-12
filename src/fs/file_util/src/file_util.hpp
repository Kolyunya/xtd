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

		bool			get_file_exists ( const std::string& file );
		
		off_t			get_file_size ( const int& fileDescriptor );
		
		off_t			get_file_size ( const std::string& filePath );
		
		std::string		get_file_contents ( const std::string& file );
		
		void			set_file_contents ( const std::string& file , const std::string& data );
		
		void			prepend_file_contents ( const std::string& file , const std::string& data );

		void			append_file_contents ( const std::string& file , const std::string& data );
		
		void			truncate_file_contents ( const std::string& file );
		
		void			check_file_exists ( const std::string& file );
	
	}
	
}

#include "file_util.ipp"

#endif	// _FILE_UTIL_HPP_