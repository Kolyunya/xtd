{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'event',
        'UNIT_NEEDS_COMPILING': 'false',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/event.hpp',
            './../sources/event.tpp',
        ],
    },
}