#include <gtest/gtest.h>
#include <typeinfo>
#include <utility/parameter_pack.hpp>

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::parameter_pack::type_of_first<>::type;
    std::size_t first_parameter_type_hash_expected = typeid(std::parameter_pack::null_type).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::parameter_pack::type_of_first<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(std::string).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_002 )
{
    using first_parameter_type = typename std::parameter_pack::type_of_first<double,std::string,bool,int>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::parameter_pack::type_of_last<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::parameter_pack::type_of_last<double,std::string,bool,int>::type;
    std::size_t first_parameter_type_hash_expected = typeid(int).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( empty_parameter_pack , is_homogeneous )
{
    bool empty_parameter_pack_is_homogeneous = std::parameter_pack::is_homogeneous<>::value;
    using empty_parameter_pack_type = std::parameter_pack::is_homogeneous<>::type;
    bool empty_parameter_pack_type_is_null_type = std::is_same<std::parameter_pack::null_type,empty_parameter_pack_type>::value;
    ASSERT_TRUE(empty_parameter_pack_is_homogeneous);
    ASSERT_TRUE(empty_parameter_pack_type_is_null_type);
}

TEST ( empty_parameter_pack , is_not_heterogeneous )
{
    bool empty_parameter_pack_is_heterogeneous = std::parameter_pack::is_heterogeneous<>::value;
    ASSERT_FALSE(empty_parameter_pack_is_heterogeneous);
}

TEST ( parameter_pack_consisting_of_one_integer , is_homogeneous )
{
    bool pack_is_homogeneous = std::parameter_pack::is_homogeneous<int>::value;
    using pack_type = std::parameter_pack::is_homogeneous<int>::type;
    bool pack_type_is_int = std::is_same<int,pack_type>::value;
    ASSERT_TRUE(pack_is_homogeneous);
    ASSERT_TRUE(pack_type_is_int);
}

TEST ( parameter_pack_consisting_of_one_integer , is_not_heterogeneous )
{
    bool parameter_pack_consisting_of_one_integer_is_heterogeneous = std::parameter_pack::is_heterogeneous<int>::value;
    ASSERT_FALSE(parameter_pack_consisting_of_one_integer_is_heterogeneous);
}

TEST ( parameter_pack_consisting_of_two_integers , is_homogeneous )
{
    bool parameter_pack_consisting_of_two_integers_is_homogeneous = std::parameter_pack::is_homogeneous<int,int>::value;
    ASSERT_TRUE(parameter_pack_consisting_of_two_integers_is_homogeneous);
}

TEST ( parameter_pack_consisting_of_two_integers , is_not_heterogeneous )
{
    bool parameter_pack_consisting_of_two_integers_is_heterogeneous = std::parameter_pack::is_heterogeneous<int,int>::value;
    ASSERT_FALSE(parameter_pack_consisting_of_two_integers_is_heterogeneous);
}

TEST ( parameter_pack_consisting_of_integer_and_float , is_not_homogeneous )
{
    bool parameter_pack_consisting_of_integer_and_float_is_not_homogeneous = std::parameter_pack::is_homogeneous<int,float>::value;
    ASSERT_FALSE(parameter_pack_consisting_of_integer_and_float_is_not_homogeneous);
}

TEST ( parameter_pack_consisting_of_three_integers , is_homogeneous )
{
    bool parameter_pack_consisting_of_three_integers_is_homogeneous = std::parameter_pack::is_homogeneous<int,int,int>::value;
    ASSERT_TRUE(parameter_pack_consisting_of_three_integers_is_homogeneous);
}

TEST ( parameter_pack_consisting_of_three_integers_and_boolean , is_heterogeneous )
{
    bool parameter_pack_consisting_of_three_integers_and_boolean_is_heterogeneous = std::parameter_pack::is_heterogeneous<int,int,int,bool>::value;
    ASSERT_TRUE(parameter_pack_consisting_of_three_integers_and_boolean_is_heterogeneous);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
