#!/usr/bin/env python3

ab = {
	'Harsh'		:	'harsh@mail.com',
	'Tuts'		:	'tuts@mail.com',
	'Spammer'	:	'spammy@mail.com'
	}

print('Number of addresses in the address book =', len(ab))

del ab['Spammer']

for name, address in ab.items():
	print('Contact {} at {}'.format(name, address))

ab['Yoos'] = 'yoos@mail.com'

if 'Yoos' in ab:
	print('Yoos can be contacted at', ab['Yoos'])
