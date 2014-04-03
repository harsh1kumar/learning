#!/usr/bin/env

shopList = ['apple', 'mango', 'banana', 'carrot']

# mylist1 is a reference to shopList
mylist1 = shopList

#mylist2 is a copy of shopList
mylist2 = shopList[:]

del shopList[0]
print('Deleted shopList[0]')
print(shopList)
print(mylist1)
print(mylist2)
print()

del mylist1[0]
print('Deleted mylist1[0]')
print(shopList)
print(mylist1)
print(mylist2)
print()

del mylist2[0]
print('Deleted mylist2[0]')
print(shopList)
print(mylist1)
print(mylist2)
print()

