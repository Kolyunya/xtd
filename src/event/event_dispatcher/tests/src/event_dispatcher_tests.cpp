#include <gtest/gtest.h>
#include <std/event/event_dispatcher.hpp>

class event_dispatcher : public std::event_dispatcher
{

    public:

        void dispatch_phony_event ( void )
        {

            this->dispatch_event(0,nullptr);

        }

};

class success
{

};

class event_listener
{

    public:

        void do_something ( void* )
        {

            throw success();

        }

};

TEST ( event_dispatcher , does_not_throw_exceptions_while_construction )
{

    ASSERT_NO_THROW ( event_dispatcher() );

}

TEST ( event_dispatcher , does_not_throw_exceptions_while_adding_subscription )
{

    event_dispatcher dispatcher;
    event_listener listener;

    ASSERT_NO_THROW ( dispatcher.add_event_listener(0,&listener,&event_listener::do_something) );

}

TEST ( event_dispatcher , throws_runtime_error_while_trying_to_add_subscription_which_already_exists )
{

    event_dispatcher dispatcher;
    event_listener listener;

    dispatcher.add_event_listener(0,&listener,&event_listener::do_something);

    ASSERT_THROW ( dispatcher.add_event_listener(0,&listener,&event_listener::do_something,true) , std::runtime_error );

}

TEST ( event_dispatcher , does_not_throw_exceptions_while_trying_to_add_subscriptions_to_different_events )
{

    event_dispatcher dispatcher;
    event_listener listener;

    dispatcher.add_event_listener(0,&listener,&event_listener::do_something);

    ASSERT_NO_THROW ( dispatcher.add_event_listener(1,&listener,&event_listener::do_something) );

}

TEST ( event_dispatcher , throws_runtime_error_while_trying_to_delete_subscription_which_does_not_exist_yet )
{

    event_dispatcher dispatcher;
    event_listener listener;

    ASSERT_THROW ( dispatcher.remove_event_listener(0,&listener,&event_listener::do_something,true) , std::runtime_error );

}

TEST ( event_dispatcher , does_not_throw_exceptions_while_trying_to_delete_subscription_which_already_exists )
{

    event_dispatcher dispatcher;
    event_listener listener;

    dispatcher.add_event_listener(0,&listener,&event_listener::do_something);
    ASSERT_NO_THROW ( dispatcher.remove_event_listener(0,&listener,&event_listener::do_something) );

}

TEST ( event_dispatcher , does_not_throw_when_dispatching_event_while_having_zero_subscriptions )
{

    event_dispatcher dispatcher;

    ASSERT_NO_THROW ( dispatcher.dispatch_phony_event() );

}

int main ( int argc , char** argv )
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}