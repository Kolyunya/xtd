namespace std
{

                        logger_client::logger_client ( abstract_logger* logger_ptr )
    {

        this->set_logger(logger_ptr);

    }

    abstract_logger&    logger_client::get_logger_ref ( void )
    {

        return * this->logger_ptr;

    }

    abstract_logger*    logger_client::get_logger_ptr ( void )
    {

        return this->logger_ptr;

    }

    void                logger_client::set_logger ( abstract_logger* logger_ptr )
    {

        this->logger_ptr = logger_ptr;

    }

    void                logger_client::log ( const std::string& data ) const
    {

        if ( this->logger_ptr )
        {

            this->logger_ptr->log(data);

        }

    }

}