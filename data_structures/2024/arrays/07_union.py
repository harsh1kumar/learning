from typing import List

def union(a: List[int], b: List[int]) -> List[int]:
    x = 0
    y = 0
    arr = []

    while x < len(a) and y < len(b):
        if a[x] <= b[y]:
            if len(arr)==0 or arr[-1] != a[x]:
                arr.append(a[x])
            x += 1
        elif a[x] > b[y]:
            if len(arr)==0 or arr[-1] != b[y]:
                arr.append(b[y])
            y += 1

    while x < len(a):
        if arr[-1] != a[x]:
            arr.append(a[x])
        x += 1
    
    while y < len(b):
        if arr[-1] != b[y]:
            arr.append(b[y])
        y += 1


    return arr


def main():
    print(union([1,2,3,4,5], [2,3,4,5,6]))
    print(union([1,2,3,4,5], [2,3,4,4,5]))
    print(union([1,2,3,4,5,7], [2,3,4,4,5,6,6,6,7]))
    print(union([1,2,3,4,5], [2,3,4,4,5,6,6,6,7]))

if __name__=="__main__":
    main()