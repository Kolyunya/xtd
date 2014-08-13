{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'file_logger',
        'UNIT_NEEDS_COMPILING': 'true',
        'UNIT_NEEDS_TESTING': 'true',
        'UNIT_SOURCES':
        [
            './../sources/file_logger.hpp',
            './../sources/file_logger.cpp',
        ],
        'UNIT_DEPENDENCIES':
        [
            './../../abstract_logger/build/abstract_logger.gyp:abstract_logger',
            './../../../file/file_utils/build/file_utils.gyp:file_utils',
            './../../../io/scout/build/scout.gyp:scout',
        ],
    },
}