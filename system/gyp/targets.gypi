{
    'targets':
    [
        {
            'target_name': '<(UNIT_NAME)',
            'type': '<(LIBRARY_TYPE)',
            'sources':
            [
                '<(UNIT_SOURCE_FILE)',
            ],
        },
        {
            'target_name': '<(UNIT_TESTS_TARGET)',
            'type': 'executable',
            'dependencies':
            [
                '<(UNIT_NAME)',
                '<@(UNIT_DEPENDENCIES)',
            ],
            'sources':
            [
                '<(UNIT_TESTS_SOURCE_FILE)',
                '<(GTEST_OBJECT_FILE)',
            ],
            'include_dirs':
            [
                '<(GTEST_INCLUDE_DIR)',
            ],
            'ldflags':
            [
                '-lpthread',
            ],
        },
    ],
}