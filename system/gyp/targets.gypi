{
    'conditions' :
    [
        [
            'UNIT_NEEDS_COMPILING == "true"',
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
                        'dependencies':
                        [
                            '<@(UNIT_DEPENDENCIES)',
                        ],
                    },
                ],
            },
        ],
        [
            'UNIT_NEEDS_TESTING == "true"',
            {
                'targets':
                [
                    {
                        'target_name': '<(UNIT_TESTS_TARGET)',
                        'type': 'executable',
                        'sources':
                        [
                            '<@(UNIT_SOURCES)',
                            '<(UNIT_TESTS_SOURCE_FILE)',
                            '<(GTEST_OBJECT_FILE)',
                        ],
                        'dependencies':
                        [
                            '<@(UNIT_DEPENDENCIES)',
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
            },
        ],
    ],
}