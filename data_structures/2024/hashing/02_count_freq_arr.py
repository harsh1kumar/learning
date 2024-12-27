from typing import List

def count_arr_freq(arr: List[int]) -> None:
    d = {}
    for a in arr:
        if a not in d:
            d[a] = 0
        d[a] += 1
    
    for key in d:
        print(f"{key} occurs {d[key]} times")


def main():
    count_arr_freq([10,5,10,15,10,5])
    print("")
    count_arr_freq([2,2,3,4,4,2])

if __name__=="__main__":
    main()
    