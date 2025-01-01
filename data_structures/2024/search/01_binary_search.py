from typing import List

def binary_search_iterative(arr: List[int], x: int) -> int:

    index = 0

    while(len(arr)>0):
        i = int(len(arr)/2)
        if arr[i] == x:
            return index + i
        elif arr[i] > x:
            arr = arr[:i]
        else:
            arr = arr[i+1:]
            index = i+1

    return -1

def binary_search_iterative_alt(arr: List[int], x: int) -> int:
    low = 0
    high = len(arr)-1

    while (low <= high):
        mid = int((low + high)/2)
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            high = mid-1
        else:
            low = mid+1

    return -1

def binary_search_recursive(arr: List[int], x: int, low: int, high: int) -> int:
    if low>high:
        return -1

    mid = int((low + high)/2)
    if arr[mid] == x:
        return mid
    elif arr[mid] > x:
        return binary_search_recursive(arr, x, low, mid-1)
    else:
        return binary_search_recursive(arr, x, mid+1, high)

def main():
    print(f'[Expect, Got]:  2, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 6)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 5)}')
    print(f'[Expect, Got]:  6, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 16)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 20)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 15)}')
    print(f'[Expect, Got]:  5, {binary_search_iterative([3, 4, 6, 7, 9, 12, 16, 17], 12)}')

    print("")
    
    print(f'[Expect, Got]:  2, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 6,)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 5,)}')
    print(f'[Expect, Got]:  6, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 16,)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 20,)}')
    print(f'[Expect, Got]: -1, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 15,)}')
    print(f'[Expect, Got]:  5, {binary_search_iterative_alt([3, 4, 6, 7, 9, 12, 16, 17], 12,)}')
    
    print("")
    
    print(f'[Expect, Got]:  2, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 6, 0, 7)}')
    print(f'[Expect, Got]: -1, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 5, 0, 7)}')
    print(f'[Expect, Got]:  6, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 16, 0, 7)}')
    print(f'[Expect, Got]: -1, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 20, 0, 7)}')
    print(f'[Expect, Got]: -1, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 15, 0, 7)}')
    print(f'[Expect, Got]:  5, {binary_search_recursive([3, 4, 6, 7, 9, 12, 16, 17], 12, 0, 7)}')


if __name__=="__main__":
    main()