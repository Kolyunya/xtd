namespace std
{

            console_logger::console_logger ( bool add_new_line , bool addTimeStamp ) noexcept
                :
                    AbstractLogger(addNewLine,addTimeStamp)
    {

    }

    void    console_logger::log_data ( const std::string& data ) const noexcept
    {

        std::cout << data;

    }

}