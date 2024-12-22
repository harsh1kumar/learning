from typing import List

def factors(n: int) -> List[int]:
    f = []
    for i in range(1, n+1):
        if n%i==0:
            f.append(i)
    return f

def find_gcd(x, y):
    gcd = 1
    for i in range(min(x, y), 0, -1):
        if x%i==0 and y%i==0:
            gcd = i
            break
    
    print(f'gcd of {x}, {y}: {gcd}')
    return gcd


def main():
    find_gcd(9, 12)
    find_gcd(20, 15)
    find_gcd(13, 1)
    find_gcd(13, 15)

if __name__=="__main__":
    main()