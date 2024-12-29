from typing import List

def missing_number(arr: List[int], n: int) -> int:
    return int(n * (n+1)/2 - sum(arr))

def main():
    print(missing_number([1,2,4,5], 5))
    print(missing_number([6,2,4,5,7,1], 7))

if __name__=="__main__":
    main()