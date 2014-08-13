{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'file_logger',
        'UNIT_DEPENDENCIES':
        [
            './../../abstract_logger/build/abstract_logger.gyp:abstract_logger',
            './../../../chrono/chrono_utils/build/chrono_utils.gyp:chrono_utils',
            './../../../file/file_utils/build/file_utils.gyp:file_utils',
            './../../../io/scout/build/scout.gyp:scout',
        ]
    },
}