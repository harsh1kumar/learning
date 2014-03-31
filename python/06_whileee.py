#!/usr/bin/env python3
number = 23
guess = int(input('Enter an integer: '))
while guess != number:
	if guess < number:
		print('Sorry, Go higher')
	else:
		print('Sorry, Go lower')
	print('Try again\n')
	guess = int(input('Enter an integer: '))
else:
	print('You got it!! Congos!!\n\n')
