namespace std
{

            event_dispatcher::~event_dispatcher ( void )
    {

        // @description:    Frees memory allocated by event dispatcher before it's destruction.
        // @warning:        This function is blocking.



        std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);

        for ( auto subscriptions_itr = this->subscriptions.begin() ; subscriptions_itr != this->subscriptions.end() ; subscriptions_itr++ )
        {

            // `std::event_dispatcher::add_event_listener` creates instances of `std::functor` on the heap which must be deleted
            delete subscriptions_itr->second;

        }

    }

    void    event_dispatcher::dispatch_event ( int event_id , void* event_data_ptr )
    {

        // @description:    Notyfies all event listeners that it has occured and sends them data pointed by `event_data_ptr`
        // @parameter:      event_id - Event identifier which has occured
        // @parameter:      event_data_ptr - A pointer to an occured event data
        // @warning:        This function is blocking.



        std::lock_guard<std::recursive_mutex> lock_guard(this->mutex);

        // This method iterates over listeners to `event_id` event and invokes listener's methods. Listeners may add or delete subscriptions inside methods being invoked when event occurs.
        // If this will happen subscription iterator will be broken. Thus a copy of subscriptions collection is created.
        // Obviously subscriptions added during execution of this method will be executed only when next event happens.
        auto subscriptions_copy = this->subscriptions;

        auto subscriptions_for_current_event = subscriptions_copy.equal_range(event_id);

        for ( auto subscription_itr = subscriptions_for_current_event.first ; subscription_itr != subscriptions_for_current_event.second ; subscription_itr++ )
        {

            subscription_itr->second->invoke(event_data_ptr);

        }

    }

}