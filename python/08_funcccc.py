#!/usr/bin/env python3
x = 50

def func():
	global x
	print('x is', x)
	x = 2
	print('Changed global x to', x)

func()
print('Value of x is', x)

# Default argument of times is 1
def say(message, times = 1):
	print(message * times)

say('Hello')
say('World', 5)


