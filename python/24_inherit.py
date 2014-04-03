#!/usr/bin/env python3

class SchoolMember:
	'''Represents a member of the school'''
	
	def __init__(self, name, age):
		'''Initializes a SchoolMember'''
		self.name = name
		self.age = age
		print('Initialized SchoolMember', self.name)
	
	def details(self):
		'''Prints the details of the SchoolMember'''
		print('Name: {}, Age: {}'.format(self.name, self.age), end=', ')

class Teacher(SchoolMember):
	'''Represents a Teacher'''
	
	def __init__(self, name, age, salary):
		'''Initializes a Teacher'''
		SchoolMember.__init__(self, name, age)
		self.salary = salary
		print('Initialized Teacher', self.name)
	
	def details(self):
		'''Prints the details of the Teacher'''
		SchoolMember.details(self)
		print('Salary: {}'.format(self.salary))

class Student(SchoolMember):
	'''Represents a Student'''
	
	def __init__(self, name, age, fee):
		'''Initializes a Student'''
		SchoolMember.__init__(self, name, age)
		self.fee = fee
		print('Initialized Student', self.name)
	
	def details(self):
		'''Prints the details of the Student'''
		SchoolMember.details(self)
		print('Fee: {}'.format(self.fee))


t = Teacher('Lata', 45, 350)
s = Student('Harsh', 14, 40)

t.details()
s.details()

print()

members = [t, s]
for member in members:
	member.details()

