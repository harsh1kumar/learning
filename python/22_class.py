#!/usr/bin/env python3

class Person1:
	pass

p1 = Person1()
print(p1)



class Person2:
	def sayHi(self):
		print("Hello")

p2 = Person2()
p2.sayHi()

class Person3:
	def __init__(self, name):
		self.name = name
	def sayHi(self):
		print('Hello Mr.{} !!'.format(self.name))

p3 = Person3('Harsh')
p3.sayHi()
