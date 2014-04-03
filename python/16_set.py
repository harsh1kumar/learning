#!/usr/bin/env python3

bri = set(['Brazil', 'Russia', 'India'])
print('India in bri =',('India' in bri))
print('USA in bri =', ('USA' in bri))

bric = bri.copy()
bric.add('China')
print('bric is superset of bri =', bric.issuperset(bri))

bri.remove('Russia')
print('bri & bric =',bri & bric)
print('bri.intersection(birc) =',bri.intersection(bric))
