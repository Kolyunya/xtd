{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'memory_utils',
        'UNIT_IS_HEADER_ONLY': 'true',
        'UNIT_SOURCES':
        [
            './../sources/memory_utils.hpp',
            './../sources/memory_utils.tpp',
        ],
    },
}