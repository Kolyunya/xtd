{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'memory_utils',
        'UNIT_NEEDS_COMPILING': 'false',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/memory_utils.hpp',
            './../sources/memory_utils.tpp',
        ],
    },
}