#!/usr/bin/env python3

import sys, warnings

if sys.version_info.major < 3:
	# I wonder... why are we issuing a warning. If version 3.0 or greater is 
	# required to run the program, shouldn't we stop the program here?
	warnings.warn('Python version 3.0 or greater is needed for this program', RuntimeWarning)
else:
	print('Python version is 3.0 or greater')

print('--------------')