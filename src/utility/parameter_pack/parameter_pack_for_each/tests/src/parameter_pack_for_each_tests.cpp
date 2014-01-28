#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>
#include <iostream>

void printer ( int integer )
{
    std::cout << integer << std::endl;
}

TEST ( foo , bar )
{
    std::pp::for_each<printer,int,int,int>(4,2,42);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
