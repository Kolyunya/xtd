TEST ( to_double , effectively_converts_14_dot_5631 )
{
    std::string source_string = "14.5631";
    double result_number_correct = 14.5631;
    double result_number_actual = xtd::str::to_double(source_string);
    ASSERT_FLOAT_EQ ( result_number_correct , result_number_actual );
}

TEST ( to_double , effectively_converts_minus_145_dot_643 )
{
    std::string source_string = "-145.643";
    double result_number_correct = -145.643;
    double result_number_actual = xtd::str::to_double(source_string);
    ASSERT_FLOAT_EQ ( result_number_correct , result_number_actual );
}