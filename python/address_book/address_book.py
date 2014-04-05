
class Address_book(dict):
	'''Represents an address book. It is a dict(inherited)'''

	def __init__(self):
		dict.__init__(self)
		self.add_contact()

	def add_contact(self):
		'''Adds a contact by getting the information from the user'''
		print()
		name = input('Enter Name: ')
		email = input('Enter Email: ')
		address = input('Enter Address: ')
		phone = input('Enter Phone Number: ')
		self[name] = (email, address, phone)
	
	def del_contact(self):
		'''Deletes a contact'''
		print()
		name = input('Enter name of the contact you want to delete: ')
		del self[name]
	
	def print_contacts(self):
		'''Prints all the contact in the address book'''
		if len(self) > 0:
			print('-'*80)
			print('{0:15}{1:25}{2:15}{3:15}'.format('Name', 'Email', 'Address', 'Phone Number'))
			print('-'*80 + '\n')
			for key in self:
				print('{0:15}{1:25}{2:15}{3:15}'.format(key,
								self[key][0],
								self[key][1],
								self[key][2]))
			print('-'*80 + '\n')

