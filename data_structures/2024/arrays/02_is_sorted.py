from typing import List

def is_sorted(arr: List[int]) -> bool:
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True


def main():
    arr = [2,5,1,3,0]
    print(f'Is sorted {arr}: {is_sorted(arr)}')
    print("")
    arr = [0,1,2,3]
    print(f'Is sorted {arr}: {is_sorted(arr)}')
    
if __name__=="__main__":
    main()