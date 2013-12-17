#ifndef _STD_TIMER_HPP_
#define _STD_TIMER_HPP_

#include <vector>
#include <event.hpp>
#include <chrono/timer_manager.hpp>

namespace std
{

    namespace chrono
    {

        template <typename clock = high_resolution_clock>
        class timer
        {
            public:

                using duration = typename clock::duration;

                using time_point = typename clock::time_point;

                using event_start_type = typename std::event<>;

                using event_tick_type = typename std::event <unsigned int>;

                using event_complete_type = typename std::event<>;

                using event_stop_type = typename std::event<>;


                explicit                timer ( void )
                                            :
                                                is_active(false),
                                                ticks_done(0)
                {

                }

                virtual                 ~timer ( void ) noexcept
                {
                    this->stop();
                }

                void                    get_is_active ( void ) const
                {
                    return this->is_active;
                }

                void                    get_ticks_done ( void ) const
                {
                    return this->ticks_done();
                }

                void                    start ( void )
                {
                    this->check_is_ready_to_start();
                    timer_manager::get_instance().add_timer(this);
                    this->update_next_tick_time_point();
                    this->is_active = true;
                    this->event_start.dispatch();
                }

                void                    stop ( void )
                {
                    this->check_is_ready_to_stop();
                    timer_manager::get_instance().remove_timer(this);
                    this->is_active = false;
                    this->ticks_done = 0;
                    this->event_stop.dispatch();
                }

                duration                tick_interval;

                unsigned int            tick_limit;

                event_start_type        event_start;

                event_tick_type         event_tick;

                event_complete_type     event_complete;

                event_stop_type         event_stop;


            protected:

                bool                    requires_tick ( void )
                {
                    return clock::now() >= this->next_tick_time_point;
                }

                void                    tick ( void )
                {

                    if ( this->requires_tick() == true )
                    {

                        this->last_tick_id++;
                        this->update_next_tick_time_point();
                        this->event_tick.dispatch(this->last_tick_id);

                        if ( this->last_tick_id == this->tick_limit )
                        {
                            this->event_complete.dispatch();
                            this->stop();
                            return;
                        }

                    }

                }

                void                    update_next_tick_time_point ( void )
                {


                }

                void                    check_is_ready_to_start ( void ) const
                {
                    if
                    (
                        this->tick_interval.count() == 0
                            ||
                        this->is_active == true
                    )
                    {
                        throw std::runtime_error("Timer is not ready to start");
                    }
                }

                void                    check_is_ready_to_stop ( void ) const
                {
                    if ( this->is_active == false )
                    {

                        throw std::runtime_error("Timer is already stopped");

                    }
                }

                bool                    is_active;

                unsigned int            ticks_done;

                time_point              next_tick_time_point;

        };

    }

}

#endif  //  _STD_TIMER_HPP_