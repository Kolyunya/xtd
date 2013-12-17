#include <gtest/gtest.h>
#include <chrono/timer.hpp>

TEST ( timer_default_constuctor , does_not_throw )
{
    std::chrono::timer<std::chrono::high_resolution_clock> timer;
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}