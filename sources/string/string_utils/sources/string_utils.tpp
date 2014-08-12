namespace xtd
{

    namespace str
    {

        template <typename type>
        std::string from ( type source )
        {
            std::stringstream string_stream;
            string_stream << source;
            std::string result_string = string_stream.str();
            return result_string;
        }

    }

}