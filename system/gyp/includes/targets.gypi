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
                                'ldflags'       :   [
                                                        '<(GTEST_OBJECT_FILE)',
                                                    ],
                                'sources'       :   [
                                                        '<(UNIT_TESTS_SOURCE_FILE)',
                                                    ],
                                'include_dirs'  :   [
                                                        '$(GTEST_HOME)/include/',
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
                            #{
                            #    'target_name'   :   'clean',
                            #    'type'          :   'none',
                            #    'actions'       :   [
                            #                            {
                            #                                'action_name'   :   'delete_build_artifacts',
                            #                                'inputs'        :   [
                            #                                                        'targets.gypi',
                            #                                                    ],
                            #                                'outputs'       :   [
                            #                                                        'phony',
                            #                                                    ],
                            #                                'action'        :   [
                            #                                                        'python',
                            #                                                        '<(SCRIPTS_DIR)/delete_build_artifacts.py',
                            #                                                        '<(UNIT_NAME).gyp',
                            #                                                    ],
                            #                                'message'       :   'Deleting build artifacts',
                            #                            },
                            #                        ],
                            #},
                        ],
}