#!/usr/bin/env python3

shopList = ['apple', 'mango', 'carrot', 'banana']
name = 'Harsh'

print('Item 0 =', shopList[0])
print('Item 1 =', shopList[1])
print('Item 2 =', shopList[2])
print('Item 3 =', shopList[3])

print()

print('Item -1 =', shopList[-1])
print('Item -2 =', shopList[-2])
print('Item -3 =', shopList[-3])
print('Item -4 =', shopList[-4])
print('2nd character =', name[2])

print()

#Slicing a list
print('Item 1 to 3', shopList[1:3])
print('Item 1 to last', shopList[1:])
print('Item first to last', shopList[:])
print('Item 1 to -1', shopList[1:-1])

print()

#Slicing a string
print('Character 1 to 3', name[1:3])
print('Character 2 to last', name[2:])
print('Character first to last', name[:])
print('Character 1 to -1', name[1:-1])

