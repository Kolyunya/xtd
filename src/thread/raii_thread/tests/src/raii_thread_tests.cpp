#include <gtest/gtest.h>
#include <thread.hpp>

TEST ( raii_thread_constructor , does_not_throw )
{
    ASSERT_NO_THROW(std::raii_thread<void(*)()> foo([](){;}));
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}