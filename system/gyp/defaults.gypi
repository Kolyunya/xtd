{
    'target_defaults':
    {
        'cflags':
        [
            '<@(CFLAGS_STANDARD)',
        ],
        'include_dirs':
        [
            '<(LIBRARY_INCLUDE_DIR)',
        ],
        'configurations':
        {
            'release':
            {
                'cflags':
                [
                    '<@(CFLAGS_RELEASE)',
                ],
            },
            'debug':
            {
                'cflags':
                [
                    '<@(CFLAGS_DEBUG)',
                ],
            },
        },
    },
}