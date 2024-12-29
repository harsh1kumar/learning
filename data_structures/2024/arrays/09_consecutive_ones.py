from typing import List

def consecutive_ones(arr: List[int]) -> int:

    max_one = 0
    x = 0
    for a in arr:
        if a == 1:
            x += 1
        else:
            max_one = max(x, max_one)
            x = 0
    
    return max(x, max_one)


print(consecutive_ones([1,1,0,1,1,1]))
print(consecutive_ones([1,1,0,1,1,1,1,0,0,0,1,1,1]))