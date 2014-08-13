{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'raii_thread_base',
        'UNIT_NEEDS_COMPILING': 'true',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/raii_thread_base.hpp',
            './../sources/raii_thread_base.cpp',
        ],
    },
}