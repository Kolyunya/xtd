{
    'variables'     :    {
                            'variables'                 :   {
                                                                'conditions'    :   [
                                                                                        [
                                                                                            'OS == "win"',
                                                                                            {
                                                                                                'CONDITIONAL_UNIT_STANDARD'     :      'gnu++11',
                                                                                            },
                                                                                            {
                                                                                                'CONDITIONAL_UNIT_STANDARD'     :       'c++11',
                                                                                            },
                                                                                        ],
                                                                                    ],
                                                            },
                            'UNIT_ROOT_DIR'             :   './..',
                            'UNIT_STANDARD'             :   '<(CONDITIONAL_UNIT_STANDARD)',
                            'UNIT_SOURCES_DIR'          :   '<(UNIT_ROOT_DIR)/src',
                            'UNIT_TESTS_DIR'            :   '<(UNIT_ROOT_DIR)/tests',
                            'UNIT_TESTS_SOURCES_DIR'    :   '<(UNIT_TESTS_DIR)/src',
                            'UNIT_TESTS_DATA_DIR'       :   '<(UNIT_TESTS_DIR)/data',
                            'UNIT_TESTS_SOURCE_FILE'    :   '<(UNIT_TESTS_SOURCES_DIR)/<(UNIT_NAME)_tests.cpp',
                            'GTEST_OBJECT_FILE'         :   '$(GTEST_HOME)/build/gtest-all.o',
                            'SCRIPTS_DIR'               :   '$(STD_HOME)/system/gyp/scripts',
                            'CFLAGS_STANDARD'           :   [
                                                                '-std=<(UNIT_STANDARD)',    # Use c++11 standard
                                                                '-Wall',                    # Turns on all optional warnings which are desirable for normal code.
                                                                '-Wextra',                  # This enables some extra warning flags that are not enabled by -Wall
                                                                '-Werror',                  # Make all warnings into hard errors. Source code which triggers warnings will be rejected.
                                                                '-pedantic',                # Issue all the mandatory diagnostics listed in the C standard. Some of them are left out by default, since they trigger frequently on harmless code.
                                                                '-pedantic-errors',         # Issue all the mandatory diagnostics, and make all mandatory diagnostics into errors. This includes mandatory diagnostics that GCC issues without -pedantic but treats as warnings.
                                                                '-Wno-unused-function',     # Allow unused functions.
                                                            ],
                            'CFLAGS_DEBUG'              :   [
                                                                '-O0',                      # Reduce compilation time and make debugging produce the expected results. This is the default.
                                                                '-g',                       # Produce debugging information in the operating system's native format
                                                            ],
                            'CFLAGS_RELEASE'            :   [
                                                                '-O3',                      # Enable high level of optimisation
                                                                '-s',                       # Remove all symbol table and relocation information from the executable.
                                                            ],
                        },
}