{
    'variables':
    {
        'UNIT_ROOT_DIR': './..',
        'UNIT_STANDARD': 'c++11',
        'UNIT_SOURCES_DIR': '<(UNIT_ROOT_DIR)/sources',
        'UNIT_SOURCE_FILE': '<(UNIT_SOURCES_DIR)/<(UNIT_NAME).cpp',
        'UNIT_TESTS_DIR': '<(UNIT_ROOT_DIR)/tests',
        'UNIT_TESTS_SOURCE_FILE': '<(UNIT_TESTS_DIR)/<(UNIT_NAME).cpp',
        'UNIT_TESTS_TARGET': '<(UNIT_NAME)_tests',
        'GTEST_OBJECT_FILE': '$(GTEST_HOME)/build/gtest-all.o',
        'GTEST_INCLUDE_DIR': '$(GTEST_HOME)/include',
        'LIBRARY_INCLUDE_DIR': '$(XTD_HOME)/include',
        'LIBRARY_LINKAGE': 'static',
        'LIBRARY_TYPE': '<(LIBRARY_LINKAGE)_library',
        'CFLAGS_STANDARD':
        [
            '-std=<(UNIT_STANDARD)',
            '-Wall',
            '-Wextra',
            '-Werror',
            '-pedantic',
            '-pedantic-errors',
        ],
        'CFLAGS_DEBUG':
        [
            '-O0',
            '-g',
        ],
        'CFLAGS_RELEASE':
        [
            '-O3',
            '-s',
        ],
    },
}