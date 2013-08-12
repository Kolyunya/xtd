namespace std
{

	namespace fs
	{

		bool			get_file_exists ( const std::string& file )
		{

			//	Open an input file stream
			std::ifstream fileStream(file.data());
			
			//	Check if a stream is successfully opened
			if ( fileStream.is_open() )
			{
			
				//	Close the file stream
				fileStream.close();
				
				return true;
				
			}
			
			return false;

		}

		off_t			get_file_size ( int fileDescriptor )
		{
		
			struct stat fileStatistics;
			
			int getFileStatisticsResult = fstat(fileDescriptor,&fileStatistics);
			
			if ( getFileStatisticsResult != 0 )
			{
			
				throw std::runtime_error("Could no retrieve file statistics");
				
			}
			
			off_t fileSize = fileStatistics.st_size;
			
			return fileSize;
			
		}
		
		off_t			get_file_size ( const std::string& filePath )
		{
		
			struct stat fileStatistics;
			
			int getFileStatisticsResult = stat(filePath.c_str(),&fileStatistics);
			
			if ( getFileStatisticsResult != 0 )
			{
			
				throw std::runtime_error("Could no retrieve file statistics");
				
			}
			
			off_t fileSize = fileStatistics.st_size;
			
			return fileSize;
		
		}
		
		std::string		get_file_contents ( const std::string& file )
		{

			//	Check if the file does exist
			check_file_exists(file);

			//	Open an input file stream
			std::ifstream fileStream(file.data());
			
			//	Check if a stream is successfully opened
			if ( ! fileStream.is_open() )
			{
			
				throw std::runtime_error("Could no open file");
				
			}
			
			//	Define variables to hold file contents
			char fileCharacter;
			std::string fileContents;
			
			//	Read file line by line
			while ( fileStream.good() && ! fileStream.eof() )
			{
			
				fileCharacter = fileStream.get();
				
				if ( fileCharacter != -1 )
				{

					fileContents += fileCharacter;
					
				}
				
			}

			//	Close the file stream
			fileStream.close();
			
			//	Return file contents
			return fileContents;
			
		}

		void			set_file_contents ( const std::string& file , const std::string& data )
		{

			//	Ensure that the file does exist
			check_file_exists(file);
			
			//	Create an output stream
			std::ofstream fileStream(file.data());
			
			//	Write data to file stream
			fileStream.write(data.data(),data.size());
			
			//	Close the file stream
			fileStream.close();
			
		}

		void			append_file_contents ( const std::string& file , const std::string& data )
		{

			set_file_contents(file,get_file_contents(file)+data);

		}
		
		void			prepend_file_contents ( const std::string& file , const std::string& data )
		{
		
			set_file_contents(file,data+get_file_contents(file));
		
		}

		void			truncate_file_contents ( const std::string& file )
		{

			set_file_contents(file,"");

		}

		void			check_file_exists ( const std::string& file )
		{

			if ( ! get_file_exists(file) )
			{
			
				throw std::runtime_error("File does not exist");
				
			}
			
		}
		
	}
	
}