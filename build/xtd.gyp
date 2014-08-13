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
            'dependencies':
            [
                './../sources/chrono/chrono_utils/build/chrono_utils.gyp:chrono_utils',
                './../sources/file/file_utils/build/file_utils.gyp:file_utils',
                './../sources/io/scout/build/scout.gyp:scout',
                './../sources/memory/memory_utils/build/memory_utils.gyp:memory_utils',
                './../sources/pubsub/event/build/event.gyp:event',
                './../sources/random/random_utils/build/random_utils.gyp:random_utils',
                './../sources/string/string_utils/build/string_utils.gyp:string_utils',
            ],
        },
    ],
}