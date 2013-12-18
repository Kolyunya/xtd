#include <gtest/gtest.h>
#include <iostream>
#include <chrono/timer.hpp>

TEST ( timer_default_constuctor , does_not_throw )
{
    ASSERT_NO_THROW(delete(new std::chrono::timer<std::chrono::high_resolution_clock>()));
}

TEST ( timer , does_not_throw_while_starting )
{
    std::chrono::timer<std::chrono::high_resolution_clock> timer;
    timer.tick_interval = std::chrono::seconds(1);
    timer.tick_limit = 5;
    timer.start();
    timer.event_tick.add_listener([](unsigned int tick_id){std::cout << tick_id << std::endl;});
    while ( true )
    {

    }
    ASSERT_NO_THROW(timer.start());
}



int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}