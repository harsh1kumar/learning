from typing import List

def find_single(arr: List[int]) -> int:
    d = {}
    for a in arr:
        d[a] = d.get(a, 0) + 1

    for key, val in d.items():
        if val==1:
            return key
    return None

def find_single_alt(arr: List[int]) -> int:
    xorr = 0
    for a in arr:
        xorr ^= a
    return xorr

print(find_single([2,2,1]))
print(find_single([4,1,2,1,2]))
print(find_single([4,1,2,1,2,4]))

print(find_single_alt([2,2,1]))
print(find_single_alt([4,1,2,1,2]))
print(find_single_alt([4,1,2,1,2,4]))
