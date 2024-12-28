from typing import List

def bubble_sort(arr: List[int], n: int) -> List[int]:
    if n<=1:
        return arr

    for i in range(n-1):
        if arr[i] > arr[i+1]:
            tmp = arr[i+1]
            arr[i+1] = arr[i]
            arr[i] = tmp

    return bubble_sort(arr, n-1)


def main():
    arr = [13,46,24,52,20,9]
    sorted_arr = bubble_sort(arr, len(arr))
    assert arr == [9,13,20,24,46,52], "Array isn't sorted"
    print(f"*** Sorted Array: {sorted_arr} ***\n")

    arr = [5,4,3,2,1]
    sorted_arr = bubble_sort(arr, len(arr))
    assert arr == [1,2,3,4,5], "Array isn't sorted"
    print(f"*** Sorted Array: {sorted_arr} ***\n")

if __name__=="__main__":
    main()
