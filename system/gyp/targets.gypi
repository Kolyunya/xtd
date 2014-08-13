{
    'conditions' :
    [
        [
            'UNIT_IS_HEADER_ONLY == "false"',
            {
                'targets':
                [
                    {
                        'target_name': '<(UNIT_NAME)',
                        'type': '<(LIBRARY_TYPE)',
                        'sources':
                        [
                            '<@(UNIT_SOURCES)',
                        ],
                    },
                ],
            },
        ],
    ],
    'targets':
    [
        {
            'target_name': '<(UNIT_TESTS_TARGET)',
            'type': 'executable',
            'conditions' :
            [
                [
                    'UNIT_IS_HEADER_ONLY == "false"',
                    {
                        'dependencies':
                        [
                            '<(UNIT_NAME)',
                        ],
                    },
                ],
            ],
            'dependencies':
            [
                '<@(UNIT_DEPENDENCIES)',
            ],
            'sources':
            [
                '<@(UNIT_SOURCES)',
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