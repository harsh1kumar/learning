#!/usr/bin/env python3

#
# Palindrome version 1
#	Considers case, space & special characters
#

def reverse(text):
	return text[::-1]

def is_palindrome(text):
	return (text == reverse(text))

text = input('Enter some text:')
if is_palindrome(text):
	print('\tIs a palindrome\n')
else:
	print('\tNot a palindrome\n')
