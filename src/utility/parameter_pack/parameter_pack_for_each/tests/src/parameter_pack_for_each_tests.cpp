#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>
#include <iostream>

struct printer
{
    template < typename type >
    static void process ( type object )
    {
        std::cout << object << std::endl;
    }
};

TEST ( foo , bar )
{
    std::pp::for_each<printer>(4,2,42);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
