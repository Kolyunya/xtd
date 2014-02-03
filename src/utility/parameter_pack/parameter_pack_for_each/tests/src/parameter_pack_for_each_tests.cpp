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

/*

template < typename type >
void foo ( type object )
{
    //  foo the object
}

template < typename type >
void bar ( type object )
{
    //  bar the object
}

template < typename type >
void baz ( type object )
{
    //  baz the object
}

*/

TEST ( foo , bar )
{
    std::pp::for_each<printer,int,int,int>(4,2,42);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
