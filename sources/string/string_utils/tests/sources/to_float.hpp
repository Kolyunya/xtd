TEST ( to_float , effectively_converts_14_dot_5631 )
{
    std::string source_string = "14.5631";
    float result_number_correct = 14.5631;
    float result_number_actual = xtd::string::to_float(source_string);
    ASSERT_FLOAT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_float , effectively_converts_minus_145_dot_643 )
{
    std::string source_string = "-145.643";
    float result_number_correct = -145.643;
    float result_number_actual = xtd::string::to_float(source_string);
    ASSERT_FLOAT_EQ ( result_number_correct , result_number_actual );
}