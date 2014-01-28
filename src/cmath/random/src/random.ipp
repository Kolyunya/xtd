namespace std
{

    namespace random
    {

        void    randomize ( void )
        {

            // Randomize random number generator using vurent
            std::srand(std::time(nullptr));

        }

        int     get_int ( const int minimum , const int maximum )
        {

            // Validate the range
            if ( minimum > maximum )
            {

                throw std::range_error("Invalid limits range");

            }

            // Minimum range
            else if ( minimum == maximum )
            {

                return minimum;

            }

            // Calculate the length of the range
            int range_length = maximum - minimum + 1;

            // Return a random number from the range
            return std::rand() % range_length + minimum;

        }

        bool    coin_flip ( float win_rate_percent )
        {

            if ( win_rate_percent > 100 )
            {

                win_rate_percent = 100;

            }

            if ( win_rate_percent < 0 )
            {

                win_rate_percent = 0;

            }

            int win_rate_inverted = 100 / win_rate_percent;

            return get_int(1,win_rate_inverted) == 1;

        }

    }

}
