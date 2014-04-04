#!/usr/bin/env python3

class Person:
	def __init__(self):
		self.data = 10

	def __str__(self):
		return '|*********{0}*********|'.format(self.data)

	def __getitem__(self, key):
		return self.data + key
	
	def __len__(self):
		return self.data*4

p = Person()
print(p)
print(p[5])
print(len(p))
