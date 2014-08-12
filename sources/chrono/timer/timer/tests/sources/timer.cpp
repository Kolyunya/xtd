#include <gtest/gtest.h>
#include <xtd/chrono.hpp>
#include <iostream>

/*
TEST ( timer_default_constuctor , does_not_throw )
{
    ASSERT_NO_THROW(delete(new std::chrono::timer<std::chrono::high_resolution_clock>()));
}
*/

TEST ( timer , does_not_throw_while_starting )
{
    xstd::chrono::timer<std::chrono::high_resolution_clock> timer;
    timer.event_tick.add_listener
    (
        [
        ]
        (
            unsigned int tick_id
        )
        {
            std::cout << "Tick id: " << tick_id << std::endl;
        }
    );
    timer.tick_interval = std::chrono::seconds(1);
    timer.tick_limit = 3;

    timer.start();

    while (  timer.get_is_active() == true )
    {

    }

    ASSERT_TRUE(true);

}


int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}