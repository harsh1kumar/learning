#!/usr/bin/env python3
def total(initial=5, *numbers, ase=1, **keywords):
	count = initial
	for no in numbers:
		count += no
	for key in keywords:
		count += keywords[key]
	return count-ase

print(total(10,1,2,3, veg = 50, noveg=100))

def total2(initial=5, *, ase, **keywords):
	'''Returns total of values after subtracting ase from it.
	
	Initial has default value
	ase is a keyword-only argument'''
	count = initial
	for key in keywords:
		count += keywords[key]
	return count-ase

print(total2(10, ase = 12, veg = 50, noveg=100))

#Function with no return value
def somefunc():
	pass

print(somefunc())
print()
print(total2.__doc__)
help(total2)


