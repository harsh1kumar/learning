from typing import List, Tuple
import numpy as np

def largest_element(arr: List[int]) -> int:
    l = -np.inf
    for a in arr:
        if a > l:
            l=a
    return l

def second_largest_smallest(arr: List[int]) -> Tuple[int, int]:
    l1 = -np.inf
    l2 = -np.inf
    s1 = np.inf
    s2 = np.inf

    for a in arr:
        if a > l1:
            l2 = l1
            l1 = a
        elif a > l2 and a < l1:
            l2 = a
        
        if a < s1:
            s2 = s1
            s1 = a
        elif a < s2 and a > s1:
            s2 = a
    
    return (l2, s2)


def main():
    arr = [2,5,1,3,0]
    second_largest_smallest(arr)
    assert largest_element(arr) == max(arr), f"Wrong value from largest_element() for {arr}"
    print(f'Largest Element in {arr}: {largest_element(arr)}')
    print(f'2nd Largest and 2nd Smallest Element in {arr}: {second_largest_smallest(arr)}')

    print("")
    
    arr = [8,10,5,7,9]
    assert largest_element(arr) == max(arr), f"Wrong value from largest_element() for {arr}"
    print(f'Largest Element in {arr}: {largest_element(arr)}')
    print(f'2nd Largest and 2nd Smallest Element in {arr}: {second_largest_smallest(arr)}')

    print("")

    arr = [1,2,4,7,7,5]
    second_largest_smallest(arr)
    assert largest_element(arr) == max(arr), f"Wrong value from largest_element() for {arr}"
    print(f'Largest Element in {arr}: {largest_element(arr)}')
    print(f'2nd Largest and 2nd Smallest Element in {arr}: {second_largest_smallest(arr)}')
    
    print("")

    arr = [1]
    second_largest_smallest(arr)
    assert largest_element(arr) == max(arr), f"Wrong value from largest_element() for {arr}"
    print(f'Largest Element in {arr}: {largest_element(arr)}')
    print(f'2nd Largest and 2nd Smallest Element in {arr}: {second_largest_smallest(arr)}')

if __name__=="__main__":
    main()