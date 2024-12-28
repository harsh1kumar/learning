from typing import List

def insertion_sort(arr: List[int]) -> List[int]:
    print(0, 0, arr)
    for i in range(len(arr)):
        for j in range(i, 0, -1):
            if arr[j]<arr[j-1]:
                tmp = arr[j-1]
                arr[j-1] = arr[j]
                arr[j] = tmp
            else:
                break
            print(i, j, arr)

    return arr


def main():
    arr = insertion_sort([13,46,24,52,20,9])
    assert arr == [9,13,20,24,46,52], "Array isn't sorted"
    print(f"\n*** Sorted Array: {arr} ***\n")

    arr = insertion_sort([5,4,3,2,1])
    assert arr == [1,2,3,4,5], "Array isn't sorted"
    print(f"\n*** Sorted Array: {arr} ***\n")

if __name__=="__main__":
    main()

