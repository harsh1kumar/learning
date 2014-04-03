#!/usr/bin/env python3

#
# Palindrome version 2
#	Ignores case, space & special characters
#

def reverse(text):
	return text[::-1]

def is_palindrome(text):
	return (text == reverse(text))

text = input('Enter some text:')

# Clean text will store the 'text' in lower case without any spaces or special characters
clean_text = ''
for char in text:
	if char.isalnum():
		clean_text += char

# Making lower case
clean_text = clean_text.casefold()

if is_palindrome(clean_text):
	print('\tIs a palindrome\n')
else:
	print('\tNot a palindrome\n')
 
