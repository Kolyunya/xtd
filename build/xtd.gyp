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
                './../sources/file/file_utils/build/file_utils.gyp:file_utils',
                './../sources/memory/memory_utils/build/memory_utils.gyp:memory_utils',
                './../sources/string/string_utils/build/string_utils.gyp:string_utils',
            ],
        },
    ],
}