import shutil
import os

# Script deletes GYP build artifacts.

# "generator.gyp", ".gitignore" and "README" files should not be deleted
files_ignore = ['generator.gyp','.gitignore','README']

# Get a list of all files in current directory
files_all = os.listdir('./')

# Iterate over all files
for file_current in files_all :

	# All directories should be deleted
	if os.path.isdir(file_current) :
		continue
		
	# By default a file should be deleted
	file_delete = 1
	
	# Iterate over ignored files
	for file_ignore in files_ignore :
	
		# If a file should not be deleted
		if file_current == file_ignore :
		
			# Drop the delete flag
			file_delete = 0
			break
	
	# Delete the file if needed
	if file_delete == 1 :
		os.remove(file_current)