#include <gtest/gtest.h>
#include <xtd/thread/raii_thread.hpp>

TEST ( raii_thread_constructor , does_not_throw_0 )
{
    std::function<void()> foo = [](){};
    xtd::thread::raii_thread bar(foo);
}
/*
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