namespace std
{

                            template < typename type >
    static std::string      serialize ( const type& object )
    {
        size_t type_size = sizeof(type);
        std::string data(type_size,0);
        const void* source_ptr = reinterpret_cast<const void*>(&object);
        void* destination_ptr = reinterpret_cast<void*>(&data[0]);
        memcpy(destination_ptr,source_ptr,type_size);
        return data;
    }

                            template < typename type >
    static type             deserialize ( const std::string& data )
    {
        type object;
        size_t source_size = data.size();
        size_t object_size = sizeof(object);
        if ( source_size != object_size )
        {
            throw std::runtime_error("Data is corrupted");
        }
        const void* source_ptr = reinterpret_cast<const void*>(&data[0]);
        void* destination_ptr = reinterpret_cast<void*>(&object);
        memcpy(destination_ptr,source_ptr,source_size);
        return object;
    }

}
