from typing import List

def left_rotate(arr: List[int]) -> bool:
    x = arr[0]
    arr = arr[1:]
    arr.append(x)
    return arr

def left_rotate_alterative(arr: List[int]) -> bool:
    x = arr[0]
    for i in range(1, len(arr)):
        arr[i-1] = arr[i]
    arr[len(arr)-1] = x
    return arr


def main():
    arr = [1,5,10,30,100]
    print(f'{left_rotate(arr)}')
    print(f'{left_rotate_alterative(arr)}')

    arr = [0,1,2,3]
    print(f'{left_rotate(arr)}')
    print(f'{left_rotate_alterative(arr)}')
    
    arr = [10]
    print(f'{left_rotate(arr)}')
    print(f'{left_rotate_alterative(arr)}')

    
    arr = [10, 10, 10]
    print(f'{left_rotate(arr)}')
    print(f'{left_rotate_alterative(arr)}')

    
    arr = [1, 5, 5, 5, 10, 20]
    print(f'{left_rotate(arr)}')
    print(f'{left_rotate_alterative(arr)}')
    
if __name__=="__main__":
    main()