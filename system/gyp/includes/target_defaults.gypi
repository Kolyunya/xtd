{
    'target_defaults'   :   {
                                'cflags'            :   [
                                                            '<@(CFLAGS_STANDARD)',
                                                        ],
                                'include_dirs'      :   [
                                                            '$(STD_HOME)/include',
                                                            '$(UNET_HOME)/include',
                                                        ],
                                'sources'           :   [
                                                            '<@(UNIT_SOURCES)',
                                                        ],
                                'configurations'    :   {
                                                            'debug'     :   {
                                                                                'cflags'    :   [
                                                                                                    '<@(CFLAGS_DEBUG)',
                                                                                                ],
                                                                            },
                                                            'release'   :   {
                                                                                'cflags'    :   [
                                                                                                    '<@(CFLAGS_RELEASE)',
                                                                                                ],
                                                                            },
                                                        },
                            },
}