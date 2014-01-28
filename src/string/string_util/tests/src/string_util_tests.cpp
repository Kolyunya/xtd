#include <gtest/gtest.h>
#include <string.hpp>



TEST ( std_string_to_int , converts_5667859_dec_to_5667859_dec )
{

    std::string source_string = "5667859";
    int result_number_correct = 5667859;
    int result_number_actual = std::string_to_int(source_string,10);

    ASSERT_EQ ( result_number_correct , result_number_actual );

}

TEST ( std_string_to_int , converts_111_bin_to_7_dec )
{

    std::string source_string = "111";
    int result_number_correct = 7;
    int result_number_actual = std::string_to_int(source_string,2);

    ASSERT_EQ ( result_number_correct , result_number_actual );

}

TEST ( std_string_to_int , converts_111_hex_to_273_dec )
{

    std::string source_string = "111";
    int result_number_correct = 273;
    int result_number_actual = std::string_to_int(source_string,16);

    ASSERT_EQ ( result_number_correct , result_number_actual );

}

TEST ( string_5667859 , converts_to_integer_5667859 )
{

    std::string string = "5667859";
    int number_correct = 5667859;
    int number_converted = std::string_to_long_int(string);

    ASSERT_EQ ( number_correct , number_converted );

}

TEST ( string_5667857_999 , converts_to_integer_5667857 )
{

    std::string string = "5667857.999";
    int number_correct = 5667857;
    int number_converted = std::string_to_long_int(string);

    ASSERT_EQ ( number_correct , number_converted );

}

TEST ( string_14_5631 , converts_to_float_14_5631 )
{

    std::string string = "14.5631";
    float number_correct = 14.5631;
    float number_converted = std::string_to_float(string);

    ASSERT_FLOAT_EQ ( number_correct , number_converted );

}

TEST ( string_minus_145_643 , converts_to_float_minus_145_643 )
{

    std::string string = "-145.643";
    float number_correct = -145.643;
    float number_converted = std::string_to_float(string);

    ASSERT_FLOAT_EQ ( number_correct , number_converted );

}

TEST ( integer_1052 , converts_to_string_1052 )
{

    int number = 1052;
    std::string string_correct = "1052";
    std::string string_actual = std::number_to_string(number);

    ASSERT_EQ ( string_correct , string_actual );

}

TEST ( float_1052_655 , converts_to_string_1052_66 )
{

    float number = 1052.655;
    std::string string_correct = "1052.66";
    std::string string_actual = std::number_to_string(number);

    ASSERT_EQ ( string_correct , string_actual );

}

TEST ( string_1000010001001 , splits_to_0000_000_00_by_delimiter_1 )
{

    char delimiter = '1';
    std::string string = "1000010001001";
    std::strings strings = std::string_split(string,delimiter);

    ASSERT_EQ ( strings.size() , 3u );
    ASSERT_EQ ( strings[0] , "0000" );
    ASSERT_EQ ( strings[1] , "000" );
    ASSERT_EQ ( strings[2] , "00" );

}

TEST ( string_0100001000100100 , splits_to_0_0000_000_00_00_by_delimiter_1 )
{

    char delimiter = '1';
    std::string string = "0100001000100100";
    std::strings strings = std::string_split(string,delimiter);

    ASSERT_EQ ( strings.size() , 5u );
    ASSERT_EQ ( strings[0] , "0" );
    ASSERT_EQ ( strings[1] , "0000" );
    ASSERT_EQ ( strings[2] , "000" );
    ASSERT_EQ ( strings[3] , "00" );
    ASSERT_EQ ( strings[4] , "00" );

}

TEST ( string_01_100001_10001_1001_100 , splits_to_0_0000_000_00_00_by_delimiter_1_1 )
{

    std::string delimiter = "1_1";
    std::string string = "01_100001_10001_1001_100";
    std::strings strings = std::string_split(string,delimiter);

    ASSERT_EQ ( strings.size() , 5u );
    ASSERT_EQ ( strings[0] , "0" );
    ASSERT_EQ ( strings[1] , "0000" );
    ASSERT_EQ ( strings[2] , "000" );
    ASSERT_EQ ( strings[3] , "00" );
    ASSERT_EQ ( strings[4] , "00" );

}

TEST ( string_UaaaUaaUUa , splits_to_aaa_aa_a_by_delimiter_U )
{

    char delimiter = 'U';
    std::string string = "UaaaUaaUUa";
    std::strings strings = std::string_split(string,delimiter);

    ASSERT_EQ ( strings.size() , 3u );
    ASSERT_EQ ( strings[0] , "aaa" );
    ASSERT_EQ ( strings[1] , "aa" );
    ASSERT_EQ ( strings[2] , "a" );

}

TEST ( string_FOOBAR , splits_to_F_O_O_B_A_R_by_empty_delimiter)
{

    std::string delimiter = "";
    std::string string = "FOOBAR";
    std::strings strings = std::string_split(string,delimiter);

    ASSERT_EQ ( strings.size() , 6u );
    ASSERT_EQ ( strings[0] , "F" );
    ASSERT_EQ ( strings[1] , "O" );
    ASSERT_EQ ( strings[2] , "O" );
    ASSERT_EQ ( strings[3] , "B" );
    ASSERT_EQ ( strings[4] , "A" );
    ASSERT_EQ ( strings[5] , "R" );

}

TEST ( string_0101010100100001010 , transforms_into_5151515155155551515_after_replacing_0_with_5 )
{

    char search_for = '0';
    char replace_with = '5';
    std::string string = "0101010100100001010";
    std::string string_transformed_correct = "5151515155155551515";
    std::string string_transformed_actual = std::string_replace(string,search_for,replace_with);

    ASSERT_EQ ( string_transformed_correct , string_transformed_actual );

}

TEST ( string_qwertyuiop , transforms_into_poiuytrewq_after_reversing )
{


    std::string string = "qwertyuiop";
    std::string string_reversed_correct = "poiuytrewq";
    std::string string_reversed_actual = std::string_reverse(string);

    ASSERT_EQ ( string_reversed_correct , string_reversed_actual );

}

int main ( int argc , char** argv )
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
