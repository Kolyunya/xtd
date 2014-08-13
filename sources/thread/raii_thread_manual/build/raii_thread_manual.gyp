{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'raii_thread_manual',
        'UNIT_IS_HEADER_ONLY': 'false',
        'UNIT_SOURCES':
        [
            './../sources/raii_thread_manual.hpp',
            './../sources/raii_thread_manual.cpp',
        ],
    },
}