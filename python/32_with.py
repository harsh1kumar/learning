#!/usr/bin/env python3

with open('testing_file.txt', 'r') as f:
	for line in f:
		print(line, end='')
