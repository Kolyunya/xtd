namespace xtd
{

    namespace memory
    {

        template <typename type>
        void validate_pointer ( type* pointer )
        {
            if ( pointer == nullptr )
            {
                throw std::runtime_error("Null pointer exception.");
            }
        }

    }

}