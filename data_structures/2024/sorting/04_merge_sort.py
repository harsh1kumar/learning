from typing import List

def merge(a: List[int], b: List[int]) -> List[int]:
    tot_len = len(a) + len(b)

    arr = []
    x = 0
    y = 0
    for i in range(tot_len):
        if a[x] < b[y]:
            arr.append(a[x])
            x += 1
        else:
            arr.append(b[y])
            y += 1
        
        if x >= len(a):
            arr = arr + b[y:]
            break
        
        if y >= len(b):
            arr = arr + a[x:]
            break

    return arr

def merge_sort(arr: List[int]) -> List[int]:
    mid = int(len(arr)/2)
    if mid == 0:
        return arr

    a = merge_sort(arr[0:mid])
    b = merge_sort(arr[mid:])

    return merge(a, b)


def main():
    arr = merge_sort([13,46,24,52,20,9])
    assert arr == [9,13,20,24,46,52], "Array isn't sorted"
    print(f"*** Sorted Array: {arr} ***\n")

    arr = merge_sort([5,4,3,2,1])
    assert arr == [1,2,3,4,5], "Array isn't sorted"
    print(f"*** Sorted Array: {arr} ***\n")

if __name__=="__main__":
    main()

