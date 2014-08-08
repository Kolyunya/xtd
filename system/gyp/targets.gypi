{
    'conditions'    :   [
                            [
                                'UNIT_TYPE == "static_library"',
                                {
                                    'targets'   :   [
                                                        {
                                                            'target_name'   :   'build',
                                                            'type'          :   'static_library',
                                                        },
                                                    ],
                                },
                            ],
                        ],
    'targets'       :   [
                            {
                                'target_name'   :   'tests',
                                'type'          :   'executable',
                                'sources'       :   [
                                                        '<(UNIT_TESTS_SOURCE_FILE)',
                                                        '<(GTEST_OBJECT_FILE)',
                                                    ],
                                'include_dirs'  :   [
                                                        '<(GTEST_INCLUDE_DIR)',
                                                    ],
                                'conditions'    :   [
                                                        [
                                                            'UNIT_TYPE == "static_library"',
                                                            {
                                                                'dependencies'  :   [
                                                                                        'build',
                                                                                    ],
                                                            },
                                                        ],
                                                        [
                                                            'OS == "linux"',
                                                            {
                                                                'ldflags'   :   [
                                                                                    '-lpthread',
                                                                                ],
                                                            },
                                                        ],
                                                    ],
                            },
                        ],
}