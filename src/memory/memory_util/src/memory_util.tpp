namespace std
{

                            template <typename Type>
    inline static void      validate_pointer ( Type* pointer )
    {
        if ( pointer == nullptr )
        {
            throw std::runtime_error("Null pointer exception");
        }
    }

}
