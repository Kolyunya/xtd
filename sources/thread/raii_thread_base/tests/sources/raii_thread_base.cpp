#include <gtest/gtest.h>
#include <xtd/thread/raii_thread_base.hpp>

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
