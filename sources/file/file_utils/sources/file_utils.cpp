#include "file_utils.hpp"

namespace xtd
{

    namespace file
    {

        bool get_exists ( const std::string& file_path )
        {

            std::ifstream file_stream(file_path.data());

            if ( file_stream.is_open() )
            {

                file_stream.close();
                return true;

            }

            return false;

        }

        off_t get_size ( const std::string& file_path )
        {

            struct stat file_statistics;

            int get_file_statistics_result = stat(file_path.c_str(),&file_statistics);

            if ( get_file_statistics_result != 0 )
            {

                throw std::runtime_error("Could no retrieve file_path statistics");

            }

            off_t file_size = file_statistics.st_size;

            return file_size;

        }

        off_t get_size ( int file_descriptor )
        {

            struct stat file_statistics;

            int get_file_statistics_result = fstat(file_descriptor,&file_statistics);

            if ( get_file_statistics_result != 0 )
            {

                throw std::runtime_error("Could no retrieve file_path statistics");

            }

            off_t file_size = file_statistics.st_size;

            return file_size;

        }

        std::string get_contents ( const std::string& file_path )
        {

            check_exists(file_path);

            std::ifstream file_stream(file_path.data());

            if ( ! file_stream.is_open() )
            {

                throw std::runtime_error("Could no open file_path");

            }

            char file_character;
            std::string file_contents;

            while ( file_stream.good() && ! file_stream.eof() )
            {

                file_character = file_stream.get();

                if ( file_character != -1 )
                {

                    file_contents += file_character;

                }

            }

            file_stream.close();

            return file_contents;

        }

        void set_contents ( const std::string& file_path , const std::string& data )
        {

            check_exists(file_path);

            std::ofstream output_file_stream(file_path.data());

            output_file_stream.write(data.data(),data.size());

            output_file_stream.close();

        }

        void append_contents ( const std::string& file_path , const std::string& data )
        {

            set_contents(file_path,get_contents(file_path)+data);

        }

        void prepend_contents ( const std::string& file_path , const std::string& data )
        {

            set_contents(file_path,data+get_contents(file_path));

        }

        void truncate_contents ( const std::string& file_path )
        {

            set_contents(file_path,"");

        }

        void check_exists ( const std::string& file_path )
        {

            if ( ! get_exists(file_path) )
            {

                throw std::runtime_error("File does not exist.");

            }

        }

    }

}