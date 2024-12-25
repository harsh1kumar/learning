import numpy as np

def is_armstrong(n):
    n_bck = n
    digits = []
    while n>0:
        digits.append(n%10)
        n //= 10
    
    cnt = len(digits)
    return np.sum([x**cnt for x in digits]) == n_bck

def is_armstrong_optimal(n):
    n_bck = n
    num_digit = int(np.log10(n))+1
    x = 0
    while n>0:
        x += (n%10)**num_digit
        n //= 10
    
    return x == n_bck


def main():
    print(f'is 153 armstrong: {is_armstrong(153)}')
    print(f'is 371 armstrong: {is_armstrong(371)}')
    print(f'is 111 armstrong: {is_armstrong(111)}')
    print(f'is 222 armstrong: {is_armstrong(222)}')

    print("")

    print(f'is 153 armstrong: {is_armstrong_optimal(153)}')
    print(f'is 371 armstrong: {is_armstrong_optimal(371)}')
    print(f'is 111 armstrong: {is_armstrong_optimal(111)}')
    print(f'is 222 armstrong: {is_armstrong_optimal(222)}')

if __name__=="__main__":
    main()