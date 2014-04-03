#!/usr/bin/env python3

try:
	text = input('Enter text: ')
except EOFError:
	print('\nWhy did you enter EOF?')
except KeyboardInterrupt:
	print('\nYou cancelled')
else:
	print('You entered:', text)
