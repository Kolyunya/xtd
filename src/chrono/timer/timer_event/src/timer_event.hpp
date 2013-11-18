#ifndef _TIMER_EVENT_HPP_
#define _TIMER_EVENT_HPP_

namespace std
{

    namespace chrono
    {

        enum timer_event
        {

            TIMER_EVENT_START,

            TIMER_EVENT_STOP,

            TIMER_EVENT_TICK,

            TIMER_EVENT_COMPLETE

        };

    }

}

#endif    // _TIMER_EVENT_HPP_