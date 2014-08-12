#ifndef _XTD_RANDOM_UTILS_HPP_
#define _XTD_RANDOM_UTILS_HPP_

#include <stdexcept>
#include <cstdlib>
#include <ctime>

namespace xtd
{

    namespace random
    {

        void randomize ( void );

        int get_int ( int minimum , int maximum );

        bool coin_flip ( float win_rate_percent = 50 );

    }

}

#endif