#include <gtest/gtest.h>
#include <xtd/thread/raii_thread_manual.hpp>
/*
TEST ( raii_thread_constructor , does_not_throw_0 )
{
    xtd::thread::raii_thread<void(*)()> foo([](){});
}

TEST ( raii_thread_constructor , does_not_throw_1 )
{
    xtd::thread::raii_thread<void(*)(int),int> foo([](int){},1);
}
*/
int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}