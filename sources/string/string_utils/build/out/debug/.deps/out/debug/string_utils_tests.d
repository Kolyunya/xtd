cmd_out/debug/string_utils_tests := flock out/debug/linker.lock g++ -lpthread  -o out/debug/string_utils_tests -Wl,--start-group out/debug/obj.target/string_utils_tests/../sources/string_utils.o out/debug/obj.target/string_utils_tests/../tests/sources/string_utils.o /home/kolyunya/projects/gtest/build/gtest-all.o out/debug/obj.target/libstring_utils.a -Wl,--end-group 
