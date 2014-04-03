#!/usr/bin/env python3

class Robot:
	'''Represents a robot with a name.'''
	
	population = 0
	
	def __init__(self, name):
		'''Creates a robot with a name'''
		self.name = name
		print('Created', self.name)
		Robot.population += 1
	
	def __del__(self):
		'''Destroys a robot'''
		Robot.population -= 1
		print('Destroyed', self.name)
		if Robot.population == 0:
			print('All robots have been destroyed.')
		else:
			print('{} robots are left'.format(Robot.population))
	
	def sayHi(self):
		'''Greetings from the robot'''
		print('Hello, I am', self.name)
	
	def howMany():
		'''Prints the number of robots'''
		print('Number of robots is', Robot.population)
	howMany = staticmethod(howMany)


print(Robot.__doc__)
print(Robot.__init__.__doc__)
print(Robot.howMany.__doc__)
print()

droid1 = Robot('R2-D2')
droid1.sayHi()
Robot.howMany()

droid2 = Robot('Wall-E')
droid2.sayHi()
Robot.howMany()

print()

del droid1
del droid2
Robot.howMany()

