namespace std
{

                abstract_logger::abstract_logger ( bool add_new_line , bool add_time_stamp ) noexcept
                    :
                        add_new_line(add_new_line),
                        add_time_stamp(add_time_stamp)
    {

    }

    void        abstract_logger::log ( const string& data ) const noexcept
    {

        this->log_time_stamp();
        this->log_data(data);
        this->log_new_line();

    }

    void        abstract_logger::log_new_line ( void ) const noexcept
    {

        if ( this->add_new_line )
        {

            this->log_data("\n");

        }

    }

    void        abstract_logger::log_time_stamp ( void ) const noexcept
    {

        if ( this->add_time_stamp )
        {

            this->log_data(abstract_logger::make_time_stamp() + " - ");

        }

    }

    string      abstract_logger::make_time_stamp ( void  ) noexcept
    {

        return "";

        //return UnixTime::current().getAsFormattedString("[%Y/%m/%d-%H:%M:%S]");

    }

}