#!/usr/bin/env python3

#
# Version 1 of backup
#

import os
import time

# Create backup dir if not already present
backup_dir = '/home/harsh/backup_py'
if not os.path.exists(backup_dir):
	os.mkdir(backup_dir)
	print('Backup Directory created:', backup_dir)

# Directory/File paths to zip
source = ['/home/harsh/Programming/learning_github/python', '/home/harsh/Programming/learning_github/git_basics']


# Output Directory
output_dir = backup_dir + os.sep + time.strftime('%Y-%m-%d')
if not os.path.exists(output_dir):
	os.mkdir(output_dir)
	print('Output Directory created:', output_dir)

# Output file name
output = output_dir + os.sep + time.strftime('%H-%M-%S') + '.zip'

zip_command = 'zip -rq {0} {1}'.format(output, ' '.join(source))

if os.system(zip_command) == 0:
	print('Successful backup to', output)
else:
	print('Backup Failed\n')

