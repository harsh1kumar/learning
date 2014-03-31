#!/usr/bin/env python3
number = 23
guess = int(input('Enter an integer: '))
if guess == number:
	print('Yeah!! Right Guess')
	print('(But no prizes :P)')
elif guess < number:
	print('Sorry, Go higher')
else:
	print('Sorry, Go lower')
print("Done")

while guess != number:
	print('Try again\n')
	guess = int(input('Enter an integer: '))
else:
	print('You got it!! Congos!!\n\n')
