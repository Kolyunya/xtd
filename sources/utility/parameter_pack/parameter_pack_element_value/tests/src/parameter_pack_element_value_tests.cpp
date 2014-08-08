//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

#include <gtest/gtest.h>
#include <utility/parameter_pack.hpp>

TEST ( retrieving_value_from_an_empty_pack , throws_out_of_range_exception )
{
    ASSERT_THROW
    (
        xstd::pp::nth_value<42>(),
        std::out_of_range
    );
}

TEST ( first_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = xstd::pp::first_value<>(42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( second_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = xstd::pp::nth_value<1>(4.2,42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( third_pack_element_value , is_being_retrieves_correctly_000 )
{
    int pack_element_value_expected = 42;
    int pack_element_value_actual = xstd::pp::nth_value<2>(true,4.2,42);
    ASSERT_EQ(pack_element_value_expected,pack_element_value_actual);
}

TEST ( last_pack_element_value , is_being_retrieves_correctly_000 )
{
    bool pack_element_value_expected = false;
    bool pack_element_value_actual = xstd::pp::last_value<>(true,4.2,42,false);
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