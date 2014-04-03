#!/usr/bin/env python3

import time

try:
	f = open('testing_file.txt', 'r')
	while True:
		line = f.readline()
		if len(line) == 0:
			break;
		print(line, end='')
		time.sleep(2)

except KeyboardInterrupt:
	print('\n(ERROR: You interrupted the file read operation.)')
finally:
	f.close()
	print('\n(Closed the file)')
