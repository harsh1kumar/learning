import numpy as np

def is_prime(n):
    factors = []
    for i in range(1, int(np.sqrt(n))+1):
        if n%i == 0:
            factors.append(i)
            factors.append(n/i)
    
    return len(factors)==2


print(f'Is 1 prime: {is_prime(1)}')
print(f'Is 2 prime: {is_prime(2)}')
print(f'Is 3 prime: {is_prime(3)}')
print(f'Is 4 prime: {is_prime(4)}')
print(f'Is 5 prime: {is_prime(5)}')
print(f'Is 6 prime: {is_prime(6)}')
print(f'Is 7 prime: {is_prime(7)}')
print(f'Is 23 prime: {is_prime(23)}')
print(f'Is 25 prime: {is_prime(25)}')
print(f'Is 100 prime: {is_prime(100)}')
