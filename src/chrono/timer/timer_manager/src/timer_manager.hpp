#ifndef _STD_TIMER_MANAGER_HPP_
#define _STD_TIMER_MANAGER_HPP_

#include <memory>
#include <vector>
#include <thread.hpp>
#include <chrono/timer_base.hpp>

namespace std
{

    namespace chrono
    {

        class timer_manager
        {
            public:

                static timer_manager&       get_instance ( void )
                {
                    //  No mutex needed here because local statics are initialized in a thread-safe manner in C++11
                    //  and the "instance" is not modified after the instantiation
                    static timer_manager instance;
                    return instance;
                }

                void                        add_timer ( timer_base* const timer_ptr )
                {
                    std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);
                    this->check_has_no_timer(timer_ptr);
                    this->timers.push_back(timer_ptr);
                    this->start_thread_if_needed();
                }

                void                        remove_timer ( timer_base* const timer_ptr )
                {
                    std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);
                    this->check_has_timer(timer_ptr);
                    this->timers.erase(this->get_timer_itr(timer_ptr));
                    this->stop_thread_if_needed();
                }

            private:

                explicit                    timer_manager ( void )
                                                :
                                                    thread(std::bind(timer_manager::thread_routine,this))
                {

                }

                virtual                     ~timer_manager ( void ) noexcept
                {

                }

                bool                        has_timer ( const timer_base* timer_ptr ) const
                {
                    return this->get_timer_itr(timer_ptr) != this->timers.cend();
                }

                void                        check_has_timer ( const timer_base* timer_ptr ) const
                {
                    if ( this->has_timer(timer_ptr) == false )
                    {
                        throw std::runtime_error("Timer is not being managed");
                    }
                }

                void                        check_has_no_timer ( const timer_base* timer_ptr ) const
                {
                    if ( this->has_timer(timer_ptr) == true )
                    {
                        throw std::runtime_error("Timer is already being managed");
                    }
                }

                void                        start_thread_if_needed ( void )
                {

                    //  Starts the thread if there is exactly one active timer
                    //  If there are more than one timer the thread is already started
                    //  This function is called from "timer_manager::add_timer"
                    if ( this->timers.size() == 1 )
                    {
                        this->thread.start();
                    }

                }

                void                        stop_thread_if_needed ( void )
                {

                    //  Stops the thread if there are no active timers
                    //  This function is called from "timer_manager::add_timer"
                    if ( this->timers.empty() )
                    {
                        this->thread.stop();
                    }

                }

                timers_vector_itr           get_timer_itr ( const timer_base* timer_ptr ) const
                {

                    timers_vector_itr timers_vector_itr_obj = this->timers.begin();

                    for ( ; timers_vector_itr_obj != this->timers.end() ; timers_vector_itr_obj++ )
                    {

                        if ( *timers_vector_itr_obj == timer_ptr )
                        {

                            return timers_vector_itr_obj;

                        }

                    }

                    return this->timers.end();

                }

                static void                 thread_routine ( const timer_manager* timer_manager_ptr )
                {

                    for ( timer_base* timer_ptr : timer_manager_ptr->timers )
                    {

                        try
                        {

                            timer_ptr->tick();

                        }

                        catch ( ... )
                        {

                            continue;

                        }

                    }

                }

                timer_manager&              operator= ( timer_manager& ) = delete;

                raii_thread_manual          thread;

                std::recursive_mutex        mutex;

                mutable timers_vector       timers;

        };

    }

}

#endif  //  _STD_TIMER_MANAGER_HPP_