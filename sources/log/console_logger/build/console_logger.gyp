{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'console_logger',
        'UNIT_NEEDS_COMPILING': 'true',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/console_logger.hpp',
            './../sources/console_logger.cpp',
        ],
        'UNIT_DEPENDENCIES':
        [
            './../../abstract_logger/build/abstract_logger.gyp:abstract_logger',
            './../../../io/scout/build/scout.gyp:scout',
        ],
    },
}