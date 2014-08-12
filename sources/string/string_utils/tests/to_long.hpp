TEST ( to_long , effectively_converts_123_dec_000 )
{
    std::string source_string = "123";
    signed long int result_number_correct = 123;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_123_dec_001 )
{
    std::string source_string = "123";
    signed long int result_number_correct = 123;
    signed long int result_number_actual = xtd::str::to_long(source_string,10);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_567_oct_000 )
{
    std::string source_string = "0567";
    signed long int result_number_correct = 0567;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_567_oct_001 )
{
    std::string source_string = "0567";
    signed long int result_number_correct = 0567;
    signed long int result_number_actual = xtd::str::to_long(source_string,8);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_abc_hex_000 )
{
    std::string source_string = "0xABC";
    signed long int result_number_correct = 0xABC;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_abc_hex_001 )
{
    std::string source_string = "0xABC";
    signed long int result_number_correct = 0xABC;
    signed long int result_number_actual = xtd::str::to_long(source_string,16);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_minus_abc_hex_000 )
{
    std::string source_string = "-0xABC";
    signed long int result_number_correct = -0xABC;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_minus_abc_hex_001 )
{
    std::string source_string = "-0xABC";
    signed long int result_number_correct = -0xABC;
    signed long int result_number_actual = xtd::str::to_long(source_string,16);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_minus_111_bin )
{
    std::string source_string = "-111";
    signed long int result_number_correct = -7;
    signed long int result_number_actual = xtd::str::to_long(source_string,2);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_0 )
{
    std::string source_string = "0";
    signed long int result_number_correct = 0;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_0abc )
{
    std::string source_string = "0ABC";
    signed long int result_number_correct = 0;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , effectively_converts_123_with_three_leading_spaces )
{
    std::string source_string = "   123";
    signed long int result_number_correct = 123;
    signed long int result_number_actual = xtd::str::to_long(source_string);
    ASSERT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_long , fails_to_parse_a_string_containing_only_spaces )
{
    std::string source_string = "     ";
    ASSERT_THROW ( xtd::str::to_long(source_string) , std::runtime_error );
}

TEST ( to_long , fails_to_parse_abc )
{
    std::string source_string = "ABC";
    ASSERT_THROW ( xtd::str::to_long(source_string) , std::runtime_error );
}

TEST ( to_long , fails_to_parse_abc123 )
{
    std::string source_string = "ABC123";
    ASSERT_THROW ( xtd::str::to_long(source_string) , std::runtime_error );
}
