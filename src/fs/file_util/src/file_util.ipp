namespace std
{

    namespace fs
    {

        bool        get_file_exists ( const string& file_path )
        {

            ifstream file_stream(file_path.data());

            if ( file_stream.is_open() )
            {

                file_stream.close();
                return true;

            }

            return false;

        }

        off_t       get_file_size ( const string& file_path )
        {

            struct stat file_statistics;

            int get_file_statistics_result = stat(file_path.c_str(),&file_statistics);

            if ( get_file_statistics_result != 0 )
            {

                throw runtime_error("Could no retrieve file_path statistics");

            }

            off_t file_size = file_statistics.st_size;

            return file_size;

        }

        off_t       get_file_size ( int file_descriptor )
        {

            struct stat file_statistics;

            int get_file_statistics_result = fstat(file_descriptor,&file_statistics);

            if ( get_file_statistics_result != 0 )
            {

                throw runtime_error("Could no retrieve file_path statistics");

            }

            off_t file_size = file_statistics.st_size;

            return file_size;

        }

        string      get_file_contents ( const string& file_path )
        {

            check_file_exists(file_path);

            ifstream file_stream(file_path.data());

            if ( ! file_stream.is_open() )
            {

                throw runtime_error("Could no open file_path");

            }

            char file_character;
            string file_contents;

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

        void        set_file_contents ( const string& file_path , const string& data )
        {

            check_file_exists(file_path);

            ofstream output_file_stream(file_path.data());

            output_file_stream.write(data.data(),data.size());

            output_file_stream.close();

        }

        void        append_file_contents ( const string& file_path , const string& data )
        {

            set_file_contents(file_path,get_file_contents(file_path)+data);

        }

        void        prepend_file_contents ( const string& file_path , const string& data )
        {

            set_file_contents(file_path,data+get_file_contents(file_path));

        }

        void        truncate_file_contents ( const string& file_path )
        {

            set_file_contents(file_path,"");

        }

        void        check_file_exists ( const string& file_path )
        {

            if ( ! get_file_exists(file_path) )
            {

                throw runtime_error("File does not exist.");

            }

        }

    }

}
