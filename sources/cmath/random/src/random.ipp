//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

namespace xstd
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