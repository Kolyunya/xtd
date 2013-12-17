#include "timer.hpp"

namespace std
{
    namespace chrono
    {

                                timer::timer ( const precision& tick_interval , const unsigned long& tick_limit )
                                    :
                                        tick_interval ( tick_interval ),
                                        tick_limit ( tick_limit ),
                                        last_tick_id ( 0 ),
                                        is_active ( false )
        {

            // Data races can not occur during object construction, since an object which is not constructed yet can not be called anyhow.
            // Thus no data protection needed in the constructor and no need to call setters for tick interval and tick limit.
            // Using initializer list will also give a tiny performance advantage

        }

                                timer::~timer ( void )
        {

            // @warning Execution may be block for a duration which does not exceed `timer::tick_interval` much

            // Timer must be stopped before destroying. Otherwise service service_thread will have a danglign pointer to the timer
            this->stop();

            // Service theread is guaranteed to be joined at this point. Thus it's safe to delete the timer.

        }

        bool                    timer::get_is_active ( void ) const
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            return this->is_active;

        }

        timer::precision        timer::get_tick_interval ( void ) const
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            return this->tick_interval;

        }

        unsigned long           timer::get_tick_limit ( void ) const
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            return this->tick_limit;

        }

        unsigned long           timer::get_last_tick_id ( void ) const
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            return this->last_tick_id;

        }

        void                    timer::set_tick_interval ( const precision& tick_interval )
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            this->tick_interval = tick_interval;

            // The time of next tick changes when tick interval is changed
            this->update_next_tick_time_point();

        }

        void                    timer::set_tick_limit ( const unsigned long& tick_limit )
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            this->tick_limit = tick_limit;

        }

        bool                    timer::start ( bool throw_on_fail )
        {

            // @warning There is no guarantee that the service service_thread started execution after this method is complete
            // @throws timer_is_not_configured if timer is not configured yet
            // @throws timer_is_active if timer is active

            // Commands changing timer state must execute mutually exclusive
            std::lock_guard<std::recursive_mutex> commandLockGuard(this->command_mutex);

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            try
            {

                this->check_is_ready_to_start();

            }

            catch ( std::runtime_error timer_is_not_ready_to_start )
            {

                if ( throw_on_fail )
                {

                    throw timer_is_not_ready_to_start;

                }

                return false;

            }

            this->is_active = true;
            this->update_last_tick_time_point();

            this->service_thread = std::thread(timer::service_thread_routine,this);

            this->dispatch_event(TIMER_EVENT_START,nullptr);

            return true;

        }

        bool                    timer::stop ( bool throw_on_fail )
        {

            // @warning Execution may be block for a duration which does not exceed `timer::tick_interval` much. This is caused by service service_thread which is being joined during execution
            // @throws timer_is_stopped if timer is already stopped

            // Commands changing timer state must execute mutually exclusive
            std::lock_guard<std::recursive_mutex> commandLockGuard(this->command_mutex);

            // Data must me protected from simultaneous read and write access
            // Data should be unlocked manually later thus `unique_lock` is used
            std::unique_lock<std::recursive_mutex> dataUniqueLock(this->data_mutex);

            try
            {

                this->check_is_ready_to_stop();

            }

            catch ( std::runtime_error timer_is_not_ready_to_stop )
            {

                if ( throw_on_fail )
                {

                    throw timer_is_not_ready_to_stop;

                }

                return false;

            }

            this->is_active = false;
            this->last_tick_id = 0;
            this->last_tick_time_point -= this->last_tick_time_point.time_since_epoch();

            // Unlock data mutex so that srevice service_thread can read it
            // Commands still can NOT be executed since command mutex is still locked
            dataUniqueLock.unlock();

            // Thread is always joinable at this point since it's either scheduled or executing or finished executing
            this->service_thread.join();

            // There is a guarantee that service service_thread finished execution at this point

            this->dispatch_event(TIMER_EVENT_STOP,nullptr);

            return true;

        }

        timer::time_point       timer::get_time_point_current ( void ) const
        {

            return std::chrono::time_point_cast<timer::precision> (timer::clock::now());

        }

        bool                    timer::get_reached_tick_limit ( void ) const
        {

            // Data must me protected from simultaneous read and write access
            std::lock_guard<std::recursive_mutex> dataLockGuard(this->data_mutex);

            // `tick_limit` equal to `0` means the timer has no tick limit
            if ( this->tick_limit == 0 )
            {

                return false;

            }

            // Current tick reached the limit
            if ( this->last_tick_id >= this->tick_limit )
            {

                return true;

            }

            return false;

        }

        bool                    timer::get_tick_required ( void ) const
        {

            // Next timer tick is required when current time equals or is greater than the time of last tick plus tick interval
            time_point nextTickTimePoint = this->last_tick_time_point + this->tick_interval;
            time_point currentTimePoint = std::chrono::time_point_cast<precision>(timer::clock::now());

            return currentTimePoint >= nextTickTimePoint;

        }

        void                    timer::update_last_tick_time_point ( void )
        {

            this->last_tick_time_point = this->get_time_point_current();

        }

        void                    timer::update_next_tick_time_point ( void )
        {

            this->next_tick_time_point = this->last_tick_time_point + this->tick_interval;

        }

        void                    timer::tick ( void )
        {

            // Warning: this is unreliable since `startInstantly` could be used
            this->last_tick_id++;

            this->update_last_tick_time_point();
            this->update_next_tick_time_point();

            this->dispatch_event(TIMER_EVENT_TICK,nullptr);

            if ( this->get_reached_tick_limit() )
            {

                this->dispatch_event(TIMER_EVENT_COMPLETE,nullptr);

                this->stop();

            }

        }

        void                    timer::check_is_ready_to_start ( void ) const
        {

            // Warning: `timer::data_mutex`must be locked before calling this method

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

        void                    timer::check_is_ready_to_stop ( void ) const
        {

            // Warning: `timer::data_mutex`must be locked before calling this method

            // `timer::last_tick_time_point` is zero ONLY if timer is stopped
            if ( this->last_tick_time_point.time_since_epoch() == timer::precision(0) )
            {

                throw std::runtime_error("Timer is not ready to stop");

            }

        }

        void                    timer::service_thread_routine ( timer* timer )
        {

            while ( 1 )
            {

                // Data must me protected from simultaneous read and write access
                std::lock_guard<std::recursive_mutex> dataLockGuard(timer->data_mutex);

                if ( timer->is_active == false )
                {

                    // timer was deactivated
                    return;

                }

                if ( timer->get_tick_required() )
                {

                    timer->tick();

                }

            }

        }

    }

}