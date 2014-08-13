{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'abstract_logger',
        'UNIT_NEEDS_COMPILING': 'true',
        'UNIT_NEEDS_TESTING': 'false',
        'UNIT_SOURCES':
        [
            './../sources/abstract_logger.hpp',
            './../sources/abstract_logger.cpp',
        ],
        'UNIT_DEPENDENCIES':
        [
            './../../../chrono/chrono_utils/build/chrono_utils.gyp:chrono_utils',
        ],
    },
}