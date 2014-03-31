#!/usr/bin/env python3

shopList = ['apple','mango', 'carrot', 'banana']

print('Shopping List has', len(shopList), 'items.')

print('These items are:', end=' ')
for item in shopList:
	print(item, end=' ')
print()

shopList.append('rice')
print('Added rice to the list, now total items are', len(shopList))

shopList.sort()
print('Sorted list is: ', shopList)

oldItem = shopList[0]
del shopList[0]
print('Purchased {0}. Now, the list is : {1}'.format(oldItem, shopList))
