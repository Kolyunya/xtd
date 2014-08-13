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
                './../sources/log/abstract_logger/sources/abstract_logger.cpp',
                './../sources/log/console_logger/sources/console_logger.cpp',
                './../sources/log/file_logger/sources/file_logger.cpp',
                './../sources/random/random_utils/sources/random_utils.cpp',
                './../sources/string/string_utils/sources/string_utils.cpp',
                './../sources/thread/raii_thread_base/sources/raii_thread_base.cpp',
                './../sources/thread/raii_thread/sources/raii_thread.cpp',
                './../sources/thread/raii_thread_manual/sources/raii_thread_manual.cpp',
            ],
        },
    ],
}