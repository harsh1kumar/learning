from typing import List

def selection_sort(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        min_val = arr[i]
        min_index = i
        print(f"Outer Loop {i}")
        for j in range(i+1, len(arr)):
            if arr[j] < min_val:
                min_index = j
                min_val = arr[j]
            print(f"\tInner Loop {j}: Min_Index: {min_index}, Min_Val: {min_val}")

        arr[min_index] = arr[i]
        arr[i] = min_val
        print(f"\t\tSwap {i}th with {min_index}th position, arr = {arr}")

    return arr


def main():
    arr = selection_sort([13,46,24,52,20,9])
    print(f"\n*** Sorted Array: {arr} ***\n")

    arr = selection_sort([5,4,3,2,1])
    print(f"\n*** Sorted Array: {arr} ***\n")

if __name__=="__main__":
    main()

