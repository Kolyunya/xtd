{
    'includes'  :   [
                        './../../../../system/gyp/includes/includes.gypi',
                    ],
    'variables' :   {
                        'UNIT_NAME'     :   'file_util',
                        'UNIT_TYPE'     :   'header_only',
                        'UNIT_SOURCES'  :   [
                                                '<(UNIT_SOURCES_DIR)/<(UNIT_NAME).hpp',
                                                '<(UNIT_SOURCES_DIR)/<(UNIT_NAME).ipp',
                                                '<(UNIT_SOURCES_DIR)/<(UNIT_NAME).tpp',
                                            ],
                    },
}