#!/usr/bin/env python3
import sys

print('The command line arguments are:')
for i in sys.argv:
	print(i)

print('\nThe PYTHONPATH is', sys.path,'\n')

#------------------------------------------#

import os
#Get Current Working Directory
print(os.getcwd())

#------------------------------------------#

from math import sqrt
print("The square root of 25 is", sqrt(25))

#------------------------------------------#

