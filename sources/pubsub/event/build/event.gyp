{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'event',
        'UNIT_IS_HEADER_ONLY': 'true',
        'UNIT_SOURCES':
        [
            './../sources/event.hpp',
            './../sources/event.tpp',
        ],
    },
}