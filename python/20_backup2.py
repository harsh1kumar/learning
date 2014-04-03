#!/usr/bin/env python3

#
# Version 2 of backup:
#	Verbose mode can be specified using -v
#	Additional sources can be specified on the command line
#

import os
import time
import sys

def verbose_print(text):
	if verbose:
		print(text)

# Check if verbose
if '-v' in sys.argv:
	verbose = True
else:
	verbose = False

# Create backup dir if not already present
backup_dir = '/home/harsh/backup_py'
if not os.path.exists(backup_dir):
	os.mkdir(backup_dir)
	verbose_print('Backup Directory created:' + backup_dir)
else:
	verbose_print('Backup Directory exists.')

# Directory/File paths to zip
source = ['/home/harsh/Programming/learning_github/python', '/home/harsh/Programming/learning_github/git_basics']

# Adding sources from command line, if available
for i in range(1, len(sys.argv)):
	if sys.argv[i] != '-v':
		source.append(sys.argv[i])
		verbose_print("Added a source from command line:" + sys.argv[i])

# Output Directory
output_dir = backup_dir + os.sep + time.strftime('%Y-%m-%d')
if not os.path.exists(output_dir):
	os.mkdir(output_dir)
	verbose_print('Output Directory created:' + output_dir)
else:
	verbose_print('Output Directory exists.')

# Output file name
output = output_dir + os.sep + time.strftime('%H-%M-%S') + '.zip'

zip_command = 'zip -rq {0} {1}'.format(output, ' '.join(source))

verbose_print('\n' + zip_command)

if os.system(zip_command) == 0:
	print('\nSuccessful backup to {}\n'.format(output))
else:
	print('\nBackup Failed\n')

