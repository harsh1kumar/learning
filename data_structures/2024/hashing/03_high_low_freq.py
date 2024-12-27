from typing import List
import numpy as np

def highest_lowest_freq(arr: List[int]) -> None:
    d = {}

    highest_freq_key = None
    lowest_freq_key = None

    highest_freq = 0
    lowest_freq = np.inf

    for a in arr:
        if a not in d:
            d[a] = 0
        d[a] += 1
        
    
    for key, val in d.items():
        if val > highest_freq:
            highest_freq = val
            highest_freq_key = key
        if val < lowest_freq:
            lowest_freq = val
            lowest_freq_key = key
    
    print(f"Highest frequecy is {highest_freq_key} which occurs {highest_freq}")
    print(f"Lowest frequecy is {lowest_freq_key} which occurs {lowest_freq}")


def main():
    highest_lowest_freq([10,5,10,15,10,5])
    print("")
    highest_lowest_freq([2,2,3,4,4,2])

if __name__=="__main__":
    main()