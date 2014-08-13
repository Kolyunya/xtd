{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'raii_thread_manual',
        'UNIT_NEEDS_COMPILING': 'true',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/raii_thread_manual.hpp',
            './../sources/raii_thread_manual.cpp',
        ],
        'UNIT_DEPENDENCIES':
        [
            './../../raii_thread_base/build/raii_thread_base.gyp:raii_thread_base',
        ],
    },
}