from typing import List

def zeros_to_end(arr: List[int]) -> bool:
    zero_cnt = 0
    x = 0
    for i in range(len(arr)):
        if arr[i] == 0:
            zero_cnt += 1
        else:
            arr[x] = arr[i]
            x += 1

    for i in range(zero_cnt):
        arr[-1-i] = 0

    return arr

def main():
    arr = [1,5,0,10,0,30,100]
    print(f'{zeros_to_end(arr)}')

    arr = [0,0,0,1,2,0,3,0]
    print(f'{zeros_to_end(arr)}')
    
    arr = [10]
    print(f'{zeros_to_end(arr)}')

    
    arr = [10, 10, 10]
    print(f'{zeros_to_end(arr)}')
    
if __name__=="__main__":
    main()