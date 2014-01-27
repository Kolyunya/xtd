#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>

TEST ( pack , is_homogeneous_000 )
{
    bool pack_is_homogeneous = std::pp::is_homogeneous<>::value;
    ASSERT_TRUE(pack_is_homogeneous);
}

TEST ( pack , is_homogeneous_001 )
{
    bool pack_is_homogeneous = std::pp::is_homogeneous<int>::value;
    ASSERT_TRUE(pack_is_homogeneous);
}

TEST ( pack , is_heterogeneous_000 )
{
    bool pack_is_heterogeneous = std::pp::is_heterogeneous<int,float>::value;
    ASSERT_TRUE(pack_is_heterogeneous);
}

TEST ( pack_type , is_retrieved_correctly_000 )
{
    using pack_type_expected = std::pp::null_type;
    using pack_type_actual = std::pp::is_homogeneous<>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_001 )
{
    using pack_type_expected = std::pp::null_type;
    using pack_type_actual = std::pp::is_homogeneous<int,bool>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_002 )
{
    using pack_type_expected = int;
    using pack_type_actual = std::pp::is_homogeneous<int>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_003 )
{
    using pack_type_expected = int;
    using pack_type_actual = std::pp::is_homogeneous<int,int,int>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}