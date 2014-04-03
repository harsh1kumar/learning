#!/usr/bin/env python3

class ShortInputExpection(Exception):
	def __init__(self, length, atleast):
		Exception.__init__(self)
		self.length = length
		self.atleast = atleast

min_len = 5

try:
	text = input('Enter text with atleast {} characters: '.format(min_len))
	if len(text) < min_len:
		raise ShortInputExpection(len(text), min_len)
except EOFError:
	print('\nERROR: Don\'t enter EOF. Please enter proper text')
except ShortInputExpection as ex:
	print('ERROR: You entered a text of length {0}. You needed to enter atleast {1} characters'.format(ex.length, ex.atleast))
except:
	print('\nERROR: There was some problem with your input')
else:
	print('Congos!! You are smart enough to follow simple instructions.')
