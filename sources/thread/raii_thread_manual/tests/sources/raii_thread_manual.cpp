#include <gtest/gtest.h>
#include <xtd/thread.hpp>

TEST ( raii_thread_constructor , does_not_throw_0 )
{
    std::function<void()> foo = [](){};
    xtd::thread::raii_thread_manual bar(foo);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}