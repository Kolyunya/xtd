namespace std
{

            file_logger::file_logger ( const std::string& file , const bool addNewLine , const bool addTimeStamp ) noexcept
                :
                    AbstractLogger(addNewLine,addTimeStamp),
                    file(file)
    {

    }

    void    file_logger::logData ( const std::string& data ) const noexcept
    {

        FileUtil::appendFileContents(file,data);

    }
    
}