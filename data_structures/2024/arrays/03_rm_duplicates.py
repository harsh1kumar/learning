from typing import List

def rm_duplicates(arr: List[int]) -> bool:
    x = 1
    for i in range(1, len(arr)):
        if arr[i] != arr[i-1]:
            arr[x] = arr[i]
            x += 1
    return x, arr


def main():
    arr = [1,5,10,30,100]
    print(f'{rm_duplicates(arr)}')

    arr = [0,1,2,3]
    print(f'{rm_duplicates(arr)}')
    
    arr = [10]
    print(f'{rm_duplicates(arr)}')

    
    arr = [10, 10, 10]
    print(f'{rm_duplicates(arr)}')

    
    arr = [1, 5, 5, 5, 10, 20]
    print(f'{rm_duplicates(arr)}')
    
if __name__=="__main__":
    main()