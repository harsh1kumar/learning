from typing import List

def search_in_list(arr: List[int], n: int) -> int:
    for i in range(len(arr)):
        if n == arr[i]:
            return i
    return -1

def search(arr: List[int], n: int):
    mid = int(len(arr)/2)
    
    if mid == 0:
        return n == arr[0]
    
    return search(arr[0:mid], n) or search(arr[mid:], n)

def main():
    print(search_in_list([1,2,3,4,5], 3))
    print(search_in_list([5,4,3,2,1], 5))
    print(search_in_list([5,4,3,2,1], 10))

    print(search([1,2,3,4,5], 3))
    print(search([5,4,3,2,1], 5))
    print(search([5,4,3,2,1], 10))


if __name__=="__main__":
    main()