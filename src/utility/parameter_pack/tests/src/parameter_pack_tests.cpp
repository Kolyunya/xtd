#include <gtest/gtest.h>
#include <typeinfo>
#include <utility/parameter_pack.hpp>

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::type_of_first<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(std::string).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( first_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::type_of_first<double,std::string,bool,int>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_000 )
{
    using first_parameter_type = typename std::type_of_last<std::string,bool,int,double>::type;
    std::size_t first_parameter_type_hash_expected = typeid(double).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

TEST ( last_parameter_pack_element_type , is_retrieved_correctly_001 )
{
    using first_parameter_type = typename std::type_of_last<double,std::string,bool,int>::type;
    std::size_t first_parameter_type_hash_expected = typeid(int).hash_code();
    std::size_t first_parameter_type_hash_actual = typeid(first_parameter_type).hash_code();
    bool first_parameter_is_recognized_correctly = first_parameter_type_hash_expected == first_parameter_type_hash_actual;
    ASSERT_TRUE(first_parameter_is_recognized_correctly);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}