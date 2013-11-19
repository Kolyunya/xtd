#ifndef _EVENT_DISPATCHER_HPP_
#define _EVENT_DISPATCHER_HPP_

#include <map>                  // std::multimap
#include <mutex>                // std::recursive_mutex
                                // std::lock_guard
#include <stdexcept>            // std::runtime_error
#include <functional.hpp>       // std::functor

namespace std
{

    typedef std::pair<int,abstract_functor*>        subscription;

    typedef std::multimap<int,abstract_functor*>    subscriptions_map;

    typedef subscriptions_map::iterator             subscription_itr;

    class event_dispatcher
    {

        //  Header-only class hence non-template methods must be declared as inline

        public:

            inline virtual          ~event_dispatcher ( void );

                                    template <typename listener_type , typename parameter_type>
            bool                    add_event_listener ( int event_id , listener_type* listener_ptr , void(listener_type::*method)(parameter_type*) , bool throw_on_fail = 0 );

                                    template <typename listener_type , typename parameter_type>
            bool                    add_event_listener ( int event_id , const functor<listener_type,parameter_type>& listener , bool throw_on_fail = 0 );

                                    template <typename listener_type , typename parameter_type>
            bool                    remove_event_listener ( int event_id , listener_type* listener_ptr , void(listener_type::*method)(parameter_type*) , bool throw_on_fail = 0 );

                                    template <typename listener_type , typename parameter_type>
            bool                    remove_event_listener ( int event_id , const functor<listener_type,parameter_type>& listener , bool throw_on_fail = 0 );

        protected:

            inline void             dispatch_event ( int event_id , void* event_data_ptr );

                                    template <typename listener_type , typename parameter_type>
            subscription_itr        get_subscription_itr ( int event_id , listener_type* listener_ptr , void(listener_type::*method_ptr)(parameter_type*) ) noexcept;

            subscriptions_map       subscriptions;

            std::recursive_mutex    mutex;

    };

}

// Include implementation file
#include "event_dispatcher.ipp"

// Include templates implementation file
#include "event_dispatcher.tpp"

#endif  // _EVENT_DISPATCHER_HPP_