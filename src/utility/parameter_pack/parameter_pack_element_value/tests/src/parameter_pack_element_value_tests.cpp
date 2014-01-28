#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>

TEST ( retrieving_value_from_an_empty_pack , throws_out_of_range_exception )
{
    ASSERT_THROW
    (
        std::pp::nth_value<42>(),
        std::out_of_range
    );
}

TEST ( first_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = std::pp::first_value<>(42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( second_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = std::pp::nth_value<1>(4.2,42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( third_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = std::pp::nth_value<2>(true,4.2,42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( last_pack_element_value , is_being_retrieves_correctly_000 )
{
    bool pack_element_value_expected = false;
    bool pack_element_value_actual = std::pp::last_value<>(true,4.2,42,false);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}




/*
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
    std::string parameter_pack_element_value_actual = std::parameter_pack::nth_value<1>(42,"foo",true,0.5f);
    ASSERT_EQ(parameter_pack_element_value_expected,parameter_pack_element_value_actual);
}

TEST ( retrieving_value_from_empty_parameter_pack , throws_runtime_error )
{
    ASSERT_THROW
    (
        std::parameter_pack::nth_value<42>(),
        std::runtime_error
    );
}
*/

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
