from typing import List

def longest_array_sum_k(arr: List[int], k: int) -> List[int]:

    max_len = 0
    for i in range(len(arr)):
        s = 0
        for j in range(i, len(arr)):
            s += arr[j]
            if s > k:
                break
            elif s==k:
                if j-i+1 > max_len:
                    max_len = (j-i+1)
                break
    return max_len

print(longest_array_sum_k([2,3,5], 5))
print(longest_array_sum_k([2,3,5,1,9], 10))
print(longest_array_sum_k([2,3,5,1,9], 11))
print(longest_array_sum_k([2,3,5,1,9], 15))

