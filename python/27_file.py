#!/usr/bin/env python3

text = '''Hello, this is a bunch of text.
It is a multi-line text.
This text has no meaning at all.
The text is only for testing purpose
'''

# Writing
f = open('testing_file.txt', 'w')
f.write(text)
f.close()

# Reading one line at a time
f = open('testing_file.txt')
while True:
	line = f.readline()
	if len(line) == 0:
		break;
	print(line, end='')
f.close()

print()

# Reading complete file at one go
f = open('testing_file.txt')
print(f.read())
f.close()
