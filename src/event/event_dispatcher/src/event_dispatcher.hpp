#ifndef _EVENT_DISPATCHER_HPP_
#define _EVENT_DISPATCHER_HPP_

#include <map>								//	std::multimap
#include <mutex>							//	std::recursive_mutex
											//	std::lock_guard
#include <stdexcept>						//	std::runtime_error
#include <std/functional/functor.hpp>		//	std::functor

namespace std
{

	typedef std::pair<int,abstract_functor*>		subscription;
	
	typedef std::multimap<int,abstract_functor*>	subscriptions_map;

	typedef subscriptions_map::iterator				subscription_itr;
	
	class event_dispatcher
	{

		public:

			virtual					~event_dispatcher ( void );

									template <typename listener>
			bool					add_event_listener ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) , bool throw_on_fail = 0 );

									template <typename listener>
			bool					remove_event_listener ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) , bool throw_on_fail = 0 );

		protected:

			void					dispatch_event ( int event_id , void* event_data_ptr );

									template <typename listener>
			subscription_itr		get_subscription_itr ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) ) noexcept;

			subscriptions_map		subscriptions;

			std::recursive_mutex	mutex;

	};

}

#include "event_dispatcher.ipp"
#include "event_dispatcher.tpp"

#endif	// _EVENT_DISPATCHER_HPP_