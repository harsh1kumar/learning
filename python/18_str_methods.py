#!/usr/bin/env python

name = 'HarshKumar'

if name.startswith('H'):
	print('name starts with H')

if 'Kum' in name:
	print('\'Kum\' is present in name')

print('\'K\' is present at position', name.find('K'))

delimiter = "[_|_]"
mylist = ['apple', 'mango', 'carrot']
print(delimiter.join(mylist))
