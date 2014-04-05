#!/usr/bin/env python3

#
# A simple command line address boook that stores:
#	Name, Email, Address, Phone Number
# Allows you to store the address book in a file & load it later
#

import address_book
import os, platform
import pickle


def clear_screen():
	if platform.platform().startswith('Window'):
		os.system('cls')
	else:
		os.system('clear')

def welcome_screen():
	'''Prints the welcome screen & returns the option number that the user inputs'''
	clear_screen()
	print('{0:^25}\n'.format('Address Book') + '*'*25 + '\n')
	print('1. Load Address Book')
	print('2. New Address Book')
	print('3. Exit')
	while True:
		try:
			option = int(input('\n\tSelect an option: '))
		except:
			print('\tWrong input, try again.')
		else:
			if option not in range(1,4):
				print('\tWrong input, try again.')
			else:
				return option

def main_screen(status_str):
	'''Prints the main screen & returns the option number that the user inputs'''
	menu = ['Load Address Book',
		'New Address Book',
		'Save Address Book',
		'Add a contact',
		'Delete a contact',
		'Exit']
	global contacts
	
	clear_screen()
	print('{0:^80}\n{1:^80}'.format('Address Book', '*'*14) + '\n')
	contacts.print_contacts()
	
	len_status = len(status_str)
	if len_status > 0:
		print('-'*(len_status+4))
		print('\ ' + status_str + ' /')
		print(' ' + '-'*(len_status+2) + '\n')
	
	for i in range(0, len(menu)):
		print('{0}. {1}'.format(i+1, menu[i]))
	print()
	
	while True:
		try:
			option = int(input('\n\tSelect an option: '))
		except:
			print('\tWrong input, try again.')
		else:
			if option not in range(1, len(menu)+1):
				print('\tWrong input, try again.')
			else:
				return option



data_file = 'address_book.data'		# Name of the file where address book is stored
unsaved = False		# True if there are unsaved changes in the address book
status_str = ''		# The status message which is printed when the menu is reprinted


# Display the Welcome Screen & get the user input
option = welcome_screen()
if option == 1:
	with open(data_file, 'rb') as f:
		contacts = pickle.load(f)
	status_str = 'Loaded Address Book'

elif option == 2:
	print('\nCreating a new Address Book')
	contacts = address_book.Address_book()
	unsaved = True
	status_str = 'Created New Address Book'

elif option == 3:
	exit()


# Loop prints the main screen to get user input & do the needful
while True:
	option = main_screen(status_str)
	if option == 1:
		# Load Address Book
		if unsaved:
			sure = input('\There are unsaved changes which will be lost. Press \'y\' to continue. ')
			if sure != 'y':
				status_str = 'Action aborted'
				continue
		
		with open(data_file, 'rb') as f:
			contacts = pickle.load(f)
		unsaved = False
		status_str = 'Loaded Address Book'

	elif option == 2:
		# New Address Book
		if unsaved:
			sure = input('\There are unsaved changes which will be lost. Press \'y\' to continue. ')
			if sure != 'y':
				status_str = 'Action aborted'
				continue
		
		contacts = address_book.Address_book()
		unsaved = True
		status_str = 'Created New Address Book'

	elif option == 3:
		# Save Address Book
		with open(data_file, 'wb') as f:
			pickle.dump(contacts, f)
		status_str = 'Saved Address Book'

	elif option == 4:
		# Add Contact
		contacts.add_contact()
		unsaved = True
		status_str = 'Added a new contact'

	elif option == 5:
		# Delete Contact
		contacts.del_contact()
		unsaved = True
		status_str = 'Deleted a contact'

	elif option == 6:
		# Exit
		if unsaved:
			sure = input('\n\tThre are unsaved changes.\n\tPress \'s\' to save & exit (OR) any key to exit without saving: ')
			if sure == 's':
				with open(data_file, 'wb') as f:
					pickle.dump(contacts, f)
				print('\nSaved Address Book\n')
		break

