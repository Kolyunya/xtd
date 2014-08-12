namespace xtd
{

    template <typename type>
    std::string str::from ( type source )
    {
        std::stringstream string_stream;
        string_stream << source;
        std::string result_string = string_stream.str();
        return result_string;
    }

}