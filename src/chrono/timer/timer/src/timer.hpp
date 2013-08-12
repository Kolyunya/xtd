#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <stdexcept>
#include <thread>
#include <mutex>
#include <std/chrono.hpp>
#include <std/chrono/timer_event.hpp>
#include <std/event/event_dispatcher.hpp>

namespace std
{

	namespace chrono
	{
	
		class timer
			:
				public std::event_dispatcher
		{
		
			public:
				
				typedef std::chrono::high_resolution_clock			clock;
				
				typedef std::chrono::milliseconds					precision;
				
				typedef std::chrono::time_point<clock,precision>	time_point;
				
				explicit						timer ( const precision& tick_interval = precision(0) , const unsigned long& tick_limit = 0 );
				
				virtual							~timer ( void );
				
				bool							get_is_active ( void ) const;
				
				precision						get_tick_interval ( void ) const;
				
				unsigned long					get_tick_limit ( void ) const;
				
				unsigned long					get_last_tick_id ( void ) const;
				
				void							set_tick_interval ( const precision& tick_interval );
				
				void							set_tick_limit ( const unsigned long& tick_limit );
				
				bool							start ( bool throw_on_fail = false );
				
				bool							stop ( bool throw_on_fail = false );
				
			protected:
			
				time_point						get_time_point_current ( void ) const;
				
				bool							get_reached_tick_limit ( void ) const;
				
				bool							get_tick_required( void ) const;
				
				void							update_last_tick_time_point ( void );
				
				void							update_next_tick_time_point ( void );
				
				void							tick ( void );
				
				void							check_is_ready_to_start ( void ) const;
				
				void							check_is_ready_to_stop ( void ) const;
				
				static void						service_thread_routine ( timer* timer );
				
				precision						tick_interval;
				
				unsigned long					tick_limit;
				
				unsigned long					last_tick_id;
				
				time_point						last_tick_time_point;
				
				time_point						next_tick_time_point;
				
				bool							is_active;
				
				std::thread						service_thread;
				
				mutable std::recursive_mutex	data_mutex;			//	This mutex is used to restrict simultaneous access to timer data
				
				mutable std::recursive_mutex	command_mutex;		//	This mutex is used to restric simultaneous execution of timer commands
				
		};
		
	}
	
}

#include "timer.ipp"

#endif	// _TIMER_HPP_