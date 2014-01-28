#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>

TEST ( type_of_the_first_parameter_of_an_empty_pack , is_null_type )
{
    using parameter_type_expected = std::pp::null_type;
    using parameter_type_actual = std::pp::first_type<>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_second_parameter_of_a_single_element_pack , is_null_type )
{
    using parameter_type_expected = std::pp::null_type;
    using parameter_type_actual = std::pp::nth_type<1,bool>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_tenth_parameter_of_a_three_elements_pack , is_null_type )
{
    using parameter_type_expected = std::pp::null_type;
    using parameter_type_actual = std::pp::nth_type<9,bool,char,int>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_minus_tenth_parameter_of_a_five_elements_pack , is_null_type )
{
    using parameter_type_expected = std::pp::null_type;
    using parameter_type_actual = std::pp::nth_type<-10,bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_minus_first_parameter_of_a_five_elements_pack , is_null_type )
{
    using parameter_type_expected = std::pp::null_type;
    using parameter_type_actual = std::pp::nth_type<-1,bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_first_parameter_of_a_pack , is_retrieved_correctly_000 )
{
    using parameter_type_expected = bool;
    using parameter_type_actual = std::pp::first_type<bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_first_parameter_of_a_pack , is_retrieved_correctly_001 )
{
    using parameter_type_expected = char;
    using parameter_type_actual = std::pp::first_type<char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_last_parameter_of_a_pack , is_retrieved_correctly_000 )
{
    using parameter_type_expected = double;
    using parameter_type_actual = std::pp::last_type<bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_last_parameter_of_a_pack , is_retrieved_correctly_001 )
{
    using parameter_type_expected = float;
    using parameter_type_actual = std::pp::last_type<bool,char,int,float>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_third_parameter_of_a_pack , is_retrieved_correctly )
{
    using parameter_type_expected = int;
    using parameter_type_actual = std::pp::nth_type<2,bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

TEST ( type_of_the_forth_parameter_of_a_pack , is_retrieved_correctly )
{
    using parameter_type_expected = float;
    using parameter_type_actual = std::pp::nth_type<3,bool,char,int,float,double>::type;
    bool parameter_type_is_retrieved_correctly = std::is_same<parameter_type_expected,parameter_type_actual>::value;
    ASSERT_TRUE(parameter_type_is_retrieved_correctly);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
