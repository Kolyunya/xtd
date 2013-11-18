namespace std
{

            file_logger::file_logger ( const std::string& file , bool add_new_line , bool add_time_stamp ) noexcept
                :
                    abstract_logger(add_new_line,add_time_stamp),
                    file(file)
    {

    }

    void    file_logger::log_data ( const std::string& data ) const noexcept
    {

        fs::append_file_contents(file,data);

    }

}