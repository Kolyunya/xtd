#include <gtest/gtest.h>
#include <chrono.hpp>

class timer_client
{
    public:
        void tick ( void* )
        {
            std::cout << "tick" << std::endl;
        }
};

TEST ( timer_constructor , does_not_throw_when_no_arguments_provided )
{

    ASSERT_NO_THROW ( std::chrono::timer() );

}

TEST ( timer_constructor , does_not_throw_when_two_arguments_provided )
{

    ASSERT_NO_THROW ( std::chrono::timer(std::chrono::timer::precision(42),42) );

}

TEST ( timer_constructor , sets_tick_interval_effectively )
{

    std::chrono::timer timer(std::chrono::timer::precision(42));

    ASSERT_EQ ( timer.get_tick_interval() , std::chrono::timer::precision(42) );

}

TEST ( timer_constructor , sets_tick_limit_effectively )
{

    std::chrono::timer timer(std::chrono::timer::precision(42),42);

    ASSERT_EQ ( timer.get_tick_limit() , 42 );

}

TEST ( timer_constructor , defaults_tick_interval_to_zero )
{

    std::chrono::timer timer;

    ASSERT_EQ ( timer.get_tick_interval() , std::chrono::timer::precision(0) );

}

TEST ( timer_constructor , defaults_tick_limit_to_zero )
{

    std::chrono::timer timer;

    ASSERT_EQ ( timer.get_tick_limit() , 0 );

}

TEST ( timer_constructor , initializes_last_tick_id_with_zero )
{

    std::chrono::timer timer;

    ASSERT_EQ ( timer.get_last_tick_id() , 0 );

}

TEST ( timer_constructor , initializes_timer_active_with_false )
{

    std::chrono::timer timer;

    ASSERT_EQ ( timer.get_is_active() , false );

}

TEST ( timer , throws_while_trying_to_start_when_not_configured )
{

    std::chrono::timer timer;

    ASSERT_THROW ( timer.start(true) , std::runtime_error );

}

TEST ( foo , bar )
{

    std::chrono::timer timer(std::chrono::timer::precision(1000));
    timer_client client;
    timer.add_event_listener(std::chrono::TIMER_EVENT_TICK,&client,&timer_client::tick);
    timer.start();
    while(1);

}

int main ( int argc , char** argv )
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}