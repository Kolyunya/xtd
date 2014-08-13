{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'scout',
        'UNIT_IS_HEADER_ONLY': 'false',
        'UNIT_SOURCES':
        [
            './../sources/scout.hpp',
            './../sources/scout.tpp',
            './../sources/scout.cpp',
        ],
    },
}