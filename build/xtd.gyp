{
    'includes':
    [
        './../system/gyp/variables.gypi',
        './../system/gyp/defaults.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'xtd',
    },
    'targets':
    [
        {
            'target_name': 'xtd',
            'type': 'static_library',
            'sources':
            [
                './../sources/chrono/chrono_utils/sources/chrono_utils.cpp',
                './../sources/file/file_utils/sources/file_utils.cpp',
                './../sources/io/scout/sources/scout.cpp',
                './../sources/memory/memory_utils/sources/memory_utils.cpp',
                './../sources/pubsub/event/sources/event.cpp',
                './../sources/random/random_utils/sources/random_utils.cpp',
                './../sources/string/string_utils/sources/string_utils.cpp',
            ],
        },
    ],
}