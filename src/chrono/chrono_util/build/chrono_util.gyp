{
	'includes'			:	[
								'./../../../../system/gyp/includes/includes.gypi',
							],
	'variables'			:	{
								'UNIT_NAME'		:	'chrono_util',
								'UNIT_SOURCES'	:	[												
														'<(UNIT_SOURCES_DIR)/<(UNIT_NAME).hpp',
														'<(UNIT_SOURCES_DIR)/<(UNIT_NAME).ipp',
													],
							},
}