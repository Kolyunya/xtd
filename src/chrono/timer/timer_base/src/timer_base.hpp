#ifndef _STD_TIMER_BASE_HPP_
#define _STD_TIMER_BASE_HPP_

#include <vector>

namespace std
{

    namespace chrono
    {

        class timer_base
        {

            public:

                virtual         ~timer_base ( void ) noexcept = default;

                virtual void    tick ( void ) = 0;

        };

        using timers_vector = vector<timer_base*>;

        using timers_vector_citr = timers_vector::const_iterator;

        using timers_vector_itr = timers_vector::iterator;

    }

}

#endif  //  _STD_TIMER_BASE_HPP_