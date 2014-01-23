#include <gtest/gtest.h>
#include <typeinfo>
#include <utility/parameter_pack.hpp>

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::parameter_pack::first_type<>::type;
    std::size_t first_parameter_type_hash_expected = typeid(std::parameter_pack::null_type).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::parameter_pack::first_type<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(std::string).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_002 )
{
    using first_parameter_type = typename std::parameter_pack::first_type<double,std::string,bool,int>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::parameter_pack::last_type<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::parameter_pack::last_type<double,std::string,bool,int>::type;
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

TEST ( first_value_of_parameter_pack , is_retrieved_correctly_000 )
{
    int parameter_pack_element_value_expected = 42;
    int parameter_pack_element_value_actual = std::parameter_pack::nth_value<0>(42);
    ASSERT_EQ(parameter_pack_element_value_actual,parameter_pack_element_value_expected);
}

TEST ( first_value_of_parameter_pack , is_retrieved_correctly_001 )
{
    int parameter_pack_element_value_expected = 42;
    int parameter_pack_element_value_actual = std::parameter_pack::nth_value<0>(42,true);
    ASSERT_EQ(parameter_pack_element_value_actual,parameter_pack_element_value_expected);
}

TEST ( first_value_of_parameter_pack , is_retrieved_correctly_002 )
{
    std::string parameter_pack_element_value_expected = "foo";
    std::string parameter_pack_element_value_actual = std::parameter_pack::nth_value<1,int,std::string>(42,"foo");
    ASSERT_EQ(parameter_pack_element_value_actual,parameter_pack_element_value_expected);
}

TEST ( retrieving_value_from_empty_parameter_pack , throws_runtime_error )
{
    ASSERT_THROW
    (
        std::parameter_pack::nth_value<42>(),
        std::runtime_error
    );
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
