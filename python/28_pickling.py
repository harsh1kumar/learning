#!/usr/bin/env python3

import pickle

shopListFile = 'shoplist.data'

shopList = ['apple', 'mango', 'banana', 'grape']

f = open(shopListFile, 'wb')
pickle.dump(shopList, f)
f.close()

del shopList

f = open(shopListFile, 'rb')
shopListRecovered = pickle.load(f)
f.close()

print(shopListRecovered)
