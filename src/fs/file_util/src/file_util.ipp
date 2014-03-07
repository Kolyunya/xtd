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

namespace xstd
{

    namespace fs
    {

        bool            get_file_exists ( const std::string& file_path )
        {

            std::ifstream file_stream(file_path.data());

            if ( file_stream.is_open() )
            {

                file_stream.close();
                return true;

            }

            return false;

        }

        off_t           get_file_size ( const std::string& file_path )
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

        off_t           get_file_size ( int file_descriptor )
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

        std::string     get_file_contents ( const std::string& file_path )
        {

            check_file_exists(file_path);

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

        void            set_file_contents ( const std::string& file_path , const std::string& data )
        {

            check_file_exists(file_path);

            std::ofstream output_file_stream(file_path.data());

            output_file_stream.write(data.data(),data.size());

            output_file_stream.close();

        }

        void            append_file_contents ( const std::string& file_path , const std::string& data )
        {

            set_file_contents(file_path,get_file_contents(file_path)+data);

        }

        void            prepend_file_contents ( const std::string& file_path , const std::string& data )
        {

            set_file_contents(file_path,data+get_file_contents(file_path));

        }

        void            truncate_file_contents ( const std::string& file_path )
        {

            set_file_contents(file_path,"");

        }

        void            check_file_exists ( const std::string& file_path )
        {

            if ( ! get_file_exists(file_path) )
            {

                throw std::runtime_error("File does not exist.");

            }

        }

    }

}