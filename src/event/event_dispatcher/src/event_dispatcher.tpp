namespace std
{

						template <typename listener>
	bool				event_dispatcher::add_event_listener ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) , bool throw_on_fail )
	{
	
		//	@description:		Registers object pointed by `listener_ptr` to listen to event `event_id` and invoke method pointed by `method_ptr` on this event.
		//	@parameter:			event_id - Event identifier to which the listener will listen to.
		//	@parameter:			listener_ptr - A pointer to a listener which will listen to the event.
		//	@parameter:			method_ptr - A pointer to a listener's method which will be invoked when event occurs. Must be accessible by the event dispatcher.
		//	@parameter:			throw_on_fail - A flag which causes the function to throw an `std::runtime_error` on error. If not set, function will return `false` otherwise.
		//	@warning:			This function is blocking.
		//	@warning:			Method pointed by `method_ptr` must be accessible by the event dispatcher.
		//	@warning:			Listener must delete registrated subscriptions manually before being destroyed. Subscriptions are not being deleted automatically after listener destruction.
		//	@throws				std::runtime_error - When trying to add a subscription which already exists
		//	@throw_guarantee:	Strong no-throw guarantee.
		
		
		
		std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);
		
		if ( this->get_subscription_itr(event_id,listener_ptr,method_ptr) != this->subscriptions.end() )
		{
		
			if ( throw_on_fail )
			{
			
				throw std::runtime_error("Subscription already exists");
			
			}
			
			return false;

		}

		auto functor_ptr = new functor<listener>(listener_ptr,method_ptr);
		
		this->subscriptions.insert(subscription(event_id,functor_ptr));
		
		return true;
	
	}

						template <typename listener>
	bool				event_dispatcher::remove_event_listener ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) , bool throw_on_fail )
	{
	
		//	@description:		Removes the subscription defined by object pointed by `listener_ptr`, event `event_id` and method pointed by `method_ptr`.
		//	@parameter:			event_id - Event identifier to which the listener is listening to.
		//	@parameter:			listener_ptr - A pointer to a listener which will listening to the event.
		//	@parameter:			method_ptr - A pointer to a listener's method which will is being invoked when event occurs.
		//	@parameter:			throw_on_fail - A flag which causes the function to throw an `std::runtime_error` on error. If not set, function will return `false` otherwise.
		//	@warning:			This function is blocking.
		//	@throw:				std::runtime_error - When trying to remove a subscription which does not exist yet
		//	@throw_guarantee:	Strong no-throw guarantee.
		
		
		
		
		std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);

		subscription_itr subscription_itr = this->get_subscription_itr(event_id,listener_ptr,method_ptr);

		if ( subscription_itr == this->subscriptions.end() )
		{
		
			if ( throw_on_fail )
			{
			
				throw std::runtime_error("Subscription does not exist");
			
			}

			return false;

		}

		this->subscriptions.erase(subscription_itr);
		
		return true;

	}

						template <typename listener>
	subscription_itr	event_dispatcher::get_subscription_itr ( int event_id , listener* listener_ptr , void(listener::*method_ptr)(void*) ) noexcept
	{
	
		//	@description:	Looks for a subscription defined by object pointed by `listener_ptr`, event `event_id` and method pointed by `method_ptr`.
		//	@parameter:		event_id - Event identifier.
		//	@parameter:		listener_ptr - A pointer to a listener.
		//	@parameter:		method_ptr - A pointer to a listener's method.
		//	@return:		If subscription is found returns its iterator or `this->subscriptions.end()` otherwise.

		
		
		auto all_subscriptions_for_current_event = this->subscriptions.equal_range(event_id);
		
		auto subscription_itr = all_subscriptions_for_current_event.first;

		for ( ; subscription_itr != all_subscriptions_for_current_event.second ; subscription_itr++ )
		{
		
			auto functor_current = dynamic_cast <functor<listener>*> ( (*subscription_itr).second );

			if
			(
				functor_current
					&&
				functor_current->object == listener_ptr
					&&
				functor_current->method == method_ptr
			)
			{

				break;

			}

		}

		return subscription_itr;

	}
	
}