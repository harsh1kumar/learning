#!/usr/bin/env python3

import sys, os

def wrong_usage():
	print('Usage: {0} from to --- file'.format(sys.argv[0]))
	exit()

min_args = 5
# Make sure that minimum number of arguments are present
if len(sys.argv) < min_args:
	wrong_usage()

# Make sure that one argument is ---
if '---' not in sys.argv:
	wrong_usage()

# Make sure triple dashes are at index 3 in the list
dashes_index = sys.argv.index('---')	# Index of triple dashes
if dashes_index != 3:
	wrong_usage()

# Make sure that files mentioned exist
fileList = sys.argv[dashes_index+1:]	# List of files got for command line
for filepath in fileList:
	if not os.path.isfile(filepath):
		print('File not found:', filepath)
		exit()

from_str = sys.argv[1]
to_str = sys.argv[2]

print('\nReplacing \'{0}\' with \'{1}\'\n'.format(from_str, to_str))
for filepath in fileList:
	f = open(filepath, 'r')
	text = f.read()
	f.close()
	
	text = text.replace(from_str, to_str)
	print('\t', filepath)
	
	f = open(filepath, 'w')
	f.write(text)
	f.close()



