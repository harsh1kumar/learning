import numpy as np

def factors(n):
    for i in range(1, n+1):
        if n%i==0:
            print(i, end=" ")
    print("")

def factors_optimal(n):
    for i in range(1, int(np.sqrt(n))+1):
        if n%i==0:
            if i == n/i:
                print(i, end=" ")
            else:
                print(i, int(n/i), end=" ")
    print("")


factors(100)
factors(36)
factors(12)

print("")

factors_optimal(100)
factors_optimal(36)
factors_optimal(12)

