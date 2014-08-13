{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'abstract_logger',
        'UNIT_DEPENDENCIES':
        [
            './../../../chrono/chrono_utils/build/chrono_utils.gyp:chrono_utils',
        ]
    },
}