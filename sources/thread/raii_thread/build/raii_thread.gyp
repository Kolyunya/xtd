{
    'includes':
    [
        './../../../../system/gyp/includes.gypi',
    ],
    'variables':
    {
        'UNIT_NAME': 'raii_thread',
        'UNIT_DEPENDENCIES':
        [
            './../../raii_thread_base/build/raii_thread_base.gyp:raii_thread_base',
        ],
    },
}