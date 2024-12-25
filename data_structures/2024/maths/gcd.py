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

def find_gcd_optimal(x, y):
    if x==0:
        return y
    elif y==0:
        return x
    elif x>y:
        return find_gcd_optimal(x-y, y)
    else:
        return find_gcd_optimal(x, y-x)

def main():
    find_gcd(9, 12)
    find_gcd(20, 15)
    find_gcd(13, 1)
    find_gcd(13, 15)

    print("")
    print(f'gcd{9, 12}: {find_gcd_optimal(9,12)}')
    print(f'gcd{20, 15}: {find_gcd_optimal(20,15)}')
    print(f'gcd{13, 1}: {find_gcd_optimal(13,1)}')
    print(f'gcd{13, 15}: {find_gcd_optimal(13,15)}')

if __name__=="__main__":
    main()